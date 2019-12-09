/**
  **********************************  STM8S  ***********************************
  * @�ļ���     �� bsp_uart.c
  * @����       �� strongerHuang
  * @��汾     �� V2.2.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2017��04��10��
  * @ժҪ       �� UARTԴ�ļ�
  ******************************************************************************/
/*----------------------------------------------------------------------------
  ������־:
  2017-04-10 V1.0.0:��ʼ�汾
  ----------------------------------------------------------------------------*/
/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "bsp_uart.h"


/************************************************
�������� �� UART_Initializes
��    �� �� UART��ʼ��
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void UART_Initializes(void)
{
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  UART1_Cmd(ENABLE);
  UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);

  enableInterrupts();
}

/************************************************
�������� �� UART1_SendByte
��    �� �� UART1����һ���ַ�
��    �� �� Data --- ����
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void UART1_SendByte(uint8_t Data)
{
  while((UART1_GetFlagStatus(UART1_FLAG_TXE)==RESET));
  UART1_SendData8(Data);
  while((UART1_GetFlagStatus(UART1_FLAG_TC)==RESET));
}

/************************************************
�������� �� UART1_SendNByte
��    �� �� ����1����N���ַ�
��    �� �� pData ---- �ַ���
            Length --- ����
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void UART1_SendNByte(uint8_t *pData, uint16_t Length)
{
  while(Length--)
  {
    UART1_SendByte(*pData);
    pData++;
  }
}

/************************************************
�������� �� UART1_Printf
��    �� �� ����1��ӡ���
��    �� �� String --- �ַ���
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void UART1_Printf(uint8_t *String)
{
  while((*String) != '\0')
  {
    UART1_SendByte(*String);
    String++;
  }
}


/**** Copyright (C)2017 strongerHuang. All Rights Reserved **** END OF FILE ****/
