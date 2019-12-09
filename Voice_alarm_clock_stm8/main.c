#include "stm8s.h"
#include "uart.h"
#include <stdarg.h>
#include <tm1652.h>

int i =5 ;
char str[10];

void main(void)
{
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); 
  UART_Initializes();

  SHUMAGUAN_Init();
  
  while( 1 )
  {
        
    
     for(int i=1;i<6;i++){
    
           INT_printf(2);
           backlight(1,i);
           display(0,1,0);
           display(0,2,0);
           display(0,3,0);
           display(0,4,0);
           Delay(100000);
     }
     
     
     for(int i=1;i<8;i++){
    
           INT_printf(2);
           backlight(15,i);
           display(0,1,0);
           display(0,2,0);
           display(0,3,0);
           display(0,4,0);
           Delay(100000);
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

