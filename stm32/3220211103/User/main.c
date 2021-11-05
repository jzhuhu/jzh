#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_dma.h"
extern	const uint32_t aSRC_Const_Buffer[BUFFER_SIZE];
extern	uint32_t aDST_Buffer[BUFFER_SIZE];

void Delay(uint32_t time)
{
	for(;time>2;time--);
}
int main()
{
	uint8_t TransferStayus;
	LED_GPIO_Config();
	LED_PUERLE
	Delay(0xffffff);
	DMA_Config();
	while(DMA_GetFlagStatus(DMA_FLAG_TC)==RESET)
	{
		TransferStayus=Buffercmp(aSRC_Const_Buffer,aDST_Buffer,BUFFER_SIZE);
		if(TransferStayus==0)
		{
			LED_RED
		}
		else
		{
			LED_GREEN
		}
		while(1);
		}
}
