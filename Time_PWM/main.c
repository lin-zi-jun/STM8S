#include "stm8s.h"

#define T1_CCR1_Val  ((uint16_t)100)
#define T1_CCR2_Val  ((uint16_t)100)
#define T1_CCR3_Val  ((uint16_t)100)
#define T2_CCR1_Val  ((uint16_t)100)
#define T2_CCR2_Val  ((uint16_t)100)
#define T2_CCR3_Val  ((uint16_t)100)

static void TIM1_Config(void);
static void TIM2_Config(void);
void T1_RGB_VAL(uint8_t R,uint8_t G,uint8_t B);
void T2_RGB_VAL(uint8_t R,uint8_t G,uint8_t B);
void delay_ms(int ii);

void main(void)
{
 // TIM1_Config();
  TIM2_Config();
  
  while (1)
  {
  
      T2_RGB_VAL(0,0,255);
      delay_ms(1000);
     
      T2_RGB_VAL(0,255,0);
      delay_ms(1000);
  
      T2_RGB_VAL(255,0,0);
      delay_ms(1000);
  } 
}

static void TIM1_Config(void)
{

  TIM1_DeInit();
  TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP, 255, 0);
  TIM1_Cmd(ENABLE);
  TIM1_CtrlPWMOutputs(ENABLE);
}


static void TIM2_Config(void)
{
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_1,255);
  TIM2_Cmd(ENABLE);
}


void T1_RGB_VAL(uint8_t R,uint8_t G,uint8_t B){
    
   TIM1_OC1Init(TIM1_OCMODE_PWM2, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_ENABLE,   //
                R, TIM1_OCPOLARITY_LOW, TIM1_OCNPOLARITY_HIGH, TIM1_OCIDLESTATE_SET,
               TIM1_OCNIDLESTATE_RESET); 

  TIM1_OC2Init(TIM1_OCMODE_PWM2, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_ENABLE, 
                G,TIM1_OCPOLARITY_LOW, TIM1_OCNPOLARITY_HIGH, TIM1_OCIDLESTATE_SET, 
               TIM1_OCNIDLESTATE_RESET);

  TIM1_OC3Init(TIM1_OCMODE_PWM2, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_ENABLE,  //
                B, TIM1_OCPOLARITY_LOW, TIM1_OCNPOLARITY_HIGH, TIM1_OCIDLESTATE_SET,
               TIM1_OCNIDLESTATE_RESET);
}

void T2_RGB_VAL(uint8_t R,uint8_t G,uint8_t B){
    
  TIM2_OC1Init(TIM2_OCMODE_PWM2, TIM2_OUTPUTSTATE_ENABLE,R,TIM2_OCPOLARITY_LOW); 
  TIM2_OC2Init(TIM2_OCMODE_PWM2, TIM2_OUTPUTSTATE_ENABLE,G,TIM2_OCPOLARITY_LOW);
  TIM2_OC3Init(TIM2_OCMODE_PWM2, TIM2_OUTPUTSTATE_ENABLE,B,TIM2_OCPOLARITY_LOW);
}

int i=0,j=0;
void delay_ms(int ii){

  for(i=0;i<ii;i++){
    for(j=0;j<100;j++)
    {
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
