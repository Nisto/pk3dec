#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "vu1_regs.h"
#include "vu1_mem.h"
#include "vu1_ops.h"
#include "vu1_mpg_6e0_tbl_1f0.h"
#include "vu1_mpg_6e0_tbl_200.h"
#include "vu1_mpg_1410_tbl_300.h"
#include "vu1_mpg_1690_tbl_100.h"
#include "vu1_mpg_1690_tbl_140.h"
#include "vu1_mpg_1690_tbl_180.h"

static void SUB_6E0(void);
static void SUB_C88(void);
static void SUB_1188(void);
static void SUB_1410(void);
static void SUB_1690(void);

static void SUB_6E0(void)
{
  MULx(_xyzw, &VF01, &VF01, &VF00);                                 ILW(_x, &VI03, 0x101, &VI00);

                                                                    IADDIU(&VI01, &VI00, 0x0);
                                                                    IADDIU(&VI02, &VI00, 0x108);
                                                                    IADDIU(&VI12, &VI00, 0xD8);
                                                                    IADDIU(&VI13, &VI00, 0xFF);

                                                                    LQ(_y, &VF02, 0x200, &VI03);

                                                                    ILW(_y, &VI03, 0x101, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_z, &VI03, 0x101, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_w, &VI03, 0x101, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_x, &VI03, 0x102, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_y, &VI03, 0x102, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_z, &VI03, 0x102, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_w, &VI03, 0x102, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_x, &VI03, 0x103, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_y, &VI03, 0x103, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_z, &VI03, 0x103, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_w, &VI03, 0x103, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_x, &VI03, 0x104, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();
                                                                    ILW(_y, &VI03, 0x104, &VI00);
                                                                    SQI(_xyzw, &VF01, &VI12);
                                                                    SUB_C88();

                                                                    ILW(_z, &VI03, 0x104, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_w, &VI03, 0x104, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_x, &VI03, 0x105, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_y, &VI03, 0x105, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_z, &VI03, 0x105, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_w, &VI03, 0x105, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_x, &VI03, 0x106, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_y, &VI03, 0x106, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_z, &VI03, 0x106, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_w, &VI03, 0x106, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_x, &VI03, 0x107, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_y, &VI03, 0x107, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_z, &VI03, 0x107, &VI00);
                                                                    SUB_C88();
                                                                    ILW(_w, &VI03, 0x107, &VI00);
                                                                    SUB_C88();

                                                                    IADDIU(&VI04, &VI00, 0x8);
                                                                    IADDIU(&VI05, &VI00, 0x8);
                                                                    LQ(_xyzw, &VF04, 0x1F0, &VI00);
                                                                    LQ(_xyzw, &VF05, 0x1F1, &VI00);
                                                                    LQ(_xyzw, &VF06, 0x1F2, &VI00);
                                                                    LQ(_xyzw, &VF07, 0x1F3, &VI00);
                                                                    LQ(_xyzw, &VF08, 0x1F4, &VI00);
                                                                    LQ(_xyzw, &VF09, 0x1F5, &VI00);
                                                                    LQ(_xyzw, &VF10, 0x1F6, &VI00);
                                                                    LQ(_xyzw, &VF11, 0x1F7, &VI00);
                                                                    LQ(_xyzw, &VF12, 0x1F8, &VI00);
                                                                    LQ(_xyzw, &VF13, 0x1F9, &VI00);
                                                                    LQ(_xyzw, &VF14, 0x1FA, &VI00);
                                                                    LQ(_xyzw, &VF15, 0x1FB, &VI00);
                                                                    LQ(_xyzw, &VF16, 0x1FC, &VI00);
                                                                    LQ(_xyzw, &VF17, 0x1FD, &VI00);
                                                                    LQ(_xyzw, &VF18, 0x1FE, &VI00);
                                                                    LQ(_xyzw, &VF19, 0x1FF, &VI00);
                                                                    IADDIU(&VI03, &VI00, 0x1B);
                                                                    LQD(_xyzw, &VF24, &VI04);
                                                                    LQI(_xyzw, &VF25, &VI05);
                                                                    LQ(_xyzw, &VF03, 0x100, &VI00);

  MULAx(_w, &VF24, &VF04);
  MSUBx(_w, &VF26, &VF19, &VF25);
  MULAw(_x, &VF25, &VF11);
  MADDw(_x, &VF27, &VF12, &VF24);

while (VI03.UL != VI00.UL) {
  MULAy(_z, &VF24, &VF04);                                          IADDI(&VI06, &VI04, 0x1);
  MSUBy(_z, &VF26, &VF19, &VF25);                                   IADDI(&VI07, &VI05, 0x1F);
  MULAz(_y, &VF25, &VF11);
  MADDz(_y, &VF27, &VF12, &VF24);
  MULAz(_y, &VF24, &VF04);
  MSUBz(_y, &VF26, &VF19, &VF25);
  MULAy(_z, &VF25, &VF11);
  MADDy(_z, &VF27, &VF12, &VF24);
  MULAw(_x, &VF24, &VF04);                                          LQD(_xyzw, &VF28, &VI04);
  MSUBw(_x, &VF26, &VF19, &VF25);                                   LQI(_xyzw, &VF29, &VI05);
  MULAx(_w, &VF25, &VF11);
  MADDx(_w, &VF27, &VF12, &VF24);
  MULAx(_w, &VF28, &VF05);
  MSUBx(_w, &VF30, &VF18, &VF29);                                   SQD(_xyzw, &VF26, &VI06);
  MULAw(_x, &VF29, &VF10);
  MADDw(_x, &VF31, &VF13, &VF28);                                   SQI(_xyzw, &VF27, &VI07);
  MULAy(_z, &VF28, &VF05);
  MSUBy(_z, &VF30, &VF18, &VF29);
  MULAz(_y, &VF29, &VF10);
  MADDz(_y, &VF31, &VF13, &VF28);
  MULAz(_y, &VF28, &VF05);
  MSUBz(_y, &VF30, &VF18, &VF29);
  MULAy(_z, &VF29, &VF10);
  MADDy(_z, &VF31, &VF13, &VF28);
  MULAw(_x, &VF28, &VF05);                                          LQD(_xyzw, &VF24, &VI04);
  MSUBw(_x, &VF30, &VF18, &VF29);                                   LQI(_xyzw, &VF25, &VI05);
  MULAx(_w, &VF29, &VF10);
  MADDx(_w, &VF31, &VF13, &VF28);
  MULAx(_w, &VF24, &VF06);
  MSUBx(_w, &VF26, &VF17, &VF25);                                   SQD(_xyzw, &VF30, &VI06);
  MULAw(_x, &VF25, &VF09);
  MADDw(_x, &VF27, &VF14, &VF24);                                   SQI(_xyzw, &VF31, &VI07);
  MULAy(_z, &VF24, &VF06);
  MSUBy(_z, &VF26, &VF17, &VF25);
  MULAz(_y, &VF25, &VF09);
  MADDz(_y, &VF27, &VF14, &VF24);
  MULAz(_y, &VF24, &VF06);
  MSUBz(_y, &VF26, &VF17, &VF25);
  MULAy(_z, &VF25, &VF09);
  MADDy(_z, &VF27, &VF14, &VF24);
  MULAw(_x, &VF24, &VF06);                                          LQD(_xyzw, &VF28, &VI04);
  MSUBw(_x, &VF26, &VF17, &VF25);                                   LQI(_xyzw, &VF29, &VI05);
  MULAx(_w, &VF25, &VF09);
  MADDx(_w, &VF27, &VF14, &VF24);
  MULAx(_w, &VF28, &VF07);
  MSUBx(_w, &VF30, &VF16, &VF29);                                   SQD(_xyzw, &VF26, &VI06);
  MULAw(_x, &VF29, &VF08);
  MADDw(_x, &VF31, &VF15, &VF28);                                   SQI(_xyzw, &VF27, &VI07);
  MULAy(_z, &VF28, &VF07);
  MSUBy(_z, &VF30, &VF16, &VF29);
  MULAz(_y, &VF29, &VF08);
  MADDz(_y, &VF31, &VF15, &VF28);
  MULAz(_y, &VF28, &VF07);
  MSUBz(_y, &VF30, &VF16, &VF29);
  MULAy(_z, &VF29, &VF08);                                          IADDIU(&VI04, &VI04, 0xC);
  MADDy(_z, &VF31, &VF15, &VF28);                                   IADDIU(&VI05, &VI05, 0x4);
  MULAw(_x, &VF28, &VF07);                                          LQD(_xyzw, &VF24, &VI04);
  MSUBw(_x, &VF30, &VF16, &VF29);                                   LQI(_xyzw, &VF25, &VI05);
  MULAx(_w, &VF29, &VF08);
  MADDx(_w, &VF31, &VF15, &VF28);
  MULAx(_w, &VF24, &VF04);                                          IADDI(&VI03, &VI03, 0x1F);
  MSUBx(_w, &VF26, &VF19, &VF25);                                   SQD(_xyzw, &VF30, &VI06);
  MULAw(_x, &VF25, &VF11);
  MADDw(_x, &VF27, &VF12, &VF24);                                   SQI(_xyzw, &VF31, &VI07);
}

  ITOF0(_xyzw, &VF03, &VF03);
}


static void SUB_C88(void)
{
                                                                    SQI(_xyzw, &VF01, &VI12);
if (VI03.UL == VI00.UL) {
                                                                    SQI(_xyzw, &VF01, &VI01);
                                                                    SQI(_xyzw, &VF01, &VI01);
                                                                    SQI(_xyzw, &VF01, &VI01);
                                                                    SQI(_xyzw, &VF01, &VI01);
                                                                    SQI(_xyzw, &VF01, &VI01);
                                                                    SQI(_xyzw, &VF01, &VI01);
                                                                    SQI(_xyzw, &VF01, &VI01);
                                                                    SQI(_xyzw, &VF01, &VI01);
} else {
                                                                    LQ(_y, &VF03, 0x280, &VI03);
                                                                    LQI(_xyzw, &VF28, &VI02);
                                                                    LQI(_xyzw, &VF29, &VI02);
                                                                    LQI(_xyzw, &VF30, &VI02);
  MULy(_y, &VF03, &VF03, &VF02);                                    LQI(_xyzw, &VF31, &VI02);
  ITOF0(_xyzw, &VF28, &VF28);
  ITOF0(_xyzw, &VF29, &VF29);
  ITOF0(_xyzw, &VF30, &VF30);
  ITOF0(_xyzw, &VF31, &VF31);
  ABS(_xyzw, &VF04, &VF28);
  ABS(_xyzw, &VF05, &VF29);
  ABS(_xyzw, &VF06, &VF30);
  ABS(_xyzw, &VF07, &VF31);
  MULy(_xyzw, &VF04, &VF04, &VF03);
  MULy(_xyzw, &VF05, &VF05, &VF03);
  MULy(_xyzw, &VF06, &VF06, &VF03);
  MULy(_xyzw, &VF07, &VF07, &VF03);                                 LOI(512);
  MULi(_xyzw, &VF08, &VF04);
  MULi(_xyzw, &VF09, &VF05);
  MULi(_xyzw, &VF10, &VF06);
  MULi(_xyzw, &VF11, &VF07);
  ADDw(_xyzw, &VF16, &VF08, &VF00);
  ADDw(_xyzw, &VF17, &VF09, &VF00);
  ADDw(_xyzw, &VF18, &VF10, &VF00);
  ADDw(_xyzw, &VF19, &VF11, &VF00);
  FTOI0(_xyzw, &VF08, &VF08);
  FTOI0(_xyzw, &VF09, &VF09);
  FTOI0(_xyzw, &VF10, &VF10);
  FTOI0(_xyzw, &VF11, &VF11);
  ITOF0(_xyzw, &VF12, &VF08);
  ITOF0(_xyzw, &VF13, &VF09);
  ITOF0(_xyzw, &VF14, &VF10);
  ITOF0(_xyzw, &VF15, &VF11);                                       LOI(0.00195313);
  MULi(_xyzw, &VF12, &VF12);
  MULi(_xyzw, &VF13, &VF13);
  MULi(_xyzw, &VF14, &VF14);
  MULi(_xyzw, &VF15, &VF15);
  FTOI0(_xyzw, &VF16, &VF16);
  FTOI0(_xyzw, &VF17, &VF17);
  FTOI0(_xyzw, &VF18, &VF18);
  FTOI0(_xyzw, &VF19, &VF19);
  ITOF0(_xyzw, &VF16, &VF16);
  ITOF0(_xyzw, &VF17, &VF17);
  ITOF0(_xyzw, &VF18, &VF18);
  ITOF0(_xyzw, &VF19, &VF19);
  MULi(_xyzw, &VF16, &VF16);
  MULi(_xyzw, &VF17, &VF17);
  MULi(_xyzw, &VF18, &VF18);
  MULi(_xyzw, &VF19, &VF19);
  SUB(_xyzw, &VF24, &VF04, &VF12);                                  MTIR(&VI04, &VF08, Fx);
  SUB(_xyzw, &VF25, &VF16, &VF12);                                  MTIR(&VI05, &VF08, Fy);
  ADD(_xyzw, &VF26, &VF28, &VF01);                                  MTIR(&VI06, &VF08, Fz);
                                                                    MTIR(&VI07, &VF08, Fw);
                                                                    SUB_1188();

  SUB(_xyzw, &VF24, &VF05, &VF13);                                  MTIR(&VI04, &VF09, Fx);
  SUB(_xyzw, &VF25, &VF17, &VF13);                                  MTIR(&VI05, &VF09, Fy);
  ADD(_xyzw, &VF26, &VF29, &VF01);                                  MTIR(&VI06, &VF09, Fz);
                                                                    MTIR(&VI07, &VF09, Fw);
                                                                    SUB_1188();

  SUB(_xyzw, &VF24, &VF06, &VF14);                                  MTIR(&VI04, &VF10, Fx);
  SUB(_xyzw, &VF25, &VF18, &VF14);                                  MTIR(&VI05, &VF10, Fy);
  ADD(_xyzw, &VF26, &VF30, &VF01);                                  MTIR(&VI06, &VF10, Fz);
                                                                    MTIR(&VI07, &VF10, Fw);
                                                                    SUB_1188();

  SUB(_xyzw, &VF24, &VF07, &VF15);                                  MTIR(&VI04, &VF11, Fx);
  SUB(_xyzw, &VF25, &VF19, &VF15);                                  MTIR(&VI05, &VF11, Fy);
  ADD(_xyzw, &VF26, &VF31, &VF01);                                  MTIR(&VI06, &VF11, Fz);
                                                                    MTIR(&VI07, &VF11, Fw);
                                                                    SUB_1188();

                                                                    LQI(_xyzw, &VF28, &VI02);
                                                                    LQI(_xyzw, &VF29, &VI02);
                                                                    LQI(_xyzw, &VF30, &VI02);
                                                                    LQI(_xyzw, &VF31, &VI02);
  ITOF0(_xyzw, &VF28, &VF28);
  ITOF0(_xyzw, &VF29, &VF29);
  ITOF0(_xyzw, &VF30, &VF30);
  ITOF0(_xyzw, &VF31, &VF31);
  ABS(_xyzw, &VF04, &VF28);
  ABS(_xyzw, &VF05, &VF29);
  ABS(_xyzw, &VF06, &VF30);
  ABS(_xyzw, &VF07, &VF31);
  MULy(_xyzw, &VF04, &VF04, &VF03);
  MULy(_xyzw, &VF05, &VF05, &VF03);
  MULy(_xyzw, &VF06, &VF06, &VF03);
  MULy(_xyzw, &VF07, &VF07, &VF03);                                 LOI(512);
  MULi(_xyzw, &VF08, &VF04);
  MULi(_xyzw, &VF09, &VF05);
  MULi(_xyzw, &VF10, &VF06);
  MULi(_xyzw, &VF11, &VF07);
  ADDw(_xyzw, &VF16, &VF08, &VF00);
  ADDw(_xyzw, &VF17, &VF09, &VF00);
  ADDw(_xyzw, &VF18, &VF10, &VF00);
  ADDw(_xyzw, &VF19, &VF11, &VF00);
  FTOI0(_xyzw, &VF08, &VF08);
  FTOI0(_xyzw, &VF09, &VF09);
  FTOI0(_xyzw, &VF10, &VF10);
  FTOI0(_xyzw, &VF11, &VF11);
  ITOF0(_xyzw, &VF12, &VF08);
  ITOF0(_xyzw, &VF13, &VF09);
  ITOF0(_xyzw, &VF14, &VF10);
  ITOF0(_xyzw, &VF15, &VF11);                                       LOI(0.00195313);
  MULi(_xyzw, &VF12, &VF12);
  MULi(_xyzw, &VF13, &VF13);
  MULi(_xyzw, &VF14, &VF14);
  MULi(_xyzw, &VF15, &VF15);
  FTOI0(_xyzw, &VF16, &VF16);
  FTOI0(_xyzw, &VF17, &VF17);
  FTOI0(_xyzw, &VF18, &VF18);
  FTOI0(_xyzw, &VF19, &VF19);
  ITOF0(_xyzw, &VF16, &VF16);
  ITOF0(_xyzw, &VF17, &VF17);
  ITOF0(_xyzw, &VF18, &VF18);
  ITOF0(_xyzw, &VF19, &VF19);
  MULi(_xyzw, &VF16, &VF16);
  MULi(_xyzw, &VF17, &VF17);
  MULi(_xyzw, &VF18, &VF18);
  MULi(_xyzw, &VF19, &VF19);
  SUB(_xyzw, &VF24, &VF04, &VF12);                                  MTIR(&VI04, &VF08, Fx);
  SUB(_xyzw, &VF25, &VF16, &VF12);                                  MTIR(&VI05, &VF08, Fy);
  ADD(_xyzw, &VF26, &VF28, &VF01);                                  MTIR(&VI06, &VF08, Fz);
                                                                    MTIR(&VI07, &VF08, Fw);
                                                                    SUB_1188();

  SUB(_xyzw, &VF24, &VF05, &VF13);                                  MTIR(&VI04, &VF09, Fx);
  SUB(_xyzw, &VF25, &VF17, &VF13);                                  MTIR(&VI05, &VF09, Fy);
  ADD(_xyzw, &VF26, &VF29, &VF01);                                  MTIR(&VI06, &VF09, Fz);
                                                                    MTIR(&VI07, &VF09, Fw);
                                                                    SUB_1188();

  SUB(_xyzw, &VF24, &VF06, &VF14);                                  MTIR(&VI04, &VF10, Fx);
  SUB(_xyzw, &VF25, &VF18, &VF14);                                  MTIR(&VI05, &VF10, Fy);
  ADD(_xyzw, &VF26, &VF30, &VF01);                                  MTIR(&VI06, &VF10, Fz);
                                                                    MTIR(&VI07, &VF10, Fw);
                                                                    SUB_1188();

  SUB(_xyzw, &VF24, &VF07, &VF15);                                  MTIR(&VI04, &VF11, Fx);
  SUB(_xyzw, &VF25, &VF19, &VF15);                                  MTIR(&VI05, &VF11, Fy);
  ADD(_xyzw, &VF26, &VF31, &VF01);                                  MTIR(&VI06, &VF11, Fz);
                                                                    MTIR(&VI07, &VF11, Fw);
                                                                    SUB_1188();
}
}


static void SUB_1188(void)
{
                                                                    FMAND(&VI09, &VI13);
                                                                    LOI(-1);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ADDw(_xyzw, &VF27, &VF01, &VF00);                                 IADDIU(&VI11, &VI00, 0x8);
                                                                    IAND(&VI11, &VI11, &VI09);
                                                                    DIV(&VF24, Fx, &VF25, Fx);
                                                                    IADDIU(&VI10, &VI00, 0x80);
                                                                    IAND(&VI10, &VI10, &VI09);
if (VI11.UL != VI00.UL) {
  MULx(_x, &VF20, &VF01, &VF01);                                    
  MULx(_x, &VF21, &VF01, &VF01);
} else {
                                                                    IADDIU(&VI08, &VI04, 0x1);
                                                                    LQ(_x, &VF20, 0x200, &VI04);
                                                                    LQ(_x, &VF21, 0x200, &VI08);
}
                                                                    IADDIU(&VI08, &VI05, 0x1);
if (VI10.UL != VI00.UL) {
  MULi(_x, &VF27, &VF27);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                                    IADDIU(&VI11, &VI00, 0x4);
  ADDq(_x, &VF04, &VF01);                                           IAND(&VI11, &VI11, &VI09);
  MULx(_x, &VF22, &VF01, &VF01);                                    DIV(&VF24, Fy, &VF25, Fy);
  MULx(_x, &VF23, &VF01, &VF01);                                    IADDIU(&VI10, &VI00, 0x40);
                                                                    IAND(&VI10, &VI10, &VI09);
if (VI11.UL == VI00.UL) {
                                                                    LQ(_x, &VF22, 0x200, &VI05);
                                                                    LQ(_x, &VF23, 0x200, &VI08);
}
  ADDx(_y, &VF20, &VF01, &VF22);
  ADDx(_y, &VF21, &VF01, &VF23);                                    IADDIU(&VI08, &VI06, 0x1);
if (VI10.UL != VI00.UL) {
  MULi(_y, &VF27, &VF27);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                                    IADDIU(&VI11, &VI00, 0x2);
  ADDq(_y, &VF04, &VF01);                                           IAND(&VI11, &VI11, &VI09);
  MULx(_x, &VF22, &VF01, &VF01);                                    DIV(&VF24, Fz, &VF25, Fz);
  MULx(_x, &VF23, &VF01, &VF01);                                    IADDIU(&VI10, &VI00, 0x20);
                                                                    IAND(&VI10, &VI10, &VI09);
if (VI11.UL == VI00.UL) {
                                                                    LQ(_x, &VF22, 0x200, &VI06);
                                                                    LQ(_x, &VF23, 0x200, &VI08);
}
  ADDx(_z, &VF20, &VF01, &VF22);
  ADDx(_z, &VF21, &VF01, &VF23);                                    IADDIU(&VI08, &VI07, 0x1);
if (VI10.UL != VI00.UL) {
  MULi(_z, &VF27, &VF27);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                                                    IADDIU(&VI11, &VI00, 0x1);
  ADDq(_z, &VF04, &VF01);                                           IAND(&VI11, &VI11, &VI09);
  MULx(_x, &VF22, &VF01, &VF01);                                    DIV(&VF24, Fw, &VF25, Fw);
  MULx(_x, &VF23, &VF01, &VF01);                                    IADDIU(&VI10, &VI00, 0x10);
                                                                    IAND(&VI10, &VI10, &VI09);
if (VI11.UL == VI00.UL) {
                                                                    LQ(_x, &VF22, 0x200, &VI07);
                                                                    LQ(_x, &VF23, 0x200, &VI08);
}
  ADDx(_w, &VF20, &VF01, &VF22);
  ADDx(_w, &VF21, &VF01, &VF23);
if (VI10.UL != VI00.UL) {
  MULi(_w, &VF27, &VF27);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  ADDq(_w, &VF04, &VF01);
  SUB(_xyzw, &VF21, &VF21, &VF20);

  MUL(_xyzw, &VF04, &VF21, &VF04);

  ADD(_xyzw, &VF04, &VF04, &VF20);

  MUL(_xyzw, &VF04, &VF04, &VF27);

                                                                    SQI(_xyzw, &VF04, &VI01);
}


static void SUB_1410(void)
{
                                                                    IADDIU(&VI01, &VI00, 0x300);
  ADDx(_xyzw, &VF03, &VF00, &VF03);                                 IADDIU(&VI03, &VI00, 0x300);
                                                                    IADDIU(&VI04, &VI00, 0x20);
                                                                    IADDIU(&VI02, &VI00, 0x0);
                                                                    IADDIU(&VI05, &VI00, 0x8);
while (VI04.UL != VI00.UL) {
                                                                    LQI(_xyzw, &VF16, &VI03);
                                                                    LQI(_xyzw, &VF17, &VI03);
                                                                    LQI(_xyzw, &VF18, &VI03);
                                                                    LQI(_xyzw, &VF19, &VI03);
                                                                    LQI(_xyzw, &VF20, &VI03);
                                                                    LQI(_xyzw, &VF21, &VI03);
                                                                    LQI(_xyzw, &VF22, &VI03);
                                                                    LQI(_xyzw, &VF23, &VI03);
                                                                    LQI(_xyzw, &VF24, &VI02);
                                                                    LQI(_xyzw, &VF25, &VI02);
                                                                    LQI(_xyzw, &VF26, &VI02);
                                                                    LQI(_xyzw, &VF27, &VI02);
  MULA(_xyzw, &VF24, &VF16);                                        LQI(_xyzw, &VF28, &VI02);
  MADDA(_xyzw, &VF25, &VF17);                                       LQI(_xyzw, &VF29, &VI02);
  MADDA(_xyzw, &VF26, &VF18);                                       LQI(_xyzw, &VF30, &VI02);
  MADDA(_xyzw, &VF27, &VF19);                                       LQI(_xyzw, &VF31, &VI02);
  MADDA(_xyzw, &VF28, &VF20);                                       LQI(_xyzw, &VF24, &VI02);
  MADDA(_xyzw, &VF29, &VF21);                                       LQI(_xyzw, &VF25, &VI02);
  MADDA(_xyzw, &VF30, &VF22);                                       LQI(_xyzw, &VF26, &VI02);
  MADD(_xyzw, &VF08, &VF31, &VF23);                                 LQI(_xyzw, &VF27, &VI02);
  MULA(_xyzw, &VF24, &VF16);                                        LQI(_xyzw, &VF28, &VI02);
  MADDA(_xyzw, &VF25, &VF17);                                       LQI(_xyzw, &VF29, &VI02);
  MADDA(_xyzw, &VF26, &VF18);                                       LQI(_xyzw, &VF30, &VI02);
  MADDA(_xyzw, &VF27, &VF19);                                       LQI(_xyzw, &VF31, &VI02);
  MADDA(_xyzw, &VF28, &VF20);                                       LQI(_xyzw, &VF24, &VI02);
  MADDA(_xyzw, &VF29, &VF21);                                       LQI(_xyzw, &VF25, &VI02);
  MADDA(_xyzw, &VF30, &VF22);                                       LQI(_xyzw, &VF26, &VI02);
  MADD(_xyzw, &VF09, &VF31, &VF23);                                 LQI(_xyzw, &VF27, &VI02);
while (VI05.UL != VI00.UL) {
  MULA(_xyzw, &VF24, &VF16);                                        LQI(_xyzw, &VF28, &VI02);
  MADDA(_xyzw, &VF25, &VF17);                                       LQI(_xyzw, &VF29, &VI02);
  MADDA(_xyzw, &VF26, &VF18);                                       LQI(_xyzw, &VF30, &VI02);
  MADDA(_xyzw, &VF27, &VF19);                                       LQI(_xyzw, &VF31, &VI02);
  MADDA(_xyzw, &VF28, &VF20);                                       LQI(_xyzw, &VF24, &VI02);
  MADDA(_xyzw, &VF29, &VF21);                                       LQI(_xyzw, &VF25, &VI02);
  MADDA(_xyzw, &VF30, &VF22);                                       LQI(_xyzw, &VF26, &VI02);
  MADD(_xyzw, &VF10, &VF31, &VF23);                                 LQI(_xyzw, &VF27, &VI02);
  MULA(_xyzw, &VF24, &VF16);                                        LQI(_xyzw, &VF28, &VI02);
  MADDA(_xyzw, &VF25, &VF17);                                       LQI(_xyzw, &VF29, &VI02);
  MADDA(_xyzw, &VF26, &VF18);                                       LQI(_xyzw, &VF30, &VI02);
  MADDA(_xyzw, &VF27, &VF19);                                       LQI(_xyzw, &VF31, &VI02);
  MADDA(_xyzw, &VF28, &VF20);                                       LQI(_xyzw, &VF24, &VI02);
  MADDA(_xyzw, &VF29, &VF21);                                       LQI(_xyzw, &VF25, &VI02);
  MADDA(_xyzw, &VF30, &VF22);                                       LQI(_xyzw, &VF26, &VI02);
  MADD(_xyzw, &VF11, &VF31, &VF23);                                 LQI(_xyzw, &VF27, &VI02);
  MULA(_xyzw, &VF24, &VF16);                                        MR32(_xyzw, &VF12, &VF08);
  MADDA(_xyzw, &VF25, &VF17);                                       MR32(_xyzw, &VF13, &VF09);
  MADDA(_xyzw, &VF26, &VF18);                                       MR32(_xyzw, &VF14, &VF10);
  MADDA(_xyzw, &VF27, &VF19);                                       MR32(_xyzw, &VF15, &VF11);
  ADD(_xz, &VF12, &VF12, &VF08);
  ADD(_yw, &VF13, &VF13, &VF09);                                    LOI(0.25);
  ADD(_xz, &VF14, &VF14, &VF10);                                    LQI(_xyzw, &VF28, &VI02);
  ADD(_yw, &VF15, &VF15, &VF11);                                    LQI(_xyzw, &VF29, &VI02);
  ADDz(_x, &VF01, &VF12, &VF12);                                    LQI(_xyzw, &VF30, &VI02);
  ADDw(_y, &VF01, &VF13, &VF13);                                    LQI(_xyzw, &VF31, &VI02);
  ADDx(_z, &VF01, &VF14, &VF14);                                    LQI(_xyzw, &VF24, &VI02);
  ADDy(_w, &VF01, &VF15, &VF15);                                    LQI(_xyzw, &VF25, &VI02);
  MADDA(_xyzw, &VF28, &VF20);                                       LQI(_xyzw, &VF26, &VI02);
  MADDA(_xyzw, &VF29, &VF21);                                       LQI(_xyzw, &VF27, &VI02);
  MADDA(_xyzw, &VF30, &VF22);                                       LQI(_xyzw, &VF28, &VI02);
  MADD(_xyzw, &VF08, &VF31, &VF23);                                 LQI(_xyzw, &VF29, &VI02);
  MULi(_xyzw, &VF01, &VF01);                                        LQI(_xyzw, &VF30, &VI02);
  MULA(_xyzw, &VF24, &VF16);                                        LQI(_xyzw, &VF31, &VI02);
  MADDA(_xyzw, &VF25, &VF17);                                       LQI(_xyzw, &VF24, &VI02);
  MADDA(_xyzw, &VF26, &VF18);                                       LQI(_xyzw, &VF25, &VI02);
  MADDA(_xyzw, &VF27, &VF19);                                       SQI(_xyzw, &VF01, &VI01);
  MADDA(_xyzw, &VF28, &VF20);                                       IADDI(&VI05, &VI05, 0x1F);
  MADDA(_xyzw, &VF29, &VF21);                                       LQI(_xyzw, &VF26, &VI02);
  MADDA(_xyzw, &VF30, &VF22);
  MADD(_xyzw, &VF09, &VF31, &VF23);                                 LQI(_xyzw, &VF27, &VI02);
}
                                                                    IADDI(&VI04, &VI04, 0x1F);
                                                                    IADDIU(&VI02, &VI00, 0x0);
                                                                    IADDIU(&VI05, &VI00, 0x8);
}
}


static void SUB_1690(void)
{
  SUBw(_w, &VF03, &VF03, &VF00);                                    IADDIU(&VI01, &VI00, 0x300);
                                                                    IADDIU(&VI02, &VI00, 0x300);
                                                                    IADDIU(&VI15, &VI00, 0x20);
                                                                    IADDIU(&VI14, &VI00, 0x10);
                                                                    SQ(_xyzw, &VF03, 0x0, &VI00);
                                                                    IADDIU(&VI13, &VI00, 0xFF);
while (VI15.UL != VI00.UL) {
  MULx(_xyzw, &VF02, &VF02, &VF00);                                 ISUBIU(&VI14, &VI14, 0x10);
                                                                    IAND(&VI04, &VI14, &VI13);
                                                                    IADDIU(&VI05, &VI04, 0x200);
                                                                    IADDIU(&VI03, &VI00, 0x180);
                                                                    LQI(_xyzw, &VF16, &VI02);
                                                                    LQI(_xyzw, &VF17, &VI02);
                                                                    LQI(_xyzw, &VF18, &VI02);
                                                                    LQI(_xyzw, &VF19, &VI02);
                                                                    LQI(_xyzw, &VF20, &VI02);
  ADDw(_x, &VF03, &VF17, &VF16);                                    LQI(_xyzw, &VF21, &VI02);
  ADDx(_w, &VF03, &VF17, &VF18);                                    LQI(_xyzw, &VF22, &VI02);
                                                                    LQI(_xyzw, &VF23, &VI02);
  ADDx(_w, &VF24, &VF18, &VF19);
  ADDw(_x, &VF25, &VF20, &VF19);
  ADDw(_x, &VF04, &VF21, &VF20);
  ADDx(_w, &VF04, &VF21, &VF22);
  ADDx(_w, &VF25, &VF22, &VF23);
  ADDx(_y, &VF24, &VF02, &VF03);
  ADDw(_z, &VF24, &VF02, &VF03);
  ADDx(_y, &VF25, &VF02, &VF04);
  ADDw(_z, &VF25, &VF02, &VF04);
  ADDw(_x, &VF05, &VF16, &VF23);
  SUBw(_x, &VF06, &VF16, &VF23);

  ADDz(_z, &VF28, &VF24, &VF25);
  ADDx(_z, &VF26, &VF02, &VF05);
  ADDx(_w, &VF28, &VF02, &VF06);
  SUBz(_z, &VF03, &VF24, &VF25);                                    LQ(_x, &VF04, 0x4, &VI03);

  ADDz(_x, &VF28, &VF25, &VF26);

  MULx(_z, &VF04, &VF03, &VF04);

  ADDz(_x, &VF26, &VF28, &VF28);

  ADDz(_y, &VF28, &VF02, &VF04);

  SUBx(_z, &VF26, &VF26, &VF25);
  ADDy(_w, &VF05, &VF24, &VF25);
  ADDw(_y, &VF26, &VF28, &VF28);
  SUBy(_w, &VF26, &VF28, &VF28);
  SUBz(_x, &VF15, &VF28, &VF28);
  ADDw(_y, &VF28, &VF24, &VF24);
  ADDw(_z, &VF28, &VF02, &VF05);
  ADDy(_w, &VF28, &VF25, &VF25);
  ADDw(_y, &VF03, &VF24, &VF25);
  SUBw(_y, &VF04, &VF24, &VF25);
  ADDw(_y, &VF30, &VF24, &VF25);
  SUBw(_y, &VF05, &VF28, &VF28);                                    LQ(_x, &VF06, 0x4, &VI03);
  ADDy(_z, &VF31, &VF28, &VF03);
  ADDy(_w, &VF31, &VF02, &VF04);
  SUBz(_y, &VF30, &VF30, &VF28);
  MULx(_y, &VF28, &VF05, &VF06);
  ADDz(_x, &VF12, &VF26, &VF31);
  ADDx(_x, &VF13, &VF02, &VF15);
  MULx(_y, &VF30, &VF30, &VF06);
  ADDy(_w, &VF03, &VF31, &VF28);                                    LQ(_x, &VF04, 0x2, &VI03);
  SUBy(_w, &VF05, &VF31, &VF28);                                    LQ(_x, &VF06, 0x6, &VI03);
  SUBz(_x, &VF14, &VF26, &VF31);
  ADDy(_z, &VF12, &VF26, &VF30);
  MULw(_x, &VF30, &VF04, &VF03);
  MULx(_w, &VF05, &VF05, &VF06);

  ADDz(_z, &VF15, &VF02, &VF12);
  ADDx(_y, &VF12, &VF26, &VF30);
  ADDw(_z, &VF30, &VF02, &VF05);


  ADDy(_w, &VF15, &VF02, &VF12);
  ADDz(_w, &VF12, &VF26, &VF30);
  SUBz(_w, &VF14, &VF26, &VF30);
  SUBy(_z, &VF13, &VF26, &VF30);
  SUBx(_y, &VF14, &VF26, &VF30);
  ADDw(_y, &VF15, &VF02, &VF12);
  ADDw(_y, &VF13, &VF02, &VF14);
  ADDz(_z, &VF14, &VF02, &VF13);
  ADDy(_w, &VF13, &VF02, &VF14);
  ADDz(_y, &VF03, &VF16, &VF16);
  ADDz(_y, &VF04, &VF19, &VF19);
  ADDz(_y, &VF24, &VF17, &VF17);
  ADDy(_z, &VF24, &VF18, &VF18);
  ADDy(_x, &VF24, &VF02, &VF03);
  ADDy(_w, &VF24, &VF02, &VF04);
  ADDz(_y, &VF03, &VF20, &VF20);
  ADDz(_y, &VF04, &VF23, &VF23);
  ADDz(_y, &VF25, &VF21, &VF21);
  ADDy(_z, &VF25, &VF22, &VF22);
  ADDy(_x, &VF25, &VF02, &VF03);
  ADDy(_w, &VF25, &VF02, &VF04);
  ADDz(_y, &VF27, &VF24, &VF24);
  ADDz(_y, &VF06, &VF25, &VF25);
  ADDx(_w, &VF05, &VF24, &VF25);
  ADDw(_x, &VF29, &VF24, &VF25);
  SUBw(_x, &VF03, &VF24, &VF25);
  ADDy(_w, &VF27, &VF02, &VF06);
  ADDw(_z, &VF27, &VF02, &VF05);
  ADDy(_x, &VF28, &VF24, &VF24);
  ADDx(_w, &VF28, &VF02, &VF03);
  ADDw(_y, &VF31, &VF27, &VF27);
  ADDz(_x, &VF31, &VF29, &VF27);
  SUBw(_y, &VF28, &VF27, &VF27);                                    LQ(_x, &VF04, 0x4, &VI03);
  SUBz(_x, &VF05, &VF29, &VF27);
  ADDw(_z, &VF06, &VF24, &VF24);
  ADDy(_x, &VF26, &VF31, &VF31);
  MULx(_y, &VF28, &VF28, &VF04);
  ADDx(_z, &VF26, &VF02, &VF05);

  ADDy(_x, &VF03, &VF25, &VF25);
  ADDw(_y, &VF26, &VF28, &VF28);
  SUBy(_w, &VF26, &VF28, &VF28);
  ADDz(_w, &VF28, &VF25, &VF25);
  ADDx(_z, &VF28, &VF02, &VF03);
  ADDz(_y, &VF28, &VF02, &VF06);
  ADDx(_x, &VF01, &VF12, &VF26);
  ADDw(_x, &VF29, &VF28, &VF28);
  ADDz(_y, &VF29, &VF28, &VF28);
  SUBw(_x, &VF04, &VF28, &VF28);
  ADDy(_x, &VF05, &VF28, &VF28);
  ADDz(_w, &VF29, &VF28, &VF28);                                    LOI(-1);
  MULi(_x, &VF01, &VF01);
  ADDx(_w, &VF31, &VF02, &VF04);
  ADDx(_z, &VF29, &VF02, &VF05);
  SUBy(_x, &VF04, &VF29, &VF29);                                    LQ(_x, &VF03, 0x4, &VI03);
                                                                    SQ(_x, &VF01, 0xC, &VI05);

  SUBw(_z, &VF06, &VF29, &VF29);
  MULx(_x, &VF04, &VF04, &VF03);


  MULx(_z, &VF06, &VF06, &VF03);
  ADDx(_y, &VF30, &VF02, &VF04);


  ADDz(_w, &VF29, &VF02, &VF06);



  ADDw(_w, &VF05, &VF31, &VF29);                                    LQ(_x, &VF03, 0x2, &VI03);
  SUBw(_w, &VF04, &VF31, &VF29);                                    LQ(_x, &VF06, 0x6, &VI03);


  MULx(_w, &VF05, &VF05, &VF03);
  MULx(_w, &VF04, &VF04, &VF06);


  ADDw(_x, &VF30, &VF02, &VF05);
  ADDw(_z, &VF30, &VF02, &VF04);

  SUBx(_x, &VF12, &VF12, &VF26);
  ADDx(_y, &VF03, &VF26, &VF30);                                    LQ(_x, &VF04, 0x1, &VI03);
  ADDy(_z, &VF03, &VF26, &VF30);                                    LQ(_x, &VF05, 0x2, &VI03);
  ADDz(_w, &VF03, &VF26, &VF30);                                    LQ(_x, &VF06, 0x3, &VI03);
  SUBy(_x, &VF03, &VF31, &VF31);                                    LQ(_x, &VF01, 0x4, &VI03);
  MULx(_y, &VF03, &VF03, &VF04);
  MULx(_z, &VF03, &VF03, &VF05);
  MULx(_w, &VF03, &VF03, &VF06);
  MULx(_x, &VF03, &VF03, &VF01);
  SUBy(_y, &VF12, &VF12, &VF03);
  ADDy(_w, &VF15, &VF15, &VF03);
  SUBz(_z, &VF12, &VF12, &VF03);
  ADDz(_z, &VF15, &VF15, &VF03);
  SUBw(_w, &VF12, &VF12, &VF03);
  ADDw(_y, &VF15, &VF15, &VF03);
  SUBx(_x, &VF13, &VF13, &VF03);
  ADDx(_x, &VF15, &VF15, &VF03);
  SUBz(_w, &VF03, &VF26, &VF30);                                    LQ(_x, &VF04, 0x5, &VI03);
  SUBy(_z, &VF03, &VF26, &VF30);                                    LQ(_x, &VF05, 0x6, &VI03);
  SUBx(_y, &VF03, &VF26, &VF30);                                    LQ(_x, &VF06, 0x7, &VI03);

  MULx(_w, &VF03, &VF03, &VF04);
  MULx(_z, &VF03, &VF03, &VF05);
  MULx(_y, &VF03, &VF03, &VF06);

  SUBw(_y, &VF13, &VF13, &VF03);
  ADDw(_w, &VF14, &VF14, &VF03);
  SUBz(_z, &VF13, &VF13, &VF03);
  ADDz(_z, &VF14, &VF14, &VF03);
  SUBy(_w, &VF13, &VF13, &VF03);
  ADDy(_y, &VF14, &VF14, &VF03);
  ADDy(_x, &VF16, &VF16, &VF16);                                    LOI(-1);
  ADDw(_z, &VF03, &VF16, &VF16);
  ADDy(_x, &VF03, &VF17, &VF17);
  ADDz(_w, &VF16, &VF17, &VF17);
  MULi(_x, &VF16, &VF16);
  ADDz(_y, &VF16, &VF02, &VF03);
  MULi(_x, &VF03, &VF03);
  ADDy(_x, &VF17, &VF18, &VF18);
  ADDw(_z, &VF03, &VF18, &VF18);
  ADDy(_x, &VF04, &VF19, &VF19);
  ADDx(_z, &VF16, &VF02, &VF03);
  MULi(_x, &VF17, &VF17);
  ADDz(_y, &VF17, &VF02, &VF03);
  MULi(_x, &VF04, &VF04);
  ADDz(_w, &VF17, &VF19, &VF19);
  ADDy(_x, &VF18, &VF20, &VF20);
  ADDw(_z, &VF03, &VF20, &VF20);
  ADDx(_z, &VF17, &VF02, &VF04);
  ADDy(_x, &VF04, &VF21, &VF21);
  MULi(_x, &VF18, &VF18);
  ADDz(_y, &VF18, &VF02, &VF03);
  ADDz(_w, &VF18, &VF21, &VF21);
  MULi(_x, &VF04, &VF04);
  ADDy(_x, &VF19, &VF22, &VF22);
  ADDw(_z, &VF03, &VF22, &VF22);
  ADDy(_x, &VF05, &VF23, &VF23);
  ADDx(_z, &VF18, &VF02, &VF04);
  MULi(_x, &VF19, &VF19);
  ADDz(_y, &VF19, &VF02, &VF03);
  MULi(_x, &VF05, &VF05);
  ADDz(_w, &VF19, &VF23, &VF23);


  ADDx(_z, &VF19, &VF02, &VF05);
  ADDz(_y, &VF24, &VF16, &VF16);                                    LOI(-1);
  ADDx(_w, &VF03, &VF16, &VF17);
  ADDz(_y, &VF03, &VF17, &VF17);
  ADDw(_x, &VF25, &VF18, &VF17);
  ADDz(_y, &VF25, &VF18, &VF18);
  ADDw(_z, &VF24, &VF02, &VF03);
  ADDy(_w, &VF24, &VF02, &VF03);
  ADDx(_w, &VF03, &VF18, &VF19);
  ADDz(_y, &VF03, &VF19, &VF19);
  ADDy(_y, &VF04, &VF24, &VF25);
  ADDw(_y, &VF27, &VF24, &VF24);
  ADDw(_z, &VF25, &VF02, &VF03);
  ADDy(_w, &VF25, &VF02, &VF03);
  SUBw(_y, &VF04, &VF04, &VF24);
  ADDy(_w, &VF03, &VF24, &VF25);
  ADDy(_w, &VF27, &VF25, &VF25);
  SUBz(_z, &VF05, &VF24, &VF25);
  SUBw(_y, &VF04, &VF04, &VF25);
  ADDw(_z, &VF27, &VF02, &VF03);
  ADDw(_y, &VF03, &VF27, &VF27);                                    LQ(_x, &VF06, 0x4, &VI03);
  ADDz(_y, &VF30, &VF02, &VF05);
  ADDy(_x, &VF09, &VF02, &VF04);
  SUBw(_y, &VF04, &VF27, &VF27);
  MULx(_y, &VF03, &VF03, &VF06);


  MULx(_y, &VF04, &VF04, &VF06);
  ADDy(_z, &VF30, &VF02, &VF03);


  ADDy(_z, &VF26, &VF02, &VF04);
  ADDz(_z, &VF03, &VF30, &VF27);                                    LQ(_x, &VF06, 0x2, &VI03);
  SUBz(_z, &VF04, &VF30, &VF27);                                    LQ(_x, &VF05, 0x6, &VI03);
  ADDz(_z, &VF01, &VF24, &VF25);                                    LQ(_x, &VF07, 0x4, &VI03);

  MULx(_z, &VF03, &VF03, &VF06);
  MULx(_z, &VF04, &VF04, &VF05);
  MULx(_z, &VF01, &VF01, &VF07);

  ADDz(_y, &VF26, &VF02, &VF03);
  ADDz(_w, &VF26, &VF02, &VF04);
  ADDz(_w, &VF31, &VF02, &VF01);



  SUBx(_w, &VF03, &VF31, &VF25);
  ADDw(_x, &VF30, &VF25, &VF31);


  ADDw(_z, &VF30, &VF02, &VF03);
  ADDx(_y, &VF08, &VF26, &VF30);
  ADDy(_z, &VF08, &VF26, &VF30);
  MULi(_x, &VF11, &VF09);
  ADDz(_w, &VF08, &VF26, &VF30);
  MULi(_y, &VF03, &VF08);
  MULi(_z, &VF11, &VF08);
  SUBz(_w, &VF05, &VF26, &VF30);
  MULi(_w, &VF04, &VF08);
  ADDy(_w, &VF11, &VF02, &VF03);
  SUBy(_z, &VF09, &VF26, &VF30);
  ADDw(_y, &VF09, &VF02, &VF05);
  ADDw(_y, &VF11, &VF02, &VF04);
  SUBx(_y, &VF04, &VF26, &VF30);
  MULi(_z, &VF10, &VF09);
  MULi(_y, &VF03, &VF09);

  ADDy(_w, &VF09, &VF02, &VF04);

  ADDy(_w, &VF10, &VF02, &VF03);

  MULi(_w, &VF03, &VF09);



  ADDw(_y, &VF10, &VF02, &VF03);
  ADDy(_x, &VF24, &VF16, &VF16);
  ADDw(_z, &VF03, &VF16, &VF16);
  ADDy(_x, &VF04, &VF17, &VF17);
  ADDz(_w, &VF24, &VF17, &VF17);
  ADDy(_x, &VF25, &VF18, &VF18);
  ADDz(_y, &VF24, &VF02, &VF03);
  ADDx(_z, &VF24, &VF02, &VF04);
  ADDw(_z, &VF03, &VF18, &VF18);
  ADDy(_x, &VF04, &VF19, &VF19);
  ADDz(_w, &VF25, &VF19, &VF19);

  ADDz(_y, &VF25, &VF02, &VF03);
  ADDx(_z, &VF25, &VF02, &VF04);
  SUBy(_x, &VF10, &VF24, &VF24);
  SUBw(_z, &VF03, &VF24, &VF24);
  SUBy(_x, &VF04, &VF25, &VF25);
  SUBw(_z, &VF05, &VF25, &VF25);
  ADDz(_y, &VF06, &VF25, &VF25);
  ADDz(_x, &VF10, &VF10, &VF03);
  ADDx(_w, &VF03, &VF24, &VF25);
  ADDz(_x, &VF04, &VF04, &VF05);
  ADDy(_w, &VF28, &VF02, &VF06);
  ADDz(_y, &VF28, &VF24, &VF24);
  ADDw(_z, &VF28, &VF02, &VF03);
  ADDx(_x, &VF10, &VF10, &VF04);
  ADDz(_w, &VF27, &VF25, &VF25);
  ADDy(_x, &VF05, &VF25, &VF25);
  ADDw(_z, &VF06, &VF24, &VF24);
  ADDy(_x, &VF27, &VF24, &VF24);

  ADDx(_z, &VF27, &VF02, &VF05);
  ADDz(_y, &VF27, &VF02, &VF06);


  ADDw(_z, &VF04, &VF27, &VF27);
  ADDy(_x, &VF29, &VF27, &VF27);
  ADDz(_y, &VF03, &VF27, &VF27);

  ADDz(_y, &VF29, &VF02, &VF04);

  ADDy(_w, &VF29, &VF02, &VF03);

  ADDy(_x, &VF03, &VF29, &VF29);                                    LQ(_x, &VF04, 0x4, &VI03);
  SUBy(_x, &VF05, &VF29, &VF29);
  ADDy(_w, &VF31, &VF28, &VF28);
  SUBw(_y, &VF30, &VF28, &VF28);
  MULx(_x, &VF03, &VF03, &VF04);
  MULx(_x, &VF05, &VF05, &VF04);
  MULx(_w, &VF31, &VF31, &VF04);

  ADDx(_z, &VF30, &VF02, &VF03);
  ADDx(_z, &VF26, &VF02, &VF05);
  ADDz(_w, &VF07, &VF31, &VF28);
  SUBz(_w, &VF01, &VF31, &VF28);
  ADDw(_z, &VF03, &VF30, &VF29);                                    LQ(_x, &VF04, 0x2, &VI03);
  SUBw(_z, &VF05, &VF30, &VF29);                                    LQ(_x, &VF06, 0x6, &VI03);
  ADDw(_x, &VF30, &VF02, &VF07);
  ADDw(_z, &VF30, &VF02, &VF01);
  MULx(_z, &VF03, &VF03, &VF04);
  MULx(_z, &VF05, &VF05, &VF06);


  ADDz(_y, &VF26, &VF02, &VF03);
  ADDz(_w, &VF26, &VF02, &VF05);
  ADDx(_x, &VF08, &VF02, &VF02);
  SUBy(_x, &VF01, &VF27, &VF27);
  ADDx(_y, &VF03, &VF26, &VF30);                                    LQ(_x, &VF04, 0x1, &VI03);
  ADDy(_z, &VF03, &VF26, &VF30);                                    LQ(_x, &VF05, 0x2, &VI03);
  ADDz(_w, &VF03, &VF26, &VF30);                                    LQ(_x, &VF06, 0x3, &VI03);
  ADDz(_x, &VF01, &VF01, &VF27);                                    LQ(_x, &VF07, 0x4, &VI03);
  MULx(_y, &VF03, &VF03, &VF04);
  MULx(_z, &VF03, &VF03, &VF05);
  MULx(_w, &VF03, &VF03, &VF06);
  SUBw(_x, &VF01, &VF01, &VF27);
  ADDy(_y, &VF08, &VF08, &VF03);
  ADDy(_w, &VF11, &VF11, &VF03);
  ADDz(_z, &VF08, &VF08, &VF03);
  ADDz(_z, &VF11, &VF11, &VF03);
  ADDw(_w, &VF08, &VF08, &VF03);
  ADDw(_y, &VF11, &VF11, &VF03);
  MULx(_x, &VF01, &VF01, &VF07);
  SUBz(_w, &VF03, &VF26, &VF30);                                    LQ(_x, &VF04, 0x5, &VI03);
  SUBy(_z, &VF03, &VF26, &VF30);                                    LQ(_x, &VF05, 0x6, &VI03);
  SUBx(_y, &VF03, &VF26, &VF30);                                    LQ(_x, &VF06, 0x7, &VI03);
  ADDx(_x, &VF09, &VF09, &VF01);
  ADDx(_x, &VF11, &VF11, &VF01);
  MULx(_w, &VF03, &VF03, &VF04);
  MULx(_z, &VF03, &VF03, &VF05);
  MULx(_y, &VF03, &VF03, &VF06);

  ADDw(_y, &VF09, &VF09, &VF03);
  ADDw(_w, &VF10, &VF10, &VF03);
  ADDz(_z, &VF09, &VF09, &VF03);
  ADDz(_z, &VF10, &VF10, &VF03);                                    LQ(_xyzw, &VF16, 0x0, &VI03);
  ADDy(_w, &VF09, &VF09, &VF03);                                    LQ(_xyzw, &VF17, 0x1, &VI03);
  ADDy(_y, &VF10, &VF10, &VF03);                                    LQ(_xyzw, &VF18, 0x2, &VI03);
  SUBw(_xyzw, &VF01, &VF02, &VF00);                                 LQ(_xyzw, &VF19, 0x3, &VI03);
  MULz(_y, &VF08, &VF08, &VF16);                                    LQ(_xyzw, &VF20, 0x4, &VI03);
  MULx(_z, &VF08, &VF08, &VF17);                                    LQ(_xyzw, &VF21, 0x5, &VI03);
  MULz(_w, &VF08, &VF08, &VF17);                                    LQ(_xyzw, &VF22, 0x6, &VI03);
  MULx(_x, &VF09, &VF09, &VF18);                                    LQ(_xyzw, &VF23, 0x7, &VI03);
  ADDy(_y, &VF24, &VF12, &VF08);
  ADDz(_z, &VF24, &VF12, &VF08);
  ADDw(_w, &VF24, &VF12, &VF08);
  ADDx(_x, &VF24, &VF13, &VF09);
  MULy(_y, &VF24, &VF24, &VF20);
  MULz(_z, &VF24, &VF24, &VF20);
  MULw(_w, &VF24, &VF24, &VF20);
  MULx(_x, &VF24, &VF24, &VF21);
  MULy(_w, &VF25, &VF01, &VF24);
  MULz(_z, &VF25, &VF01, &VF24);
  MULw(_y, &VF25, &VF01, &VF24);
  MULx(_x, &VF25, &VF01, &VF24);                                    SQ(_yzw, &VF24, 0x0, &VI05);
  SUBy(_y, &VF03, &VF08, &VF12);                                    SQ(_x, &VF24, 0x1, &VI05);
  SUBz(_z, &VF03, &VF08, &VF12);
  SUBw(_w, &VF03, &VF08, &VF12);
  SUBx(_x, &VF03, &VF09, &VF13);                                    SQ(_xyzw, &VF25, 0x7, &VI05);
  MULy(_w, &VF26, &VF19, &VF03);
  MULz(_z, &VF26, &VF19, &VF03);
  MULw(_y, &VF26, &VF19, &VF03);
  MULx(_x, &VF26, &VF19, &VF03);
  ADDw(_y, &VF27, &VF02, &VF26);
  ADDz(_z, &VF27, &VF02, &VF26);
  ADDy(_w, &VF27, &VF02, &VF26);
  ADDx(_x, &VF27, &VF02, &VF26);                                    SQ(_xyzw, &VF26, 0xF, &VI05);
  MULz(_y, &VF09, &VF09, &VF18);
  MULx(_z, &VF09, &VF09, &VF19);
  MULz(_w, &VF09, &VF09, &VF19);
  MULx(_x, &VF10, &VF10, &VF20);                                    SQ(_yzw, &VF27, 0x8, &VI05);
  ADDy(_y, &VF24, &VF13, &VF09);                                    SQ(_x, &VF27, 0x9, &VI05);
  ADDz(_z, &VF24, &VF13, &VF09);
  ADDw(_w, &VF24, &VF13, &VF09);
  ADDx(_x, &VF24, &VF14, &VF10);
  MULy(_y, &VF24, &VF24, &VF21);
  MULz(_z, &VF24, &VF24, &VF21);
  MULw(_w, &VF24, &VF24, &VF21);
  MULx(_x, &VF24, &VF24, &VF22);
  MULy(_w, &VF25, &VF01, &VF24);
  MULz(_z, &VF25, &VF01, &VF24);
  MULw(_y, &VF25, &VF01, &VF24);
  MULx(_x, &VF25, &VF01, &VF24);                                    SQ(_yzw, &VF24, 0x1, &VI05);
  SUBy(_y, &VF03, &VF09, &VF13);                                    SQ(_x, &VF24, 0x2, &VI05);
  SUBz(_z, &VF03, &VF09, &VF13);
  SUBw(_w, &VF03, &VF09, &VF13);
  SUBx(_x, &VF03, &VF10, &VF14);                                    SQ(_xyzw, &VF25, 0x6, &VI05);
  MULy(_w, &VF26, &VF18, &VF03);
  MULz(_z, &VF26, &VF18, &VF03);
  MULw(_y, &VF26, &VF18, &VF03);
  MULx(_x, &VF26, &VF18, &VF03);
  ADDw(_y, &VF27, &VF02, &VF26);
  ADDz(_z, &VF27, &VF02, &VF26);
  ADDy(_w, &VF27, &VF02, &VF26);
  ADDx(_x, &VF27, &VF02, &VF26);                                    SQ(_xyzw, &VF26, 0xE, &VI05);
  MULz(_y, &VF10, &VF10, &VF20);
  MULx(_z, &VF10, &VF10, &VF21);
  MULz(_w, &VF10, &VF10, &VF21);
  MULx(_x, &VF11, &VF11, &VF22);                                    SQ(_yzw, &VF27, 0x9, &VI05);
  ADDy(_y, &VF24, &VF14, &VF10);                                    SQ(_x, &VF27, 0xA, &VI05);
  ADDz(_z, &VF24, &VF14, &VF10);
  ADDw(_w, &VF24, &VF14, &VF10);
  ADDx(_x, &VF24, &VF15, &VF11);
  MULy(_y, &VF24, &VF24, &VF22);
  MULz(_z, &VF24, &VF24, &VF22);
  MULw(_w, &VF24, &VF24, &VF22);
  MULx(_x, &VF24, &VF24, &VF23);
  MULy(_w, &VF25, &VF01, &VF24);
  MULz(_z, &VF25, &VF01, &VF24);
  MULw(_y, &VF25, &VF01, &VF24);
  MULx(_x, &VF25, &VF01, &VF24);                                    SQ(_yzw, &VF24, 0x2, &VI05);
  SUBy(_y, &VF03, &VF10, &VF14);                                    SQ(_x, &VF24, 0x3, &VI05);
  SUBz(_z, &VF03, &VF10, &VF14);
  SUBw(_w, &VF03, &VF10, &VF14);
  SUBx(_x, &VF03, &VF11, &VF15);                                    SQ(_xyzw, &VF25, 0x5, &VI05);
  MULy(_w, &VF26, &VF17, &VF03);
  MULz(_z, &VF26, &VF17, &VF03);
  MULw(_y, &VF26, &VF17, &VF03);
  MULx(_x, &VF26, &VF17, &VF03);
  ADDw(_y, &VF27, &VF02, &VF26);
  ADDz(_z, &VF27, &VF02, &VF26);
  ADDy(_w, &VF27, &VF02, &VF26);
  ADDx(_x, &VF27, &VF02, &VF26);                                    SQ(_xyzw, &VF26, 0xD, &VI05);
  MULz(_y, &VF11, &VF11, &VF22);
  MULx(_z, &VF11, &VF11, &VF23);
  MULz(_w, &VF11, &VF11, &VF23);
                                                                    SQ(_yzw, &VF27, 0xA, &VI05);
  ADDy(_y, &VF24, &VF15, &VF11);                                    SQ(_x, &VF27, 0xB, &VI05);
  ADDz(_z, &VF24, &VF15, &VF11);
  ADDw(_w, &VF24, &VF15, &VF11);

  MULy(_y, &VF24, &VF24, &VF23);
  MULz(_z, &VF24, &VF24, &VF23);
  MULw(_w, &VF24, &VF24, &VF23);

  MULy(_w, &VF25, &VF01, &VF24);
  MULz(_z, &VF25, &VF01, &VF24);
  MULw(_y, &VF25, &VF01, &VF24);                                    SQ(_yzw, &VF24, 0x3, &VI05);
  SUBy(_y, &VF03, &VF11, &VF15);
  SUBz(_z, &VF03, &VF11, &VF15);
  SUBw(_w, &VF03, &VF11, &VF15);
                                                                    SQ(_yzw, &VF25, 0x4, &VI05);
  MULy(_w, &VF26, &VF16, &VF03);
  MULz(_z, &VF26, &VF16, &VF03);                                    IADDIU(&VI12, &VI00, 0x8);
  MULw(_y, &VF26, &VF16, &VF03);                                    IADDIU(&VI06, &VI00, 0x100);
  MULx(_x, &VF26, &VF12, &VF20);                                    IADDIU(&VI07, &VI04, 0x0);
  ADDw(_y, &VF27, &VF02, &VF26);                                    IAND(&VI07, &VI07, &VI13);
  ADDz(_z, &VF27, &VF02, &VF26);                                    LQ(_xyzw, &VF16, 0x0, &VI06);
  ADDy(_w, &VF27, &VF02, &VF26);                                    LQ(_xyzw, &VF24, 0x200, &VI07);
  MULx(_x, &VF27, &VF01, &VF26);                                    SQ(_yzw, &VF26, 0xC, &VI05);
                                                                    SQ(_x, &VF26, 0x0, &VI05);
                                                                    SQ(_x, &VF02, 0x4, &VI05);

                                                                    SQ(_yzw, &VF27, 0xB, &VI05);
                                                                    SQ(_x, &VF27, 0x8, &VI05);
                                                                    IADDIU(&VI07, &VI04, 0x18);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF17, 0x8, &VI06);
  MULA(_xyzw, &VF24, &VF16);                                        LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x20);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF16, 0x10, &VI06);
while (VI12.UL != VI00.UL) {
  MADDA(_xyzw, &VF25, &VF17);                                       LQ(_xyzw, &VF24, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x38);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF17, 0x18, &VI06);
  MADDA(_xyzw, &VF24, &VF16);                                       LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x40);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF16, 0x20, &VI06);
  MADDA(_xyzw, &VF25, &VF17);                                       LQ(_xyzw, &VF24, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x58);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF17, 0x28, &VI06);
  MADDA(_xyzw, &VF24, &VF16);                                       LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x60);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF16, 0x30, &VI06);
  MADDA(_xyzw, &VF25, &VF17);                                       LQ(_xyzw, &VF24, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x78);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF17, 0x38, &VI06);
  MADDA(_xyzw, &VF24, &VF16);                                       LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x80);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF16, 0x40, &VI06);
  MADDA(_xyzw, &VF25, &VF17);                                       LQ(_xyzw, &VF24, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x98);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF17, 0x48, &VI06);
  MADDA(_xyzw, &VF24, &VF16);                                       LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0xA0);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF16, 0x50, &VI06);
  MADDA(_xyzw, &VF25, &VF17);                                       LQ(_xyzw, &VF24, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0xB8);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF17, 0x58, &VI06);
  MADDA(_xyzw, &VF24, &VF16);                                       LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0xC0);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF16, 0x60, &VI06);
  MADDA(_xyzw, &VF25, &VF17);                                       LQ(_xyzw, &VF24, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0xD8);
                                                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF17, 0x68, &VI06);
  MADDA(_xyzw, &VF24, &VF16);                                       LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0xE0);
  ADDw(_xyzw, &VF02, &VF00, &VF00);                                 IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF16, 0x70, &VI06);
  MADDA(_xyzw, &VF25, &VF17);                                       LQ(_xyzw, &VF24, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0xF8);
  MULw(_w, &VF02, &VF00, &VF00);                                    IAND(&VI07, &VI07, &VI13);
                                                                    LQ(_xyzw, &VF17, 0x78, &VI06);
  MADDA(_xyzw, &VF24, &VF16);                                       LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    LOI(0.5);
  MULi(_xyzw, &VF02, &VF02);                                        IADDIU(&VI08, &VI00, 0x80);
                                                                    IADDIU(&VI09, &VI00, 0x40);
  MADD(_xyzw, &VF01, &VF25, &VF17);                                 IADDIU(&VI10, &VI00, 0x20);
                                                                    IADDIU(&VI11, &VI00, 0x10);
                                                                    LQ(_xyzw, &VF03, 0x0, &VI00);
                                                                    IADDIU(&VI03, &VI00, 0xF0);
                                                                    FMAND(&VI03, &VI03);
                                                                    IAND(&VI08, &VI08, &VI03);
                                                                    IADDI(&VI04, &VI04, 0x1);
                                                                    IADDI(&VI06, &VI06, 0x1);
if (VI08.UL != VI00.UL) {
  SUBw(_x, &VF02, &VF02, &VF00);
}
  MUL(_xyzw, &VF01, &VF01, &VF03);                                  IAND(&VI09, &VI09, &VI03);
                                                                    IADDIU(&VI07, &VI04, 0x0);
                                                                    IAND(&VI07, &VI07, &VI13);
if (VI09.UL != VI00.UL) {
  SUBw(_y, &VF02, &VF02, &VF00);
}
                                                                    IAND(&VI10, &VI10, &VI03);
                                                                    LQ(_xyzw, &VF16, 0x0, &VI06);
                                                                    LQ(_xyzw, &VF24, 0x200, &VI07);
if (VI10.UL != VI00.UL) {
  SUBw(_z, &VF02, &VF02, &VF00);
}
                                                                    IAND(&VI11, &VI11, &VI03);
                                                                    IADDIU(&VI07, &VI04, 0x18);
                                                                    IAND(&VI07, &VI07, &VI13);
if (VI11.UL != VI00.UL) {
  SUBw(_w, &VF02, &VF02, &VF00);
}
                                                                    LQ(_xyzw, &VF17, 0x8, &VI06);
  MULA(_xyzw, &VF24, &VF16);                                        LQ(_xyzw, &VF25, 0x200, &VI07);
                                                                    IADDIU(&VI07, &VI04, 0x20);
  ADD(_xyzw, &VF01, &VF01, &VF02);                                  IAND(&VI07, &VI07, &VI13);
                                                                    IADDI(&VI12, &VI12, 0x1F);
                                                                    LQ(_xyzw, &VF16, 0x10, &VI06);
                                                                    SQI(_xyzw, &VF01, &VI01);
}
                                                                    IADDI(&VI15, &VI15, 0x1F);

                                                                    LOI(32767);
}
  ADDi(_xyzw, &VF01, &VF00);                                        IADDIU(&VI01, &VI00, 0x300);
                                                                    IADDIU(&VI02, &VI00, 0x300);
                                                                    IADDIU(&VI03, &VI00, 0x20);
                                                                    LOI(-32768);
  SUBw(_w, &VF01, &VF01, &VF00);                                    LQI(_xyzw, &VF08, &VI01);


                                                                    LQI(_xyzw, &VF09, &VI01);
  MINI(_xyzw, &VF08, &VF08, &VF01);
  MAXi(_xyzw, &VF08, &VF08);
                                                                    LQI(_xyzw, &VF10, &VI01);
  MINI(_xyzw, &VF09, &VF09, &VF01);
  MAXi(_xyzw, &VF09, &VF09);
  FTOI0(_xyzw, &VF08, &VF08);                                       LQI(_xyzw, &VF11, &VI01);
  MINI(_xyzw, &VF10, &VF10, &VF01);
while (VI03.UL != VI00.UL) {
  MAXi(_xyzw, &VF10, &VF10);
  FTOI0(_xyzw, &VF09, &VF09);                                       LQI(_xyzw, &VF12, &VI01);
  MINI(_xyzw, &VF11, &VF11, &VF01);                                 SQI(_xyzw, &VF08, &VI02);
  MAXi(_xyzw, &VF11, &VF11);
  FTOI0(_xyzw, &VF10, &VF10);                                       LQI(_xyzw, &VF13, &VI01);
  MINI(_xyzw, &VF12, &VF12, &VF01);                                 SQI(_xyzw, &VF09, &VI02);
  MAXi(_xyzw, &VF12, &VF12);
  FTOI0(_xyzw, &VF11, &VF11);                                       LQI(_xyzw, &VF14, &VI01);
  MINI(_xyzw, &VF13, &VF13, &VF01);                                 SQI(_xyzw, &VF10, &VI02);
  MAXi(_xyzw, &VF13, &VF13);
  FTOI0(_xyzw, &VF12, &VF12);                                       LQI(_xyzw, &VF15, &VI01);
  MINI(_xyzw, &VF14, &VF14, &VF01);                                 SQI(_xyzw, &VF11, &VI02);
  MAXi(_xyzw, &VF14, &VF14);
  FTOI0(_xyzw, &VF13, &VF13);                                       LQI(_xyzw, &VF08, &VI01);
  MINI(_xyzw, &VF15, &VF15, &VF01);                                 SQI(_xyzw, &VF12, &VI02);
  MAXi(_xyzw, &VF15, &VF15);
  FTOI0(_xyzw, &VF14, &VF14);                                       LQI(_xyzw, &VF09, &VI01);
  MINI(_xyzw, &VF08, &VF08, &VF01);                                 SQI(_xyzw, &VF13, &VI02);
  MAXi(_xyzw, &VF08, &VF08);                                        IADDI(&VI03, &VI03, 0x1F);
  FTOI0(_xyzw, &VF15, &VF15);                                       LQI(_xyzw, &VF10, &VI01);
  MINI(_xyzw, &VF09, &VF09, &VF01);                                 SQI(_xyzw, &VF14, &VI02);
  MAXi(_xyzw, &VF09, &VF09);                                        LQI(_xyzw, &VF11, &VI01);
  FTOI0(_xyzw, &VF08, &VF08);
  MINI(_xyzw, &VF10, &VF10, &VF01);                                 SQI(_xyzw, &VF15, &VI02);
}
}

static uint8_t hist_data[2][0x1000] = { 0 };

/*
 * 0~3: "Sac" master volume
 * 4~F: unused / insignificant
 */
static uint8_t header[16] = { 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

int32_t *vu1_decode(int16_t *huffman_out, size_t huffman_outcnt, uint8_t ch)
{
  /*
   * For the Huffman-decoded data, we need to simulate a VIFcode UNPACK (V4-16)
   * to copy 16-bit -> 32-bit values into VUMem1 byte-address 0x1000. Other data
   * being copied into VUMem1 is constant and has already been unpacked as needed
   */
  memcpy(&VUMem1[0x100], header, sizeof(header));
  for (unsigned int a=0, b=0; a < huffman_outcnt; a+=4, b+=1) {
    VUMem1[0x101+b].SL[0] = huffman_out[a+0];
    VUMem1[0x101+b].SL[1] = huffman_out[a+1];
    VUMem1[0x101+b].SL[2] = huffman_out[a+2];
    VUMem1[0x101+b].SL[3] = huffman_out[a+3];
  }
  memcpy(&VUMem1[0x1F0], VU1_MPG_6E0_TBL_1F0, sizeof(VU1_MPG_6E0_TBL_1F0));
  memcpy(&VUMem1[0x200], VU1_MPG_6E0_TBL_200, sizeof(VU1_MPG_6E0_TBL_200));
  SUB_6E0();

  memcpy(&VUMem1[0x300], VU1_MPG_1410_TBL_300, sizeof(VU1_MPG_1410_TBL_300));
  SUB_1410();

  memcpy(&VUMem1[0x100], VU1_MPG_1690_TBL_100, sizeof(VU1_MPG_1690_TBL_100));
  memcpy(&VUMem1[0x140], VU1_MPG_1690_TBL_140, sizeof(VU1_MPG_1690_TBL_140));
  memcpy(&VUMem1[0x180], VU1_MPG_1690_TBL_180, sizeof(VU1_MPG_1690_TBL_180));
  memcpy(&VUMem1[0x200], &hist_data[ch], sizeof(hist_data[ch]));
  SUB_1690();
  memcpy(&hist_data[ch], &VUMem1[0x200], sizeof(hist_data[ch]));

  /* Decoded data (32-bit values) is stored in VUMem1 at byte-address 0x3000 */
  return (int32_t*)(&VUMem1[0x300]);
}
