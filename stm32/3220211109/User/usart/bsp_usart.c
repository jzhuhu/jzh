#include "bsp_usart.h"
#include "misc.h"
#include "stm32f10x_usart.h"
#include "stdio.h"
//static void NVIC_Configuration()
//{
//	NVIC_InitTypeDef NVIC_InitStructure;
//	//cofigurate nvic group
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
//	//配置中断源
//	NVIC_InitStructure.NVIC_IRQChannel=DEBUG_USART_IRQ;
//	//配置抢占优先级
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//	//配置子优先级
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
//	//使能中断
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	//初始化NVIC
//	NVIC_Init(&NVIC_InitStructure);
//}
void USART_Config()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//打开GPIO的时钟
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);
	//打开usart1的时钟
	DEBUG_USART_APBxCLKCmd(DEBUG_USART_CLK,ENABLE);	
	//TX pin
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_TX_GPIO_PIN;
	//复用输出
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	//设置输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);
	
	//RX pin
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_RX_GPIO_PIN;
	//浮空输入
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
	//115200的波特率
	USART_InitStructure.USART_BaudRate=DEBUG_USART_BAUDRATE;
	//不使用硬件流
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	//模式为手法一起
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	//没有校验位
	USART_InitStructure.USART_Parity=USART_Parity_No;
	//只有一位停止位
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	//初始化usart
	USART_Init(DEBUG_USARTx,&USART_InitStructure);
	//串口中断优先级配置
//	NVIC_Configuration();
	//使能串口接收中断
//	USART_ITConfig(DEBUG_USARTx,USART_IT_RXNE,ENABLE);
	//使能串口
	USART_Cmd(DEBUG_USARTx,ENABLE);	
}
//发送字符
void Usart_SendByte(USART_TypeDef *pUSARTx,uint8_t ch)
{
	USART_SendData(pUSARTx,ch);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);
}

//发送字符串
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
