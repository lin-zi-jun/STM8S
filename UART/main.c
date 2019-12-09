#include "stm8s.h"
#include "uart.h"
#include <stdarg.h>

u8 str[10];
int i = 0;
void main(void)
{
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); 
  UART_Initializes();
  while (1)
  {
      while(RingBufRead(&str[i]) == 0){
         i++;
      }
      
      SendrStr(str);
      if(str[0]=='1'){
          SendrStr("1");
      }else if(str[0]=='2'){
        SendrStr("2");
      }
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

