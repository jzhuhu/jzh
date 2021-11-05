#include "bsp_dma.h"
#include "stm32f10x_dma.h"
const uint32_t aSRC_Const_Buffer[BUFFER_SIZE]=
																		{
																		0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                    0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                    0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                    0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                    0x41424344,0x45464748,0x494A4B4C,0x4D4E4F50,
                                    0x51525354,0x55565758,0x595A5B5C,0x5D5E5F60,
                                    0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                    0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80};
uint32_t aDST_Buffer[BUFFER_SIZE];

void DMA_Config()
{
	DMA_InitTypeDef DMA_InitStructure;
	//open clock
	RCC_AHBPeriphClockCmd(DMA_CLOCK,ENABLE);
	//Periph base addr
	DMA_InitStructure.DMA_PeripheralBaseAddr=(uint32_t)aSRC_Const_Buffer;
	//memory base addr
	DMA_InitStructure.DMA_MemoryBaseAddr=(uint32_t)aDST_Buffer;
	//dirct
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralSRC;
	//tralate buffersize 
	DMA_InitStructure.DMA_BufferSize=BUFFER_SIZE;
	//memory increase
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;
	//periph increase
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralInc_Enable;
	//cofig periph size =32
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Word;
	//cofig memory size=32
	DMA_InitStructure.DMA_MemoryDataSize=DMA_MemoryDataSize_Word;
	//mode set
	DMA_InitStructure.DMA_Mode=DMA_Mode_Normal;
	//priority
	DMA_InitStructure.DMA_Priority=DMA_Priority_Medium;
	//config m2m
	DMA_InitStructure.DMA_M2M=DMA_M2M_Enable;
	//Initializes the DMA
	DMA_Init(DMA_CHANNEL,&DMA_InitStructure);
	//Enables the specified DMA1 Channel6
	DMA_Cmd(DMA_CHANNEL,ENABLE);
	
}
uint8_t Buffercmp(const uint32_t *pBuffer,uint32_t *pBuffer1,uint16_t BufferLength)
{
	while(BufferLength--)
	{
		if(*pBuffer!=*pBuffer1)
		{
			return 0;
		}
		pBuffer++;
		pBuffer1++;
	}
	return 1;
}

