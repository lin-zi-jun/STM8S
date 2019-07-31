#include "stm8s.h"
#include "main.h"
#include "stdio.h"

void main(void)
{

  /* system_clock / 1 */
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  
  UART1_DeInit();
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
              UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
	
  I2C_DeInit();
  I2C_Init(100000, 0x50, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT, 16);           
  I2C_ITConfig((I2C_IT_TypeDef)(I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF), ENABLE);
  enableInterrupts();

  int i = 0,j=0;
  while (1)
  {
    i=10;
    j=10;
    while(i--)
    while(j--);
    //UART1_SendData8('-');
  }
}


#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{

  while (1)
  {}
}
#endif

