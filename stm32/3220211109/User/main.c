#include "stm32f10x.h"
#include "bsp_i2c_ee.h"
#include "bsp_led.h"
#include  "bsp_usart.h"
#include "bsp_i2c_ee.h"
#include <stdio.h>
#define EEP_Firstpage 0x00
uint8_t I2C_Test(void);
int main(void)
{
	LED_GPIO_Config();
	LED_BLUE
	USART_Config();
	printf("JzH\n");
	printf("This is a test:\n");
	I2C_EE_Init();
	if(I2C_Test()==1)
	{
		LED_GREEN
	}
	else
	{
		LED_RED
	}
	
	while(1);

}
//test function
uint8_t I2C_Test(void)
{
	uint16_t i;
	uint8_t I2C_Buf_Write[255];
	uint8_t I2C_Buf_Read[255];
	EEPROM_INFO("写入的数据\n");
	for(i=0;i<=255;i++)
		{
			I2C_Buf_Write[i]=i;
			printf("0x%02x ",I2C_Buf_Write[i]);
			if((i%16==15))
			{
				printf("\n");
			}
		}
	printf("\n");
	//I2C_EE_ByteWrite(&I2C_Buf_Write[3],EEP_Firstpage);
	//I2C_EE_BytesWrite(I2C_Buf_Write,EEP_Firstpage,8);
	//printf("0x%02x\n",I2C_Buf_Write[3]);
	I2C_EE_PageWrite(I2C_Buf_Write,EEP_Firstpage,8);	
	EEPROM_INFO("写结束了\n");
	EEPROM_INFO("读入的数据\n");
	I2C_EE_BufferRead(I2C_Buf_Read,EEP_Firstpage,8);
		for(i=0;i<8;i++)
		{
			printf("0x%02x ",I2C_Buf_Read[i]);
		}
	return 1;
}

