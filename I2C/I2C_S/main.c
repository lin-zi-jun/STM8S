#include "stm8s.h"
#include "main.h"
#include "stdio.h"
#include "uart.h"
#include <stdarg.h>

static void TIM2_Config(void)
{
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_1,255);
  TIM2_Cmd(ENABLE);
}

void T2_RGB_VAL(uint8_t R,uint8_t G,uint8_t B){
    
  TIM2_OC1Init(TIM2_OCMODE_PWM2, TIM2_OUTPUTSTATE_ENABLE,R,TIM2_OCPOLARITY_LOW); //PD4
  TIM2_OC2Init(TIM2_OCMODE_PWM2, TIM2_OUTPUTSTATE_ENABLE,G,TIM2_OCPOLARITY_LOW); //PD3
  TIM2_OC3Init(TIM2_OCMODE_PWM2, TIM2_OUTPUTSTATE_ENABLE,B,TIM2_OCPOLARITY_LOW); //PA3
}

int i=0,j=0;
void delay_ms(int ii){

  for(i=0;i<ii;i++){
    for(j=0;j<100;j++)
    {
    }
  }
  
}

int led_status;
extern __IO uint8_t T_buf;
 uint8_t red_led_val, blue_led_val, green_led_val;
void main(void)
{

  bool Flag;
  int i=0,j=0,k=0;
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  TIM2_Config();
  
  UART1_DeInit();
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
              UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
	
  I2C_DeInit();
  I2C_Init(100000, 0x50, I2C_DUTYCYCLE_2, I2C_ACK_CURR, I2C_ADDMODE_7BIT, 16);           
  I2C_ITConfig((I2C_IT_TypeDef)(I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF), ENABLE);
  enableInterrupts();


  while (1)
  {
    if(led_status==1){
      
         if(T_buf=='$'||Flag==1){
              Flag=1;
              if((T_buf!='$')&&(T_buf!='#')){
                  i++;
                  if(i==1){
                      red_led_val = T_buf;
                  }else if(i==2){
                      green_led_val = T_buf;
                  }
                  else if(i==3){
                      blue_led_val = T_buf;
                 }
              }
          }
         
          if(T_buf=='#'){
               Flag=0;
               i=0;
               T2_RGB_VAL(red_led_val,green_led_val,blue_led_val);
          }
          led_status=0;
      }
       T2_RGB_VAL(0,0,0);
       
  }
}


#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{

  while (1)
  {}
}
#endif

