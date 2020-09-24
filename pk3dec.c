#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "vu1_decode.h"

///////////////////////////////////////////////////////////////////////////////

/* CRC-16/GENIBUS implementation */
/* https://reveng.sourceforge.io/crc-catalogue/16.htm#crc.cat.crc-16-genibus */

#define CRC16_INIT     0xFFFF
#define CRC16_POLY     0x1021
#define CRC16_XOR_OUT  0xFFFF

uint16_t crc16(uint8_t *data, int length)
{
  uint16_t i, crc = CRC16_INIT;

  while (length--) {
    for (crc ^= *data++ << 8, i = 0; i < 8; i++) {
      crc = (crc & 0x8000) ? crc << 1 ^ CRC16_POLY : crc << 1;
    }
  }

  return crc ^ CRC16_XOR_OUT;
}

///////////////////////////////////////////////////////////////////////////////

uint32_t get_u32_be(uint8_t *mem)
{
  return (mem[0] << 24) | (mem[1] << 16) | (mem[2] << 8) | mem[3];
}

uint32_t get_u32_le(uint8_t *mem)
{
  return (mem[3] << 24) | (mem[2] << 16) | (mem[1] << 8) | mem[0];
}

uint16_t get_u16_le(uint8_t *mem)
{
  return (mem[1] << 8) | mem[0];
}

void put_u32_le(uint8_t *buf, uint32_t n)
{
    buf[0] = (uint8_t)(n & 0xFF);
    buf[1] = (uint8_t)((n >> 8) & 0xFF);
    buf[2] = (uint8_t)((n >> 16) & 0xFF);
    buf[3] = (uint8_t)((n >> 24) & 0xFF);
}

void put_u16_le(uint8_t *buf, uint32_t n)
{
    buf[0] = (uint8_t)(n & 0xFF);
    buf[1] = (uint8_t)((n >> 8) & 0xFF);
}

///////////////////////////////////////////////////////////////////////////////

int16_t huff_table_1[257];       /* 0x90(...)     size=0x0202 (514)    */

int16_t huff_table_2[2][32];     /* 0x10(...)     size=0x0080 (128)    */

int16_t huff_table_3[258];       /* 0x292(...)    size=0x0204 (516)    */

uint8_t huff_table_4[16383];     /* 0x496(...)    size=0x3FFF (16383)  */

/* AKA RangeDecodeInit (Csd) */
int huff_init_tables(uint8_t *buf)
{
  uint8_t idx = 0;
  int offset = 0;

  /* initialize huff_table_1 with values from PK3 file */

  for (int i = 0; i < 256; i++) {
    int16_t n = buf[offset++];

    if (n & 0x80) {
      n &= 0x7F;
      n |= buf[offset++] << 7;
    }

    huff_table_1[i] = n;
  }

  /* zero-initialize huff_table_2 */

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 32; j++) {
      huff_table_2[i][j] = 0;
    }
  }

  /* initialize huff_table_3 */

  huff_table_1[256] = 1;
  huff_table_3[0] = 0;

  for (int i=1, j=0; i < 258; i++, j++) {
    huff_table_3[i] = huff_table_3[j] + huff_table_1[j];
  }

  /* initialize huff_table_4 */

  for (idx=0; !huff_table_1[idx]; idx++) ;

  for (int i = 0; i < 16383; i++) {
    if (i >= huff_table_3[idx+1]) {
      while (!huff_table_1[++idx]) ;
    }
    huff_table_4[i] = idx;
  }

  return offset;
}

int16_t huff_out[2][1024] = { 0 };

/* the VU1 routines always output 1024 samples */

#define NUM_SAMPLES_OUT 1024

int16_t pcm16[NUM_SAMPLES_OUT][2] = { 0 };

void decode_frame(FILE *wavfile, uint8_t *ptr, uint16_t flag, uint32_t xor_value)
{
  uint32_t unkA = 0;
  uint32_t unkB = xor_value;
  uint32_t unkC = 0;
  uint32_t unkD = 0xFFFFFFFF;
  uint32_t unkT = 0; // temp

  for (int ch = 0; ch < 2; ch++) {
    int huff_done = 0;
    int huff_todo = 28;
    int16_t huff_val = 0;
    int32_t *s32 = NULL;
    for (; huff_done < huff_todo; huff_done++) {
      unkD = unkD >> 14;
      unkA = huff_table_4[(unkB - unkC) / unkD];
      unkC += huff_table_3[unkA] * unkD;
      unkD *= huff_table_1[unkA];

      while (0xFFFFFF >= (unkC ^ (unkC + unkD))) {
        unkB = (unkB << 8) | (*ptr++);
        unkD = (unkD << 8);
        unkC = (unkC << 8);
      }

      while (0xFFFF >= unkD) {
        unkD = (((~unkC) + 1) & 0xFFFF) << 8;
        unkB = (unkB << 8) | (*ptr++);
        unkC = (unkC << 8);
      }

      if (unkA >= 0xFE) {
        unkT = unkA == 0xFE;
        unkD = unkD >> (unkT ? 8 : 13);
        unkA = (unkB - unkC) / unkD;
        unkC = unkC + (unkA * unkD);
        if (unkT) unkA += 0xFE;

        while (0xFFFFFF >= (unkC ^ (unkC + unkD))) {
          unkB = (unkB << 8) | (*ptr++);
          unkD = (unkD << 8);
          unkC = (unkC << 8);
        }

        while (0xFFFF >= unkD) {
          unkD = (((~unkC) + 1) & 0xFFFF) << 8;
          unkB = (unkB << 8) | (*ptr++);
          unkC = (unkC << 8);
        }
      }

      if (unkA & 1) {
        huff_val = -((((int16_t)unkA) + 1) / 2);
      } else {
        huff_val = unkA / 2;
      }

      if (huff_done < 28) {
        if (flag) {
          huff_val += huff_table_2[ch][huff_done];
        }

        huff_table_2[ch][huff_done] = huff_val;

        if (huff_done != 0 && (huff_val << 16) != 0) {
          huff_todo += 32;
        }
      }

      huff_out[ch][huff_done] = huff_val;
    }

    s32 = vu1_decode(huff_out[ch], huff_done, ch);
    for (int i = 0; i < NUM_SAMPLES_OUT; i++) {
      pcm16[i][ch] = *(int16_t*)(&s32[i]);
    }
  }

  if (sizeof(pcm16) != fwrite(pcm16, 1, sizeof(pcm16), wavfile)) {
    printf("fwrite failed!\n");
    exit(EXIT_FAILURE);
  }
}

int decode_file(FILE *wavfile, uint8_t *buf, long bufsize)
{
  /* parse file header */

  long offset = get_u32_le(buf+0x00);
  uint16_t frame_count = get_u16_le(buf+0x0C);

  /* parse initialization table */

  offset += huff_init_tables(buf+offset);

  /* parse frames */

  for (uint16_t i = 1; i <= frame_count; i++) {
    if (offset+4 <= bufsize && get_u32_le(buf+offset) == 0xFFFFFFFF) {
      printf("pad frame at 0x%08X\n", offset);
      offset += 0x4E000 - (offset % 0x4E000);
      --i; /* preserve expected frame id */
    } else if (offset+12 <= bufsize) {
      uint16_t crc_read   = get_u16_le(buf+offset+0x00);
      uint16_t flag       = get_u16_le(buf+offset+0x02) >> 15; /* 0 every 64th frame, 1 for others */
      uint16_t size       = get_u16_le(buf+offset+0x02) & 0x7FFF;
      uint16_t frame_id   = get_u16_le(buf+offset+0x04);
      uint16_t huff_count = get_u16_le(buf+offset+0x06); /* huffman decoded length in 16-bit units */
      uint32_t xor_value  = get_u32_be(buf+offset+0x08);

      printf(
        "i=0x%04X  flag=%d  offset=0x%08X  size=0x%04X  frame_id=0x%04X  huff_count=0x%04X  xor_value=0x%08X\n",
        i, flag, offset, size, frame_id, huff_count, xor_value
      );

      if (frame_id != i) {
        printf("frame id mismatch (read=%04X, iter=%04X)\n", frame_id, i);
        exit(EXIT_FAILURE);
      }

      /* checksum is of data starting at 0x04 */
      /* size is of data starting at 0x08 */

      if (offset+0x08+size <= bufsize) {
        uint16_t crc_calc = crc16(buf+offset+0x04, 4+size);

        if (crc_read != crc_calc) {
          printf("checksum mismatch (read=%04X, calc=%04X)\n", crc_read, crc_calc);
          exit(EXIT_FAILURE);
        }

        decode_frame(wavfile, buf+offset+0x0C, flag, xor_value);

        offset += 0x08+size;
      } else {
        printf("indicated frame size too big?");
        exit(EXIT_FAILURE);
      }
    } else {
      printf("unexpected data at 0x%X", offset);
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  FILE *f = NULL;

  long size = 0;

  uint8_t *data = NULL;

  char wav_path[1024] = { 0 };

  FILE *wavfile = NULL;

  uint8_t wavehdr[0x2C] = { 0 };

  if (argc != 2) {
    printf("Usage: %s <pk3>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  f = fopen(argv[1], "rb");
  if (!f) {
    printf("ERROR: Could not open file\n");
    exit(EXIT_FAILURE);
  }

  fseek(f, 0, SEEK_END);
  size = ftell(f);
  fseek(f, 0, SEEK_SET);

  data = malloc(size);
  if (!data) {
    printf("ERROR: Could not allocate PK3 buffer\n");
    exit(EXIT_FAILURE);
  }

  if (size != fread(data, 1, size, f)) {
    printf("ERROR: Could not read PK3 data\n");
    exit(EXIT_FAILURE);
  }

  fclose(f);

  sprintf(wav_path, "%s.wav", argv[1]);
  wavfile = fopen(wav_path, "wb");
  if (!wavfile) {
    printf("ERROR: Could not open WAV file for writing: %s\n", wav_path);
    exit(EXIT_FAILURE);
  }

  fseek(wavfile, sizeof(wavehdr), SEEK_SET);

  decode_file(wavfile, data, size);

#define WAVE_FMT_SIZE 0x10
#define WAVE_CODEC 1
#define WAVE_NUM_CHANNELS 2
#define WAVE_SAMPLE_RATE 48000
#define WAVE_NUM_BITS_PER_SAMPLE 16
#define WAVE_BITS_PER_BLOCK (WAVE_NUM_CHANNELS * WAVE_NUM_BITS_PER_SAMPLE)
#define WAVE_BYTES_PER_BLOCK (WAVE_BITS_PER_BLOCK / 8)
#define WAVE_BYTES_PER_SECOND (WAVE_SAMPLE_RATE * WAVE_BYTES_PER_BLOCK)

  memcpy(&wavehdr[0x00], "RIFF", 4);
  put_u32_le(&wavehdr[0x04], ftell(wavfile)-8);
  memcpy(&wavehdr[0x08], "WAVE", 4);
  memcpy(&wavehdr[0x0C], "fmt ", 4);
  put_u32_le(&wavehdr[0x10], WAVE_FMT_SIZE);
  put_u16_le(&wavehdr[0x14], WAVE_CODEC);
  put_u16_le(&wavehdr[0x16], WAVE_NUM_CHANNELS);
  put_u32_le(&wavehdr[0x18], WAVE_SAMPLE_RATE);
  put_u32_le(&wavehdr[0x1C], WAVE_BYTES_PER_SECOND);
  put_u16_le(&wavehdr[0x20], WAVE_BYTES_PER_BLOCK);
  put_u16_le(&wavehdr[0x22], WAVE_NUM_BITS_PER_SAMPLE);
  memcpy(&wavehdr[0x24], "data", 4);
  put_u32_le(&wavehdr[0x28], ftell(wavfile)-sizeof(wavehdr));

  fseek(wavfile, 0, SEEK_SET);

  if (sizeof(wavehdr) != fwrite(wavehdr, 1, sizeof(wavehdr), wavfile)) {
    printf("could not write WAVE header\n");
    exit(EXIT_FAILURE);
  }

  fclose(wavfile);

  free(data);

  return 0;
}
