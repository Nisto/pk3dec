#include <math.h>

static inline void UPDATE_FLAGS(uint8_t dest, REG_VF *vf)
{
  int status = 0;

  for (int i = 0; i < 4; i++) {
    int shift = 3 - i;
    if (dest & (1 << shift)) {
      uint32_t v = *(uint32_t*)(&vf->F[i]);
      int exp = (v >> 23) & 0xff;
      uint32_t s = v & 0x80000000;

      if (s)
        MAC.UL |= 0x0010<<shift;
      else
        MAC.UL &= ~(0x0010<<shift);

      if (vf->F[i] == 0) {
        MAC.UL = (MAC.UL & ~(0x1100<<shift)) | (0x0001<<shift);
        vf->UL[i] = v;
      } else {
        switch (exp) {
          case 0:
            MAC.UL = (MAC.UL & ~(0x1000<<shift)) | (0x0101<<shift);
            vf->UL[i] = s;
            break;
          case 255:
            MAC.UL = (MAC.UL & ~(0x0100<<shift)) | (0x1000<<shift);
            vf->UL[i] = s|0x7f7fffff; /* max allowed */
            break;
          default:
            MAC.UL = (MAC.UL & ~(0x1101<<shift));
            vf->UL[i] = v;
            break;
        }
      }
    } else {
      MAC.UL &= ~(0x1111<<shift);
    }
  }

  if (MAC.UL & 0x000F) status |= 0x1;
  if (MAC.UL & 0x00F0) status |= 0x2;
  if (MAC.UL & 0x0F00) status |= 0x4;
  if (MAC.UL & 0xF000) status |= 0x8;

  STATUS.UL = (STATUS.UL & 0xC30) | status | ((STATUS.UL & 0xF) << 6);
}

///////////////////////////////////////////////////////////////////////////////

static inline void DIV(REG_VF *fs, uint8_t fsf, REG_VF *ft, uint8_t ftf)
{
  float dividend = fs->F[fsf];
  float divisor = ft->F[ftf];

  if (divisor == 0.0) {
    if (dividend == 0.0) {
      STATUS.UL |= 0x10;
    } else {
      STATUS.UL |= 0x20;
    }
    if ((ft->UL[ftf] & 0x80000000) != (0x80000000 & fs->UL[fsf])) {
      Q.UL = 0xFF7FFFFF;
    } else {
      Q.UL = 0x7F7FFFFF;
    }
  } else {
    Q.F = dividend / divisor;
  }
}

///////////////////////////////////////////////////////////////////////////////

static inline void ADDi(uint8_t dest, REG_VF *fd, REG_VF *fs)
{
  if (dest & _x) fd->f.x = fs->f.x + I.F;
  if (dest & _y) fd->f.y = fs->f.y + I.F;
  if (dest & _z) fd->f.z = fs->f.z + I.F;
  if (dest & _w) fd->f.w = fs->f.w + I.F;
  UPDATE_FLAGS(dest, fd);
}

static inline void ADDq(uint8_t dest, REG_VF *fd, REG_VF *fs)
{
  if (dest & _x) fd->f.x = fs->f.x + Q.F;
  if (dest & _y) fd->f.y = fs->f.y + Q.F;
  if (dest & _z) fd->f.z = fs->f.z + Q.F;
  if (dest & _w) fd->f.w = fs->f.w + Q.F;
  UPDATE_FLAGS(dest, fd);
}

///////////////////////////////////////////////////////////////////////////////

static inline void ADD(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x + ft->f.x;
  if (dest & _y) fd->f.y = fs->f.y + ft->f.y;
  if (dest & _z) fd->f.z = fs->f.z + ft->f.z;
  if (dest & _w) fd->f.w = fs->f.w + ft->f.w;
  UPDATE_FLAGS(dest, fd);
}

static inline void ADDx(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x + ft->f.x;
  if (dest & _y) fd->f.y = fs->f.y + ft->f.x;
  if (dest & _z) fd->f.z = fs->f.z + ft->f.x;
  if (dest & _w) fd->f.w = fs->f.w + ft->f.x;
  UPDATE_FLAGS(dest, fd);
}

static inline void ADDy(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x + ft->f.y;
  if (dest & _y) fd->f.y = fs->f.y + ft->f.y;
  if (dest & _z) fd->f.z = fs->f.z + ft->f.y;
  if (dest & _w) fd->f.w = fs->f.w + ft->f.y;
  UPDATE_FLAGS(dest, fd);
}

static inline void ADDz(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x + ft->f.z;
  if (dest & _y) fd->f.y = fs->f.y + ft->f.z;
  if (dest & _z) fd->f.z = fs->f.z + ft->f.z;
  if (dest & _w) fd->f.w = fs->f.w + ft->f.z;
  UPDATE_FLAGS(dest, fd);
}

static inline void ADDw(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x + ft->f.w;
  if (dest & _y) fd->f.y = fs->f.y + ft->f.w;
  if (dest & _z) fd->f.z = fs->f.z + ft->f.w;
  if (dest & _w) fd->f.w = fs->f.w + ft->f.w;
  UPDATE_FLAGS(dest, fd);
}

///////////////////////////////////////////////////////////////////////////////

static inline void SUB(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x - ft->f.x;
  if (dest & _y) fd->f.y = fs->f.y - ft->f.y;
  if (dest & _z) fd->f.z = fs->f.z - ft->f.z;
  if (dest & _w) fd->f.w = fs->f.w - ft->f.w;
  UPDATE_FLAGS(dest, fd);
}

static inline void SUBx(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x - ft->f.x;
  if (dest & _y) fd->f.y = fs->f.y - ft->f.x;
  if (dest & _z) fd->f.z = fs->f.z - ft->f.x;
  if (dest & _w) fd->f.w = fs->f.w - ft->f.x;
  UPDATE_FLAGS(dest, fd);
}

static inline void SUBy(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x - ft->f.y;
  if (dest & _y) fd->f.y = fs->f.y - ft->f.y;
  if (dest & _z) fd->f.z = fs->f.z - ft->f.y;
  if (dest & _w) fd->f.w = fs->f.w - ft->f.y;
  UPDATE_FLAGS(dest, fd);
}

static inline void SUBz(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x - ft->f.z;
  if (dest & _y) fd->f.y = fs->f.y - ft->f.z;
  if (dest & _z) fd->f.z = fs->f.z - ft->f.z;
  if (dest & _w) fd->f.w = fs->f.w - ft->f.z;
  UPDATE_FLAGS(dest, fd);
}

static inline void SUBw(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x - ft->f.w;
  if (dest & _y) fd->f.y = fs->f.y - ft->f.w;
  if (dest & _z) fd->f.z = fs->f.z - ft->f.w;
  if (dest & _w) fd->f.w = fs->f.w - ft->f.w;
  UPDATE_FLAGS(dest, fd);
}

///////////////////////////////////////////////////////////////////////////////

static inline void MUL(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x * ft->f.x;
  if (dest & _y) fd->f.y = fs->f.y * ft->f.y;
  if (dest & _z) fd->f.z = fs->f.z * ft->f.z;
  if (dest & _w) fd->f.w = fs->f.w * ft->f.w;
  UPDATE_FLAGS(dest, fd);
}

static inline void MULx(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x * ft->f.x;
  if (dest & _y) fd->f.y = fs->f.y * ft->f.x;
  if (dest & _z) fd->f.z = fs->f.z * ft->f.x;
  if (dest & _w) fd->f.w = fs->f.w * ft->f.x;
  UPDATE_FLAGS(dest, fd);
}

static inline void MULy(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x * ft->f.y;
  if (dest & _y) fd->f.y = fs->f.y * ft->f.y;
  if (dest & _z) fd->f.z = fs->f.z * ft->f.y;
  if (dest & _w) fd->f.w = fs->f.w * ft->f.y;
  UPDATE_FLAGS(dest, fd);
}

static inline void MULz(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x * ft->f.z;
  if (dest & _y) fd->f.y = fs->f.y * ft->f.z;
  if (dest & _z) fd->f.z = fs->f.z * ft->f.z;
  if (dest & _w) fd->f.w = fs->f.w * ft->f.z;
  UPDATE_FLAGS(dest, fd);
}

static inline void MULw(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = fs->f.x * ft->f.w;
  if (dest & _y) fd->f.y = fs->f.y * ft->f.w;
  if (dest & _z) fd->f.z = fs->f.z * ft->f.w;
  if (dest & _w) fd->f.w = fs->f.w * ft->f.w;
  UPDATE_FLAGS(dest, fd);
}

///////////////////////////////////////////////////////////////////////////////

static inline void MADD(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x + (fs->f.x * ft->f.x);
  if (dest & _y) fd->f.y = ACC.f.y + (fs->f.y * ft->f.y);
  if (dest & _z) fd->f.z = ACC.f.z + (fs->f.z * ft->f.z);
  if (dest & _w) fd->f.w = ACC.f.w + (fs->f.w * ft->f.w);
  UPDATE_FLAGS(dest, fd);
}

static inline void MADDx(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x + (fs->f.x * ft->f.x);
  if (dest & _y) fd->f.y = ACC.f.y + (fs->f.y * ft->f.x);
  if (dest & _z) fd->f.z = ACC.f.z + (fs->f.z * ft->f.x);
  if (dest & _w) fd->f.w = ACC.f.w + (fs->f.w * ft->f.x);
  UPDATE_FLAGS(dest, fd);
}

static inline void MADDy(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x + (fs->f.x * ft->f.y);
  if (dest & _y) fd->f.y = ACC.f.y + (fs->f.y * ft->f.y);
  if (dest & _z) fd->f.z = ACC.f.z + (fs->f.z * ft->f.y);
  if (dest & _w) fd->f.w = ACC.f.w + (fs->f.w * ft->f.y);
  UPDATE_FLAGS(dest, fd);
}

static inline void MADDz(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x + (fs->f.x * ft->f.z);
  if (dest & _y) fd->f.y = ACC.f.y + (fs->f.y * ft->f.z);
  if (dest & _z) fd->f.z = ACC.f.z + (fs->f.z * ft->f.z);
  if (dest & _w) fd->f.w = ACC.f.w + (fs->f.w * ft->f.z);
  UPDATE_FLAGS(dest, fd);
}

static inline void MADDw(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x + (fs->f.x * ft->f.w);
  if (dest & _y) fd->f.y = ACC.f.y + (fs->f.y * ft->f.w);
  if (dest & _z) fd->f.z = ACC.f.z + (fs->f.z * ft->f.w);
  if (dest & _w) fd->f.w = ACC.f.w + (fs->f.w * ft->f.w);
  UPDATE_FLAGS(dest, fd);
}

///////////////////////////////////////////////////////////////////////////////

static inline void MSUBx(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x - (fs->f.x * ft->f.x);
  if (dest & _y) fd->f.y = ACC.f.y - (fs->f.y * ft->f.x);
  if (dest & _z) fd->f.z = ACC.f.z - (fs->f.z * ft->f.x);
  if (dest & _w) fd->f.w = ACC.f.w - (fs->f.w * ft->f.x);
  UPDATE_FLAGS(dest, fd);
}

static inline void MSUBy(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x - (fs->f.x * ft->f.y);
  if (dest & _y) fd->f.y = ACC.f.y - (fs->f.y * ft->f.y);
  if (dest & _z) fd->f.z = ACC.f.z - (fs->f.z * ft->f.y);
  if (dest & _w) fd->f.w = ACC.f.w - (fs->f.w * ft->f.y);
  UPDATE_FLAGS(dest, fd);
}

static inline void MSUBz(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x - (fs->f.x * ft->f.z);
  if (dest & _y) fd->f.y = ACC.f.y - (fs->f.y * ft->f.z);
  if (dest & _z) fd->f.z = ACC.f.z - (fs->f.z * ft->f.z);
  if (dest & _w) fd->f.w = ACC.f.w - (fs->f.w * ft->f.z);
  UPDATE_FLAGS(dest, fd);
}

static inline void MSUBw(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = ACC.f.x - (fs->f.x * ft->f.w);
  if (dest & _y) fd->f.y = ACC.f.y - (fs->f.y * ft->f.w);
  if (dest & _z) fd->f.z = ACC.f.z - (fs->f.z * ft->f.w);
  if (dest & _w) fd->f.w = ACC.f.w - (fs->f.w * ft->f.w);
  UPDATE_FLAGS(dest, fd);
}

///////////////////////////////////////////////////////////////////////////////

static inline void MADDA(uint8_t dest, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) ACC.f.x = ACC.f.x + (fs->f.x * ft->f.x);
  if (dest & _y) ACC.f.y = ACC.f.y + (fs->f.y * ft->f.y);
  if (dest & _z) ACC.f.z = ACC.f.z + (fs->f.z * ft->f.z);
  if (dest & _w) ACC.f.w = ACC.f.w + (fs->f.w * ft->f.w);
  UPDATE_FLAGS(dest, &ACC);
}

///////////////////////////////////////////////////////////////////////////////

static inline void MULA(uint8_t dest, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) ACC.f.x = fs->f.x * ft->f.x;
  if (dest & _y) ACC.f.y = fs->f.y * ft->f.y;
  if (dest & _z) ACC.f.z = fs->f.z * ft->f.z;
  if (dest & _w) ACC.f.w = fs->f.w * ft->f.w;
  UPDATE_FLAGS(dest, &ACC);
}

static inline void MULAx(uint8_t dest, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) ACC.f.x = fs->f.x * ft->f.x;
  if (dest & _y) ACC.f.y = fs->f.y * ft->f.x;
  if (dest & _z) ACC.f.z = fs->f.z * ft->f.x;
  if (dest & _w) ACC.f.w = fs->f.w * ft->f.x;
  UPDATE_FLAGS(dest, &ACC);
}

static inline void MULAy(uint8_t dest, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) ACC.f.x = fs->f.x * ft->f.y;
  if (dest & _y) ACC.f.y = fs->f.y * ft->f.y;
  if (dest & _z) ACC.f.z = fs->f.z * ft->f.y;
  if (dest & _w) ACC.f.w = fs->f.w * ft->f.y;
  UPDATE_FLAGS(dest, &ACC);
}

static inline void MULAz(uint8_t dest, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) ACC.f.x = fs->f.x * ft->f.z;
  if (dest & _y) ACC.f.y = fs->f.y * ft->f.z;
  if (dest & _z) ACC.f.z = fs->f.z * ft->f.z;
  if (dest & _w) ACC.f.w = fs->f.w * ft->f.z;
  UPDATE_FLAGS(dest, &ACC);
}

static inline void MULAw(uint8_t dest, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) ACC.f.x = fs->f.x * ft->f.w;
  if (dest & _y) ACC.f.y = fs->f.y * ft->f.w;
  if (dest & _z) ACC.f.z = fs->f.z * ft->f.w;
  if (dest & _w) ACC.f.w = fs->f.w * ft->f.w;
  UPDATE_FLAGS(dest, &ACC);
}

///////////////////////////////////////////////////////////////////////////////

static inline void MULi(uint8_t dest, REG_VF *fd, REG_VF *fs)
{
  if (dest & _x) fd->f.x = fs->f.x * I.F;
  if (dest & _y) fd->f.y = fs->f.y * I.F;
  if (dest & _z) fd->f.z = fs->f.z * I.F;
  if (dest & _w) fd->f.w = fs->f.w * I.F;
  UPDATE_FLAGS(dest, fd);
}

///////////////////////////////////////////////////////////////////////////////

static inline void MAXi(uint8_t dest, REG_VF *fd, REG_VF *fs)
{
  if (dest & _x) fd->f.x = (fs->f.x > I.F) ? fs->f.x : I.F;
  if (dest & _y) fd->f.y = (fs->f.y > I.F) ? fs->f.y : I.F;
  if (dest & _z) fd->f.z = (fs->f.z > I.F) ? fs->f.z : I.F;
  if (dest & _w) fd->f.w = (fs->f.w > I.F) ? fs->f.w : I.F;
}

///////////////////////////////////////////////////////////////////////////////

static inline void MINI(uint8_t dest, REG_VF *fd, REG_VF *fs, REG_VF *ft)
{
  if (dest & _x) fd->f.x = (fs->f.x < ft->f.x) ? fs->f.x : ft->f.x;
  if (dest & _y) fd->f.y = (fs->f.y < ft->f.y) ? fs->f.y : ft->f.y;
  if (dest & _z) fd->f.z = (fs->f.z < ft->f.z) ? fs->f.z : ft->f.z;
  if (dest & _w) fd->f.w = (fs->f.w < ft->f.w) ? fs->f.w : ft->f.w;
}

///////////////////////////////////////////////////////////////////////////////

static inline void ABS(uint8_t dest, REG_VF *ft, REG_VF *fs)
{
  if (dest & _x) ft->f.x = fabsf(fs->f.x);
  if (dest & _y) ft->f.y = fabsf(fs->f.y);
  if (dest & _z) ft->f.z = fabsf(fs->f.z);
  if (dest & _w) ft->f.w = fabsf(fs->f.w);
}

static inline void FTOI0(uint8_t dest, REG_VF *ft, REG_VF *fs)
{
  if (dest & _x) ft->SL[0] = (int32_t)fs->f.x;
  if (dest & _y) ft->SL[1] = (int32_t)fs->f.y;
  if (dest & _z) ft->SL[2] = (int32_t)fs->f.z;
  if (dest & _w) ft->SL[3] = (int32_t)fs->f.w;
}

static inline void ITOF0(uint8_t dest, REG_VF *ft, REG_VF *fs)
{
  if (dest & _x) ft->f.x = (float)fs->SL[0];
  if (dest & _y) ft->f.y = (float)fs->SL[1];
  if (dest & _z) ft->f.z = (float)fs->SL[2];
  if (dest & _w) ft->f.w = (float)fs->SL[3];
}

static inline void MR32(uint8_t dest, REG_VF *ft, REG_VF *fs)
{
  uint32_t x = fs->i.x;
  if (dest & _x) ft->i.x = fs->i.y;
  if (dest & _y) ft->i.y = fs->i.z;
  if (dest & _z) ft->i.z = fs->i.w;
  if (dest & _w) ft->i.w = x;
}

static inline void MTIR(REG_VI *it, REG_VF *fs, uint8_t fsf)
{
  it->US[0] = *(uint16_t*)(&fs->F[fsf]);
}

static inline void IADDI(REG_VI *it, REG_VI *is, uint16_t imm5)
{
  it->SS[0] = is->SS[0] + (int16_t)((imm5 & 0x10 ? 0xfff0 : 0) | (imm5 & 0xf));
}

static inline void IADDIU(REG_VI *it, REG_VI *is, uint16_t imm15)
{
  it->SS[0] = is->SS[0] + imm15;
}

static inline void ISUBIU(REG_VI *it, REG_VI *is, uint16_t imm15)
{
  it->SS[0] = is->SS[0] - imm15;
}

static inline void IAND(REG_VI *id, REG_VI *is, REG_VI *it)
{
  id->US[0] = is->US[0] & it->US[0];
}

static inline void FMAND(REG_VI *it, REG_VI *is)
{
  it->US[0] = is->US[0] & (MAC.UL & 0xFFFF);
}

///////////////////////////////////////////////////////////////////////////////

static inline void LOI(float imm)
{
  I.F = imm;
}

///////////////////////////////////////////////////////////////////////////////

static inline void ILW(uint8_t dest, REG_VI *it, uint16_t imm11, REG_VI *is)
{
  uint16_t addr = is->UL + (int16_t)((imm11&0x400 ? 0xfc00:0) | (imm11&0x3ff));
  if (dest & _x) it->US[0] = VUMem1[addr].US[0];
  if (dest & _y) it->US[0] = VUMem1[addr].US[2];
  if (dest & _z) it->US[0] = VUMem1[addr].US[4];
  if (dest & _w) it->US[0] = VUMem1[addr].US[6];
}

///////////////////////////////////////////////////////////////////////////////

static inline void LQ(uint8_t dest, REG_VF *ft, uint16_t imm11, REG_VI *is)
{
  uint16_t addr = is->UL + (int16_t)((imm11&0x400 ? 0xfc00:0) | (imm11&0x3ff));
  if (dest & _x) ft->UL[0] = VUMem1[addr].UL[0];
  if (dest & _y) ft->UL[1] = VUMem1[addr].UL[1];
  if (dest & _z) ft->UL[2] = VUMem1[addr].UL[2];
  if (dest & _w) ft->UL[3] = VUMem1[addr].UL[3];
}

static inline void LQD(uint8_t dest, REG_VF *ft, REG_VI *is)
{
  uint16_t addr = --is->UL;
  if (dest & _x) ft->UL[0] = VUMem1[addr].UL[0];
  if (dest & _y) ft->UL[1] = VUMem1[addr].UL[1];
  if (dest & _z) ft->UL[2] = VUMem1[addr].UL[2];
  if (dest & _w) ft->UL[3] = VUMem1[addr].UL[3];
}

static inline void LQI(uint8_t dest, REG_VF *ft, REG_VI *is)
{
  uint16_t addr = is->UL++;
  if (dest & _x) ft->UL[0] = VUMem1[addr].UL[0];
  if (dest & _y) ft->UL[1] = VUMem1[addr].UL[1];
  if (dest & _z) ft->UL[2] = VUMem1[addr].UL[2];
  if (dest & _w) ft->UL[3] = VUMem1[addr].UL[3];
}

///////////////////////////////////////////////////////////////////////////////

static inline void SQ(uint8_t dest, REG_VF *fs, uint16_t imm11, REG_VI *it)
{
  uint16_t addr = it->UL + (int16_t)((imm11&0x400 ? 0xfc00:0) | (imm11&0x3ff));
  if (dest & _x) VUMem1[addr].UL[0] = fs->UL[0];
  if (dest & _y) VUMem1[addr].UL[1] = fs->UL[1];
  if (dest & _z) VUMem1[addr].UL[2] = fs->UL[2];
  if (dest & _w) VUMem1[addr].UL[3] = fs->UL[3];
}

static inline void SQD(uint8_t dest, REG_VF *fs, REG_VI *is)
{
  uint16_t addr = --is->UL;
  if (dest & _x) VUMem1[addr].UL[0] = fs->UL[0];
  if (dest & _y) VUMem1[addr].UL[1] = fs->UL[1];
  if (dest & _z) VUMem1[addr].UL[2] = fs->UL[2];
  if (dest & _w) VUMem1[addr].UL[3] = fs->UL[3];
}

static inline void SQI(uint8_t dest, REG_VF *fs, REG_VI *is)
{
  uint16_t addr = is->UL++;
  if (dest & _x) VUMem1[addr].UL[0] = fs->UL[0];
  if (dest & _y) VUMem1[addr].UL[1] = fs->UL[1];
  if (dest & _z) VUMem1[addr].UL[2] = fs->UL[2];
  if (dest & _w) VUMem1[addr].UL[3] = fs->UL[3];
}
