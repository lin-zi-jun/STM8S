/**
  **********************************  STM8S  ***********************************
  * @�ļ���     �� main.c
  * @����       �� strongerHuang
  * @��汾     �� V2.2.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2017��04��10��
  * @ժҪ       �� ������ - Demo�������
  ******************************************************************************/
/*----------------------------------------------------------------------------
  ������־:
  2017-04-10 V1.0.0:��ʼ�汾
  ----------------------------------------------------------------------------*/
/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "bsp.h"
#include "bsp_timer.h"
#include "bsp_uart.h"


/************************************************
�������� �� System_Initializes
��    �� �� ϵͳ��ʼ��
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void System_Initializes(void)
{
  BSP_Initializes();
  TIMER_Initializes();
  UART_Initializes();
}

/************************************************
�������� �� main
��    �� �� ���������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void main(void)
{
  System_Initializes();

  while(1)
  {
    LED_ON;                                      //LED��
    TIMDelay_Nms(500);
    LED_OFF;                                     //LED��
    TIMDelay_Nms(500);

    UART1_Printf((uint8_t*)"Demo...");           //���ڴ�ӡ(���)����
  }
}


#ifdef USE_FULL_ASSERT                           //����(�ο��ٷ�)

void assert_failed(u8* file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/**** Copyright (C)2017 strongerHuang. All Rights Reserved **** END OF FILE ****/
