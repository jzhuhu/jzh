#include "bsp_dma.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include <stdio.h>
uint8_t SendBuff[SENDBUFF_SIZE];
void USART_Config()
{
	//定义初始化结构体名称
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef	GPIO_InitStructure;
	//GPIO CLOCK
	DEBUG_USART_GPIO_APBxClkCmd(DEBUG_USART_GPIO_CLK,ENABLE);
	//USART CLOCK
	DEBUG_USART_APBxClkCmd(DEBUG_USART_CLK,ENABLE);
	//GPIO TX
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT,&GPIO_InitStructure);
	//GPIO RX
	GPIO_InitStructure.GPIO_Pin=DEBUG_USART_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT,&GPIO_InitStructure);
	//configrate usart
	USART_InitStructure.USART_BaudRate=DEBUG_USART_BAUDRATE;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Init(DEBUG_USARTx,&USART_InitStructure);	
	USART_Cmd(DEBUG_USARTx, ENABLE);
}

//send a byte
void SendByte(USART_TypeDef * pUSARTx, uint8_t ch)
{
	USART_SendData(pUSARTx,ch);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET);
}
//send array
void Usart_SendArray(USART_TypeDef * pUSARTx,uint8_t *array, uint16_t num)
{
	uint8_t i=0;
	for(;i<num;i++)
	{
		USART_SendData(pUSARTx,array[i]);
	}
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}
//send strings
void Usart_SendString( USART_TypeDef * pUSARTx, char *str)
{
	while(*str!='\0')
	{
		SendByte(pUSARTx,*str++);
	}
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET);
}
//send 16bit num
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch)
{
	uint8_t temp_h, temp_l;
	temp_h = (ch&0XFF00)>>8;
	temp_l = ch&0XFF;
	
	USART_SendData(pUSARTx,temp_h);	
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
	USART_SendData(pUSARTx,temp_l);	
	while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);	
}
//print
int fputc(int ch,FILE *f)
{
	USART_SendData(DEBUG_USARTx,(uint8_t)ch);
	while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_TXE) == RESET);
	return ch;
}
//scanf
int fgetc(FILE *f)
{
				while (USART_GetFlagStatus(DEBUG_USARTx, USART_FLAG_RXNE) == RESET);

				return (int)USART_ReceiveData(DEBUG_USARTx);
}


void DMA_Config()
{

	DMA_InitTypeDef DMA_InitStructure;
	//open clock
	RCC_AHBPeriphClockCmd(DMA_CLOCK,ENABLE);
	//Periph base addr
	DMA_InitStructure.DMA_PeripheralBaseAddr=USART_DR_ADDRESS;
	//memory base addr
	DMA_InitStructure.DMA_MemoryBaseAddr=(uint32_t)SendBuff;
	//dirct
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralDST;
	//tralate buffersize 
	DMA_InitStructure.DMA_BufferSize=SENDBUFF_SIZE;
	//memory increase
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;
	//periph increase
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralInc_Disable;
	//cofig periph size =32
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Word;
	//cofig memory size=32
	DMA_InitStructure.DMA_MemoryDataSize=DMA_PeripheralDataSize_Byte;
	//mode set
	DMA_InitStructure.DMA_Mode=DMA_Mode_Normal;
	//priority
	DMA_InitStructure.DMA_Priority=DMA_Priority_Medium;
	//config m2m
	DMA_InitStructure.DMA_M2M=DMA_M2M_Disable;
	//Initializes the DMA
	DMA_Init(USART_TX_DMA_CHANNEL,&DMA_InitStructure);
	//Enables the specified DMA1 Channel6
	DMA_Cmd(USART_TX_DMA_CHANNEL,ENABLE);


}


