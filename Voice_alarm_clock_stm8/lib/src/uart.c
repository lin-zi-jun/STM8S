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
      SendrStr("\r\n");
}

void UART_Initializes(void)
{
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  UART1_Cmd(ENABLE);
  UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);

  enableInterrupts();
}

/**
  * @brief UART1 RX Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
{
  uint8_t temp;

  temp = UART1_ReceiveData8();                   //读取接收到的数据(该操作会自动清除中断接收标志)
  UART1_SendData8(temp);                         //发送接收到的数据
}


