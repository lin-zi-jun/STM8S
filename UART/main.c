#include "stm8s.h"
#include "uart.h"

void main(void)
{

  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); 
  UART1_DeInit();
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
              UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  while (1)
  {
      SendrStr("1234567890\r\n");
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

