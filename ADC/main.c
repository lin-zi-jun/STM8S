#include "stm8s.h"

uint16_t Conversion_Value = 0;
static void ADC_Config(void);

void main(void)
{
  ADC_Config();
  while (1);
}

static void ADC_Config()
{
  GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT);
  ADC1_DeInit();
  ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_PRESSEL_FCPU_D2, \
            ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, ADC1_SCHMITTTRIG_CHANNEL3,\
            DISABLE);
  ADC1_ITConfig(ADC1_IT_AWS3,ENABLE);
  enableInterrupts();
  ADC1_StartConversion();
}
 
#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{ 

  while (1)
  {
  }
}
#endif

