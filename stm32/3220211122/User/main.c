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
BYTE WriteBuffer[]="��ЦЦ��ĺ�����";
int main()
{
//	LED_GPIO_Config();
//	LED_RED
//	USART_Config();
//	printf("This is SPI TEST\n");
//	res_flash=f_mount(&fs,"1:",1);
//	if(res_flash==FR_NO_FILESYSTEM)
//	{
//		printf("û���ļ�ϵͳ����Ҫ���и�ʽ��(%d)\r\n",res_flash);
//		res_flash=f_mkfs("1:",0,0);
//		printf("��ʽ������ %d",res_flash);
//		if(res_flash==FR_OK)
//		{
//			printf("Flash�Ѿ�����ʽ��\r\n");
//			LED_BLUE
//			res_flash=f_mount(NULL,"1:",1);
//			printf("res_flash=%d",res_flash);
//			res_flash=f_mount(&fs,"1:",1);
//			printf("res_flash=%d",res_flash);
//		}
//		else
//		{
//			LED_RED
//			printf("��ʽ��ʧ��= %d",res_flash);
//			while(1);
//		}
//	}
//	else if(res_flash!=FR_OK)
//  {
//    printf("�����ⲿFlash�����ļ�ϵͳʧ�ܡ�(%d)\r\n",res_flash);
//    printf("��������ԭ��SPI Flash��ʼ�����ɹ���\r\n");
//		while(1);
//  }
//  else
//  {
//    printf("���ļ�ϵͳ���سɹ������Խ��ж�д����\r\n");
//  }
//	printf("Ҫ�����ļ�д����(%d)\r\n",res_flash);
//	res_flash=f_open(&fnew,"1:Fatfs.txt",FA_CREATE_ALWAYS | FA_WRITE);
//	LED_PUERLE
//	if(res_flash==FR_OK)
//	{
//		printf("�ļ������ɹ�\r\n");
//		res_flash=f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
//		if(res_flash==FR_OK)
//		{
//			LED_GREEN
//			printf("д�����ݳɹ���\r\n");
//		}
//		else
//		{
//			LED_RED
//			printf("�ļ�д��ʧ��(%d)\r\n",res_flash);
//		}
//	}
//	f_close(&fnew);
//	res_flash=f_mount(NULL,"1:",1);
	/* ��ʼ��LED */
	LED_GPIO_Config();	
	LED_BLUE;
	
	/* ��ʼ�����Դ��ڣ�һ��Ϊ����1 */
	USART_Config();	
  printf("****** ����һ��SPI FLASH �ļ�ϵͳʵ�� ******\r\n");
  
	//���ⲿSPI Flash�����ļ�ϵͳ���ļ�ϵͳ����ʱ���SPI�豸��ʼ��
	//��ʼ������������������
	//f_mount()->find_volume()->disk_initialize->SPI_FLASH_Init()
	res_flash = f_mount(&fs,"1:",1);
	
/*----------------------- ��ʽ������ -----------------*/  
	/* ���û���ļ�ϵͳ�͸�ʽ�����������ļ�ϵͳ */
	if(res_flash == FR_NO_FILESYSTEM)
	{
		printf("��FLASH��û���ļ�ϵͳ���������и�ʽ��...\r\n");
    /* ��ʽ�� */
		res_flash=f_mkfs("1:",0,0);							
		
		if(res_flash == FR_OK)
		{
			printf("��FLASH�ѳɹ���ʽ���ļ�ϵͳ��\r\n");
      /* ��ʽ������ȡ������ */
			res_flash = f_mount(NULL,"1:",1);			
      /* ���¹���	*/			
			res_flash = f_mount(&fs,"1:",1);
		}
		else
		{
			LED_RED;
			printf("������ʽ��ʧ�ܡ�����\r\n");
			while(1);
		}
	}
  else if(res_flash!=FR_OK)
  {
    printf("�����ⲿFlash�����ļ�ϵͳʧ�ܡ�(%d)\r\n",res_flash);
    printf("��������ԭ��SPI Flash��ʼ�����ɹ���\r\n");
		while(1);
  }
  else
  {
    printf("���ļ�ϵͳ���سɹ������Խ��ж�д����\r\n");
  }
  
/*----------------------- �ļ�ϵͳ���ԣ�д���� -------------------*/
	/* ���ļ���ÿ�ζ����½�����ʽ�򿪣�����Ϊ��д */
	printf("\r\n****** ���������ļ�д�����... ******\r\n");	
	res_flash = f_open(&fnew, "1:FatFs.txt",FA_CREATE_ALWAYS | FA_WRITE );
	if ( res_flash == FR_OK )
	{
		printf("����/����FatFs��д�����ļ�.txt�ļ��ɹ������ļ�д�����ݡ�\r\n");
    /* ��ָ���洢������д�뵽�ļ��� */
		res_flash=f_write(&fnew,WriteBuffer,sizeof(WriteBuffer),&fnum);
    if(res_flash==FR_OK)
    {
      printf("���ļ�д��ɹ���д���ֽ����ݣ�%d\n",fnum);
      printf("�����ļ�д�������Ϊ��\r\n%s\r\n",WriteBuffer);
    }
    else
    {
      printf("�����ļ�д��ʧ�ܣ�(%d)\n",res_flash);
    }    
		/* ���ٶ�д���ر��ļ� */
    f_close(&fnew);
	}
	else
	{	
		LED_RED;
		printf("������/�����ļ�ʧ�ܡ�\r\n");
	}
	
	
	
}
