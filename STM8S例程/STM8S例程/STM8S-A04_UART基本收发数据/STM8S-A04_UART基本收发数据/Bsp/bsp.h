/**
  **********************************  STM8S  ***********************************
  * @�ļ���     �� bsp.h
  * @����       �� strongerHuang
  * @��汾     �� V2.2.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2017��04��10��
  * @ժҪ       �� �弶֧�ְ�ͷ�ļ�
  ******************************************************************************/

/* �����ֹ�ݹ���� ----------------------------------------------------------*/
#ifndef _BSP_H
#define _BSP_H

/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "stm8s.h"


/* �궨�� --------------------------------------------------------------------*/
#define LED_GPIO_PORT             GPIOD
#define LED_GPIO_PIN              GPIO_PIN_4

/* LED */
#define LED_ON                    GPIO_WriteHigh(LED_GPIO_PORT, LED_GPIO_PIN)
#define LED_OFF                   GPIO_WriteLow(LED_GPIO_PORT, LED_GPIO_PIN)
#define LED_REVERSE               GPIO_WriteReverse(LED_GPIO_PORT, LED_GPIO_PIN)


/* �������� ------------------------------------------------------------------*/
void CLK_Configuration(void);
void GPIO_Configuration(void);
void BSP_Initializes(void);


#endif /* _BSP_H */

/**** Copyright (C)2017 strongerHuang. All Rights Reserved **** END OF FILE ****/
