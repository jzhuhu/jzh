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
BYTE ReadBuffer[1024]={0};
BYTE WriteBuffer[]="贾笑笑真的很厉害";
int main()
{
//	LED_GPIO_Config();
//	LED_RED
//	USART_Config();
//	printf("This is SPI TEST\n");
//	res_flash=f_mount(&fs,"1:",1);
//	if(res_flash==FR_NO_FILESYSTEM)
//	{
//		printf("没有文件系统，需要进行格式化(%d)\r\n",res_flash);
//		res_flash=f_mkfs("1:",0,0);
//		printf("格式化返回 %d",res_flash);
//		if(res_flash==FR_OK)
//		{
//			printf("Flash已经被格式化\r\n");
//			LED_BLUE
//			res_flash=f_mount(NULL,"1:",1);
//			printf("res_flash=%d",res_flash);
//			res_flash=f_mount(&fs,"1:",1);
//			printf("res_flash=%d",res_flash);
//		}
//		else
//		{
//			LED_RED
//			printf("格式化失败= %d",res_flash);
//			while(1);
//		}
//	}
//	else if(res_flash!=FR_OK)
//  {
//    printf("！！外部Flash挂载文件系统失败。(%d)\r\n",res_flash);
//    printf("！！可能原因：SPI Flash初始化不成功。\r\n");
//		while(1);
//  }
//  else
//  {
//    printf("》文件系统挂载成功，可以进行读写测试\r\n");
//  }
//	printf("要进行文件写入啦(%d)\r\n",res_flash);
//	res_flash=f_open(&fnew,"1:Fatfs.txt",FA_CREATE_ALWAYS | FA_WRITE);
//	LED_PUERLE
//	if(res_flash==FR_OK)
//	{
//		printf("文件创建成功\r\n");
//		res_flash=f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
//		if(res_flash==FR_OK)
//		{
//			LED_GREEN
//			printf("写入数据成功！\r\n");
//		}
//		else
//		{
//			LED_RED
//			printf("文件写入失败(%d)\r\n",res_flash);
//		}
//	}
//	f_close(&fnew);
//	res_flash=f_mount(NULL,"1:",1);
	/* 初始化LED */
	LED_GPIO_Config();	
	LED_BLUE;
	
	/* 初始化调试串口，一般为串口1 */
	USART_Config();	
  printf("****** 这是一个SPI FLASH 文件系统实验 ******\r\n");
  
	//在外部SPI Flash挂载文件系统，文件系统挂载时会对SPI设备初始化
	//初始化函数调用流程如下
	//f_mount()->find_volume()->disk_initialize->SPI_FLASH_Init()
	res_flash = f_mount(&fs,"1:",1);
	
/*----------------------- 格式化测试 -----------------*/  
	/* 如果没有文件系统就格式化创建创建文件系统 */
	if(res_flash == FR_NO_FILESYSTEM)
	{
		printf("》FLASH还没有文件系统，即将进行格式化...\r\n");
    /* 格式化 */
		res_flash=f_mkfs("1:",0,0);							
		
		if(res_flash == FR_OK)
		{
			printf("》FLASH已成功格式化文件系统。\r\n");
      /* 格式化后，先取消挂载 */
			res_flash = f_mount(NULL,"1:",1);			
      /* 重新挂载	*/			
			res_flash = f_mount(&fs,"1:",1);
		}
		else
		{
			LED_RED;
			printf("《《格式化失败。》》\r\n");
			while(1);
		}
	}
  else if(res_flash!=FR_OK)
  {
    printf("！！外部Flash挂载文件系统失败。(%d)\r\n",res_flash);
    printf("！！可能原因：SPI Flash初始化不成功。\r\n");
		while(1);
  }
  else
  {
    printf("》文件系统挂载成功，可以进行读写测试\r\n");
  }
  
/*----------------------- 文件系统测试：写测试 -------------------*/
	/* 打开文件，每次都以新建的形式打开，属性为可写 */
	printf("\r\n****** 即将进行文件写入测试... ******\r\n");	
	res_flash = f_open(&fnew, "1:FatFs.txt",FA_CREATE_ALWAYS | FA_WRITE );
	if ( res_flash == FR_OK )
	{
		printf("》打开/创建FatFs读写测试文件.txt文件成功，向文件写入数据。\r\n");
    /* 将指定存储区内容写入到文件内 */
		res_flash=f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
    if(res_flash==FR_OK)
    {
      printf("》文件写入成功，写入字节数据：%d\n",fnum);
      printf("》向文件写入的数据为：\r\n%s\r\n",WriteBuffer);
    }
    else
    {
      printf("！！文件写入失败：(%d)\n",res_flash);
    }    
		/* 不再读写，关闭文件 */
    f_close(&fnew);
	}
	else
	{	
		LED_RED;
		printf("！！打开/创建文件失败。\r\n");
	}
	
	
	
}
