#include "uart.h"
#include <stdarg.h>
#include "stm8s.h"

void SendrStr(const  char *ptr)
{
    do
    {
	UART1_SendData8(*ptr);
        while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);		
    }while(*ptr++!='\0');	
}



int Bit_Int(long n)
{
	long bit=0;
	if(n==0)
		return 1;
	while(n)
	{
		bit++;
		n/=10;
	}
	return bit;
}

void INT_printf(long num){
      char buf[20]={0};
      int Bit = 0,i;
      long sum = 1,n1,n2;

      Bit = Bit_Int(num);
              
      for(i=1;i<Bit;i++){
              sum = sum*10;
      }

      buf[0]  = num/sum+0x30; 
      n1 = sum;
      n2 = sum/10;
      for(i=1;i<Bit;i++){
          buf[i]  = num%n1/n2+0x30;
          n1=n1/10;
          n2=n2/10; 
      }

      SendrStr(buf);
}

