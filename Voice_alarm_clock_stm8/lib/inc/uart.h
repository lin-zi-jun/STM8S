#ifndef _UART_H
#define _UART_H
#include "stm8s.h"

void UART_Initializes(void);
void SendrStr(const  char *ptr);
void INT_printf(long num);

#endif 

