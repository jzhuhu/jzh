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
BYTE WriteBuffer[]="贾笑笑真的很厉害";
uint32_t FlashID;
int main()
{
	FRESULT res_flash;
	LED_GPIO_Config();
	LED_YELLOW
	USART_Config();
	printf("贾笑笑的Test:\r\n");
	res_flash=f_mount(&fs,"1:",1);
	if(res_flash==FR_NO_FILESYSTEM)
	{
		printf("没有文件系统，需要进行格式化\r\n");
		res_flash=f_mkfs("1:",0,work,sizeof(work));
		printf("28  %d",res_flash);
		if(res_flash==FR_OK)
		{
			printf("Flash已经被格式化\r\n");
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
		printf("文件挂载成功\r\n");
	}
	printf("要进行文件写入啦(%d)\r\n",res_flash);
	res_flash=f_open(&fnew,"1:Fatfs.txt",FA_CREATE_ALWAYS | FA_WRITE);
	LED_PUERLE
	if(res_flash==FR_OK)
	{
		printf("文件创建成功\r\n");
		res_flash=f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
		if(res_flash==FR_OK)
		{
			LED_GREEN
			printf("写入数据成功！\r\n");
		}
		else
		{
			LED_RED
			printf("文件写入失败(%d)\r\n",res_flash);
		}
	}
	f_close(&fnew);
	res_flash=f_mount(NULL,"1:",1);
}

