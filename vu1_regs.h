typedef struct {
  union {
    float    F;
    int32_t  SL;
    uint32_t UL;
    int16_t  SS[2];
    uint16_t US[2];
    int8_t   SC[4];
    uint8_t  UC[4];
  };
  uint32_t padding[3]; // needs padding to make them 128bit; VU0 maps VU1's VI regs as 128bits to addr 0x4xx0 in
                       // VU0 mem, with only lower 16 bits valid, and the upper 112bits are hardwired to 0
} REG_VI;

typedef union {
  struct {
    float x,y,z,w;
  } f;

  struct {
    uint32_t x,y,z,w;
  } i;

  float     F[4];      // float

  uint64_t UD[2];      // unsigned double
  int64_t  SD[2];      // signed double
  uint32_t UL[4];      // unsigned long
  int32_t  SL[4];      // signed long
  uint16_t US[8];      // unsigned short
  int16_t  SS[8];      // signed short
  uint8_t  UC[16];     // unsigned char
  int8_t   SC[16];     // signed char
} VECTOR;

typedef VECTOR REG_VF;

#define _xyzw 0xF
#define _xyz  0xE
#define _xyw  0xD
#define _xy   0xC
#define _xzw  0xB
#define _xz   0xA
#define _xw   0x9
#define _x    0x8
#define _yzw  0x7
#define _yz   0x6
#define _yw   0x5
#define _y    0x4
#define _zw   0x3
#define _z    0x2
#define _w    0x1

#define Fx 0
#define Fy 1
#define Fz 2
#define Fw 3

static REG_VF VF00 = { .f = { 0,0,0,1 } }; // w = 1.0
static REG_VF VF01 = { .f = { 0,0,0,0 } };
static REG_VF VF02 = { .f = { 0,0,0,0 } };
static REG_VF VF03 = { .f = { 0,0,0,0 } };
static REG_VF VF04 = { .f = { 0,0,0,0 } };
static REG_VF VF05 = { .f = { 0,0,0,0 } };
static REG_VF VF06 = { .f = { 0,0,0,0 } };
static REG_VF VF07 = { .f = { 0,0,0,0 } };
static REG_VF VF08 = { .f = { 0,0,0,0 } };
static REG_VF VF09 = { .f = { 0,0,0,0 } };
static REG_VF VF10 = { .f = { 0,0,0,0 } };
static REG_VF VF11 = { .f = { 0,0,0,0 } };
static REG_VF VF12 = { .f = { 0,0,0,0 } };
static REG_VF VF13 = { .f = { 0,0,0,0 } };
static REG_VF VF14 = { .f = { 0,0,0,0 } };
static REG_VF VF15 = { .f = { 0,0,0,0 } };
static REG_VF VF16 = { .f = { 0,0,0,0 } };
static REG_VF VF17 = { .f = { 0,0,0,0 } };
static REG_VF VF18 = { .f = { 0,0,0,0 } };
static REG_VF VF19 = { .f = { 0,0,0,0 } };
static REG_VF VF20 = { .f = { 0,0,0,0 } };
static REG_VF VF21 = { .f = { 0,0,0,0 } };
static REG_VF VF22 = { .f = { 0,0,0,0 } };
static REG_VF VF23 = { .f = { 0,0,0,0 } };
static REG_VF VF24 = { .f = { 0,0,0,0 } };
static REG_VF VF25 = { .f = { 0,0,0,0 } };
static REG_VF VF26 = { .f = { 0,0,0,0 } };
static REG_VF VF27 = { .f = { 0,0,0,0 } };
static REG_VF VF28 = { .f = { 0,0,0,0 } };
static REG_VF VF29 = { .f = { 0,0,0,0 } };
static REG_VF VF30 = { .f = { 0,0,0,0 } };
static REG_VF VF31 = { .f = { 0,0,0,0 } };

static REG_VI VI00 = { .UL = 0 };
static REG_VI VI01 = { .UL = 0 };
static REG_VI VI02 = { .UL = 0 };
static REG_VI VI03 = { .UL = 0 };
static REG_VI VI04 = { .UL = 0 };
static REG_VI VI05 = { .UL = 0 };
static REG_VI VI06 = { .UL = 0 };
static REG_VI VI07 = { .UL = 0 };
static REG_VI VI08 = { .UL = 0 };
static REG_VI VI09 = { .UL = 0 };
static REG_VI VI10 = { .UL = 0 };
static REG_VI VI11 = { .UL = 0 };
static REG_VI VI12 = { .UL = 0 };
static REG_VI VI13 = { .UL = 0 };
static REG_VI VI14 = { .UL = 0 };
static REG_VI VI15 = { .UL = 0 };

static REG_VI STATUS = { .UL = 0 };
static REG_VI MAC    = { .UL = 0 };
static REG_VI I      = { .F = 0.0 };
static REG_VI Q      = { .F = 0.0 };
static REG_VF ACC    = { .f = { 0,0,0,0 } };
