#include "stm8s.h"
#include "uart.h"

uint16_t Conversion_Value = 0;


void InitAD(uint8_t channel)
{
  ADC1_DeInit();
  ADC1_Init(ADC1_CONVERSIONMODE_SINGLE,
            (ADC1_Channel_TypeDef)channel,
            ADC1_PRESSEL_FCPU_D18,
            ADC1_EXTTRIG_TIM,
            DISABLE,
            ADC1_ALIGN_RIGHT,
            (ADC1_SchmittTrigg_TypeDef)channel,
            DISABLE);
}
 
void AD_Start(void)
{
  ADC1_ScanModeCmd(ENABLE);
  ADC1_DataBufferCmd(ENABLE);
  ADC1_Cmd(ENABLE);
  ADC1_StartConversion();
}
 
uint16_t getADCValue(uint8_t channel)
{
  InitAD(channel);
  AD_Start();
  while(ADC1_GetFlagStatus(ADC1_FLAG_EOC) == RESET);
  return ADC1_GetConversionValue();
}

void main(void)
{
    uint16_t Adc_Val=0,i=0;
    char buf[10]={0};
    UART1_DeInit();
    UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
                                UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  while (1){
    
   //Adc_Val = getADCValue(ADC1_SCHMITTTRIG_CHANNEL3);
    int nValue=1234;
    buf[0]  = nValue/1000+0x30; 
    buf[1]  = (nValue%1000)+0x30; 
    buf[2]  = (nValue%100)+0x30; 
    buf[3]  = nValue%10+0x30;
    
   SendrStr(buf);
   SendrStr("\r\n");
   i=100000;
   while(i--);
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

