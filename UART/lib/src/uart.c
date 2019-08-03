#include "uart.h"
#include <stdarg.h>
#include "stm8s.h"


#define KB2ASC(x)	 (u8)(0x30+x)
#define ASC2KB(x)	 (u8)(x%(0x30))

void SendrStr(const  char *ptr)
{
    do
    {
	UART1_SendData8(*ptr);
        while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);		
    }while(*ptr++!='\0');	
}




int CharToInt(char cIn)
{
        int nRet = cIn;

        if(nRet > 47 && nRet < 58)
                nRet -= 48;
        else if (nRet > 64 && nRet < 71)
                nRet -= 55;
        else if (nRet > 96 && nRet < 103)
                nRet -= 87;
        else
                nRet = 0;

        return nRet;
}

