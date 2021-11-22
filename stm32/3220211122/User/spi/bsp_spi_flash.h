#ifndef _BSP_SPI_FLASH_H
#define	_BSP_SPI_FLASH_H 
#include "stm32f10x.h"
#include<stdio.h>
#define Dummy_Byte 0xff

#define SPIT_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define SPIT_LONG_TIMEOUT         ((uint32_t)(10 * SPIT_FLAG_TIMEOUT))
#define SPI_DEBUG_ON			1
#define	SPI_FLASH_INFO(fmt,arg...)	printf("flash info--"fmt"\n",##arg)
#define	SPI_FLASH_ERROR(fmt,arg...)	printf("flash ERROR--"fmt"\n",##arg)
#define	SPI_FLASH_DEBUG(fmt,arg...)	do{if(SPI_DEBUG_ON)\
																				{printf("flash ERROR--[%d ]"fmt"\n",__FILE__,##arg);}}while(0)

void SPI_FLASH_Init(void);
uint32_t SPI_FLASH_ReadID(void);
void SPI_FLASH_SectorErase(u32 SectorAddr);																				
void SPI_FLASH_PageWrite(u8 *pBuffer,u32 WriteAddr,u16 NumByteToWrite);
void SPI_FLASH_BuffRead(u8 *pBuffer,u32 ReadAddr,u16 NumByteToRead);		
void SPI_FLASH_BufferWrite(u8* pBuffer, u32 WriteAddr, u16 NumByteToWrite);
void SPI_Flash_WAKEUP(void);																				
#endif /*_BSP_SPI_FLASH_H*/


