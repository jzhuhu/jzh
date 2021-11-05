#ifndef _BSP_DMA_H
#define _BSP_DMA_H
#include "stm32f10x.h"
#define DEBUG_USARTx 													USART1
#define DEBUG_USART_CLK									RCC_APB2Periph_USART1
#define DEBUG_USART_APBxClkCmd					RCC_APB2PeriphClockCmd
#define DEBUG_USART_BAUDRATE						115200

#define DEBUG_USART_GPIO_CLK						RCC_APB2Periph_GPIOA
#define DEBUG_USART_GPIO_APBxClkCmd			RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT				GPIOA
#define DEBUG_USART_TX_GPIO_PIN					GPIO_Pin_9
#define DEBUG_USART_RX_GPIO_PORT				GPIOA
#define DEBUG_USART_RX_GPIO_PIN					GPIO_Pin_10





#define USART_TX_DMA_CHANNEL		DMA1_Channel4
#define USART_DR_ADDRESS				(USART1_BASE+0X04)

#define DMA_CLOCK			RCC_AHBPeriph_DMA1

//#define DMA_FLAG_TC		DMA1_FLAG_TC6

#define SENDBUFF_SIZE		5000


void USART_Config(void);
void SendByte(USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendArray(USART_TypeDef * pUSARTx,uint8_t *array, uint16_t num);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);
void DMA_Config(void);
uint8_t Buffercmp(const uint32_t *pBuffer,uint32_t *pBuffer1,uint16_t BufferLength);

#endif /*_BSP_DMA_H*/
