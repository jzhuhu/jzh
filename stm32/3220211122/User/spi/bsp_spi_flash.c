#include "bsp_spi_flash.h"
uint32_t SPITimeout;
static uint16_t SPI_TIMEOUT_UserCallback(u8 errorCode);
void SPI_FLASH_Init(void)
{
	SPI_InitTypeDef SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//CS---PA4
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	//CLK---PA5
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//MISO--PA6
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
	//MOSI--PA7
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
	//SPI1
	SPI_InitStructure.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;
	SPI_InitStructure.SPI_CPHA=SPI_CPOL_High;
	SPI_InitStructure.SPI_CPOL=SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_DataSize=SPI_DataSize_8b;
	SPI_InitStructure.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_FirstBit=SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_Mode=SPI_Mode_Master;
	SPI_InitStructure.SPI_NSS=SPI_NSS_Soft;
	SPI_Init(SPI1,&SPI_InitStructure);
	SPI_Cmd(SPI1,ENABLE);
}
//send bit
uint8_t SPI_FLASH_SendByte(u8 byte)
{
	SPITimeout=SPIT_FLAG_TIMEOUT;
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)==RESET)
	{
		if((SPITimeout--)==0)
		{
			SPI_TIMEOUT_UserCallback(0);
		}
	}
	SPI_I2S_SendData(SPI1,byte);
	SPITimeout=SPIT_FLAG_TIMEOUT;
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)==RESET)
	{
		if((SPITimeout--)==0)
		{
			SPI_TIMEOUT_UserCallback(1);
		}
	}	
	return	SPI_I2S_ReceiveData(SPI1);
}
//receive data
uint8_t SPI_FLASH_ReceiveByte(void)
{
	return SPI_FLASH_SendByte(Dummy_Byte);
}
//read flash id
uint32_t SPI_FLASH_ReadID(void)
{
	uint32_t Temp=0,Temp0=0,Temp1=0,Temp2=0;
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	SPI_FLASH_SendByte(0x9f);
	Temp0=SPI_FLASH_ReceiveByte();
	Temp1=SPI_FLASH_ReceiveByte();
	Temp2=SPI_FLASH_ReceiveByte();
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	Temp=(Temp0<<16)|(Temp1<<8)|Temp2;
	return Temp;
}
//write enable 
void SPI_FALSH_WriteEnable(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	SPI_FLASH_SendByte(0x06);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}
//wait write end
void SPI_FLASH_WaitForWriteEnd(void)
{
	uint8_t FLASH_Status=0;
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	SPI_FLASH_SendByte(0x05);
	do
	{
		FLASH_Status=SPI_FLASH_ReceiveByte();
	}while((FLASH_Status&0x01)==1);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}
//sector erase
void SPI_FLASH_SectorErase(u32 SectorAddr)
{
	SPI_FALSH_WriteEnable();
	SPI_FALSH_WriteEnable();
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	SPI_FLASH_SendByte(0x20);
	SPI_FLASH_SendByte((SectorAddr&0xff0000)>>16);
	SPI_FLASH_SendByte((SectorAddr&0x00ff00)>>8);
	SPI_FLASH_SendByte(SectorAddr&0x0000ff);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	SPI_FLASH_WaitForWriteEnd();
}
//PageWrite
void SPI_FLASH_PageWrite(u8 *pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
	SPI_FALSH_WriteEnable();
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	SPI_FLASH_SendByte(0x02);
	SPI_FLASH_SendByte((WriteAddr&0xff0000)>>16);
	SPI_FLASH_SendByte((WriteAddr&0x00ff00)>>8);
	SPI_FLASH_SendByte(WriteAddr&0x0000ff);	
	while(NumByteToWrite--)
	{
		SPI_FLASH_SendByte(*pBuffer++);
	}
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	SPI_FLASH_WaitForWriteEnd();
}	
void SPI_FLASH_BufferWrite(u8 *pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
	uint8_t NumOfPage=0,NumOfSingle=0,Addr=0,count=0,temp=0;
	Addr=WriteAddr%256;
	count=256-Addr;
	NumOfPage=NumByteToWrite/256;
	NumOfSingle=NumByteToWrite%256;
	if(Addr==0)
	{
		if(NumOfPage==0)
		{
			SPI_FLASH_PageWrite(pBuffer,WriteAddr,NumByteToWrite);
		}
		else
		{
			while(NumOfPage--)
			{
				SPI_FLASH_PageWrite(pBuffer,WriteAddr,256);
				pBuffer=pBuffer+256;
				WriteAddr=WriteAddr+256;
			}
			SPI_FLASH_PageWrite(pBuffer,WriteAddr,NumOfSingle);
		}
	}
	else
	{
		if(NumOfPage==0)
		{
			if(NumOfSingle>count)
			{
				temp=NumOfSingle-count;
				SPI_FLASH_PageWrite(pBuffer,WriteAddr,count);
				pBuffer+=count;
				WriteAddr+=count;	
				SPI_FLASH_PageWrite(pBuffer,WriteAddr,temp);
			}
			else
			{
				SPI_FLASH_PageWrite(pBuffer,WriteAddr,NumByteToWrite);
			}
		}
		else
		{
			NumByteToWrite-=count;
			NumOfPage=NumByteToWrite/256;
			NumOfSingle=NumByteToWrite%256;
			SPI_FLASH_PageWrite(pBuffer,WriteAddr,count);
			pBuffer+=count;
			WriteAddr+=count;
			while(NumOfPage--)
			{
				SPI_FLASH_PageWrite(pBuffer,WriteAddr,256);
				pBuffer+=256;
				WriteAddr+=256;			
			}
			if(NumOfSingle!=0)
			{
				SPI_FLASH_PageWrite(pBuffer,WriteAddr,NumOfSingle);
			}
		}
	}	
}	



//read data
void SPI_FLASH_BuffRead(u8 *pBuffer,u32 ReadAddr,u16 NumByteToRead)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	SPI_FLASH_SendByte(0x03);
	SPI_FLASH_SendByte((ReadAddr&0xff0000)<<16);
	SPI_FLASH_SendByte((ReadAddr&0x00ff00)<<8);
	SPI_FLASH_SendByte(ReadAddr&0x0000ff);	
	while(NumByteToRead--)
	{
		*pBuffer=SPI_FLASH_ReceiveByte();
		 pBuffer++;
	}
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}

//error report
static uint16_t SPI_TIMEOUT_UserCallback(u8 errorCode)
{
	SPI_FLASH_ERROR("SPI delay,errorCode=%d",errorCode);
	return 0;
}
void SPI_Flash_WAKEUP(void)   
{
  /*选择 FLASH: CS 低 */
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);

  /* 发送 上电 命令 */
  SPI_FLASH_SendByte(0xAB);

   /* 停止信号 FLASH: CS 高 */
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}  
