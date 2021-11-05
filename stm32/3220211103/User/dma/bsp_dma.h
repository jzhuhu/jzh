#ifndef _BSP_DMA_H
#define _BSP_DMA_H
#include "stm32f10x.h"
#define DMA_CHANNEL		DMA1_Channel6
#define DMA_CLOCK			RCC_AHBPeriph_DMA1

#define DMA_FLAG_TC		DMA1_FLAG_TC6

#define BUFFER_SIZE		32



void DMA_Config(void);
uint8_t Buffercmp(const uint32_t *pBuffer,uint32_t *pBuffer1,uint16_t BufferLength);

#endif /*_BSP_DMA_H*/
