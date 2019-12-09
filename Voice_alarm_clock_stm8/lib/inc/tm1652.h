

#ifndef __TM1652_H
#define __TM1652_H
#include "stm8s_gpio.h"

#define TM1652_SDA  GPIO_PIN_4  //TM1651数据线
#define TM1652_GPIO GPIOD

#define TM1652_SDA_IN()  GPIO_Init(TM1652_GPIO, TM1652_SDA, GPIO_MODE_IN_PU_NO_IT);//上拉输入
#define TM1652_SDA_OUT() GPIO_Init(TM1652_GPIO, TM1652_SDA, GPIO_MODE_OUT_PP_HIGH_FAST);//输出2M
#define TM1652_GET_SDA() GPIO_ReadInputPin(TM1652_GPIO, TM1652_SDA)

#define NUM0 0
#define NUM1 1 
#define NUM2 2
#define NUM3 3
#define NUM4 4
#define NUM5 5 
#define NUM6 6
#define NUM7 7
#define NUM8 8
#define NUM9 9

#define NUMa 10  
#define NUMb 11
#define NUMc 12
#define NUMd 13
#define NUMe 14
#define NUMf 15

#define NUMg 16
#define NUMH 17
#define NUMi 18
#define NUML 19

#define NUMn 20
#define NUMo 21
#define NUMp 22
#define NUMr 23

#define NUMs 24
#define NUMt 25 
#define NUMu 26
#define NUMU 27

#define NUMx 28
#define NUMy 29

#define NUM_ 30





#define DISPLAY_H2()    display(NUMx,2,1)
#define UN_DISPLAY_H2() display(NUMx,2,0)

#define DISPLAY_H3()    display(NUMx,3,1)
#define UN_DISPLAY_H3() display(NUMx,3,0)

#define DISPLAY_H4()    display(NUMx,4,1)
#define UN_DISPLAY_H4() display(NUMx,4,0)

void TM1652_Set(u8 add,u8 dat);
void SHUMAGUAN_Init(void);
void display(u8 disnum,u8 disbit,u8 dotbit);
void Delay(uint32_t nCount);
void backlight(u8 i,u8 d);
#endif


