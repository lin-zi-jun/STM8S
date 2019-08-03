#include "stm8s.h"
#include "uart.h"
#include <stdarg.h>

int i =5 ;
char str[10];
void main(void)
{
  uint16_t num;
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); 
  UART1_DeInit();
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
              UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  while (1)
  {
      num = 65112;
      INT_printf(num);
       SendrStr("\r\n");
  }
}

#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{ 
  while (1)
  {
  }
}
#endif

