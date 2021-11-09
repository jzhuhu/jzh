#include "bsp_usart.h"
#include "misc.h"
#include "stm32f10x_usart.h"
#include "stdio.h"
//static void NVIC_Configuration()
//{
//	NVIC_InitTypeDef NVIC_InitStructure;
//	//cofigurate nvic group
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
//	//�����ж�Դ
//	NVIC_InitStructure.NVIC_IRQChannel=DEBUG_USART_IRQ;
//	//������ռ���ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//	//���������ȼ�
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
//	//ʹ���ж�
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	//��ʼ��NVIC
//	NVIC_Init(&NVIC_InitStructure);
//}
void USART_Config()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//��GPIO��ʱ��
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);
	//��usart1��ʱ��
	DEBUG_USART_APBxCLKCmd(DEBUG_USART_CLK,ENABLE);	
	//TX pin
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_TX_GPIO_PIN;
	//�������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	//�������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);
	
	//RX pin
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_RX_GPIO_PIN;
	//��������
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
	//115200�Ĳ�����
	USART_InitStructure.USART_BaudRate=DEBUG_USART_BAUDRATE;
	//��ʹ��Ӳ����
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	//ģʽΪ�ַ�һ��
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	//û��У��λ
	USART_InitStructure.USART_Parity=USART_Parity_No;
	//ֻ��һλֹͣλ
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	//��ʼ��usart
	USART_Init(DEBUG_USARTx,&USART_InitStructure);
	//�����ж����ȼ�����
//	NVIC_Configuration();
	//ʹ�ܴ��ڽ����ж�
//	USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);
	//ʹ�ܴ���
	USART_Cmd(DEBUG_USARTx,ENABLE);	
}
//�����ַ�
void Usart_SendByte(USART_TypeDef *pUSARTx,uint8_t ch)
{
	USART_SendData(pUSARTx,ch);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);
}

//�����ַ���
void Usart_sendString(USART_TypeDef * pUSARTx,char *str)
{
	while(*str!='\0')
	{
		Usart_SendByte(pUSARTx,*str++);
	}
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}

int fputc(int ch,FILE *f)
{
	USART_SendData(DEBUG_USARTx,(uint8_t)	ch);
	while(USART_GetFlagStatus(DEBUG_USARTx,USART_FLAG_TXE)==RESET);
	return ch;
}

int fgetc(FILE *f)
{
	while(USART_GetFlagStatus(DEBUG_USARTx,USART_FLAG_RXNE)==RESET);
	return (int)USART_ReceiveData(DEBUG_USARTx);
}
