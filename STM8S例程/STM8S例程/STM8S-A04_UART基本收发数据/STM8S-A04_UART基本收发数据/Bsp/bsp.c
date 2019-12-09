/**
  **********************************  STM8S  ***********************************
  * @�ļ���     �� bsp.c
  * @����       �� strongerHuang
  * @��汾     �� V2.2.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2017��04��10��
  * @ժҪ       �� �弶֧�ְ�Դ�ļ�
  ******************************************************************************/
/*----------------------------------------------------------------------------
  ������־:
  2017-04-10 V1.0.0:��ʼ�汾
  ----------------------------------------------------------------------------*/
/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "bsp.h"


/************************************************
�������� �� CLK_Configuration
��    �� �� ʱ������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void CLK_Configuration(void)
{
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); //HSI = 16M (1��Ƶ)
}

/************************************************
�������� �� GPIO_Configuration
��    �� �� ����IO��������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void GPIO_Configuration(void)
{
  GPIO_Init(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PIN, GPIO_MODE_OUT_PP_LOW_FAST);

#if 0 
  /* ϵͳʱ����� */
  GPIO_Init(GPIOC, (GPIO_Pin_TypeDef)GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_FAST);
  CLK_CCOCmd(ENABLE);
#endif
}

/************************************************
�������� �� BSP_Initializes
��    �� �� �弶֧�ְ���ʼ��
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void BSP_Initializes(void)
{
  CLK_Configuration();
  GPIO_Configuration();
}


/**** Copyright (C)2017 strongerHuang. All Rights Reserved **** END OF FILE ****/
