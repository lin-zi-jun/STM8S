#ifndef _UART_H
#define _UART_H
#include "stm8s.h"

u8 RingBufRead(u8 *pData);
void UART_Initializes(void);
void SendrStr(const  char *ptr);
void INT_printf(long num);
u8 PCCmdHandler(u8 *pBuf);

#endif 

