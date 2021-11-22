#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_spi_flash.h"
#include <stdio.h>
#include "bsp_spi_flash.h"
#include "ff.h"
FATFS fs;
FIL fnew;
FRESULT res_flash;
UINT fnum;
BYTE ReadBuffer[1024]=" ";
BYTE work[FF_MAX_SS];
BYTE WriteBuffer[]="��ЦЦ��ĺ�����";
uint32_t FlashID;
int main()
{
	FRESULT res_flash;
	LED_GPIO_Config();
	LED_YELLOW
	USART_Config();
	printf("��ЦЦ��Test:\r\n");
	res_flash=f_mount(&fs,"1:",1);
	if(res_flash==FR_NO_FILESYSTEM)
	{
		printf("û���ļ�ϵͳ����Ҫ���и�ʽ��\r\n");
		res_flash=f_mkfs("1:",0,work,sizeof(work));
		printf("28  %d",res_flash);
		if(res_flash==FR_OK)
		{
			printf("Flash�Ѿ�����ʽ��\r\n");
			LED_BLUE
			res_flash=f_mount(NULL,"1:",1);
			printf("34  %d",res_flash);
			res_flash=f_mount(&fs,"1:",1);
			printf("36  %d",res_flash);
		}
		else
			{
				LED_RED
				while(1);
			}
	}
	else
	{
		printf("�ļ����سɹ�\r\n");
	}
	printf("Ҫ�����ļ�д����(%d)\r\n",res_flash);
	res_flash=f_open(&fnew,"1:Fatfs.txt",FA_CREATE_ALWAYS | FA_WRITE);
	LED_PUERLE
	if(res_flash==FR_OK)
	{
		printf("�ļ������ɹ�\r\n");
		res_flash=f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
		if(res_flash==FR_OK)
		{
			LED_GREEN
			printf("д�����ݳɹ���\r\n");
		}
		else
		{
			LED_RED
			printf("�ļ�д��ʧ��(%d)\r\n",res_flash);
		}
	}
	f_close(&fnew);
	res_flash=f_mount(NULL,"1:",1);
}

