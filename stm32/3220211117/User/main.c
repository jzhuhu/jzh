#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_spi_flash.h"
#include <stdio.h>
#include "bsp_spi_flash.h"
uint32_t FlashID;
uint8_t Buff[500];
uint8_t ReadBuff[500];
int main()
{
	uint16_t i;
	LED_GPIO_Config();
	LED_RED
	USART_Config();
	printf("This is SPI TEST\n");
	SPI_FLASH_Init();
	FlashID=SPI_FLASH_ReadID();
	printf("FlashID is 0x%x\n",FlashID);
	for(i=0;i<500;i++)
	{
		Buff[i]=5;
	}
	SPI_FLASH_SectorErase(0x00);
	SPI_FLASH_BufferWrite(Buff,0x00,500);
	SPI_FLASH_BuffRead(ReadBuff,0x00,500);
	for(i=0;i<500;i++)
	{
		printf("0x%x ",ReadBuff[i]);
		if((i%16)==15)
		{
			printf("\n");
		}
	}		
}
