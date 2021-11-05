#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma.h"
#include <stdio.h>
extern uint8_t SendBuff[SENDBUFF_SIZE];

void Delay(uint32_t time)
{
	for(;time>2;time--);
}
int main()
{
		uint16_t i;
		LED_GPIO_Config();
		USART_Config();
		DMA_Config();
	for(i=0;i<SENDBUFF_SIZE;i++)
	{
		SendBuff[i]='X';
	}

	USART_DMACmd(DEBUG_USARTx,USART_DMAReq_Tx,ENABLE);
	while(1)
	{
		LED1_TOGGLE
    Delay(0xFFFFF);
	}
	//printf("hzjjj\n");
	//Usart_SendString(DEBUG_USARTx,"jzh\n");

}

