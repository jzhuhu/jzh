#ifndef _BSP_USART_H
#define _BSP_USART_H
#include "stm32f10x.h"
//usart1
#define DEBUG_USARTx									USART1
#define DEBUG_USART_CLK								RCC_APB2Periph_USART1
#define DEBUG_USART_APBxCLKCmd				RCC_APB2PeriphClockCmd
#define DEBUG_USART_BAUDRATE					115200
//usart1--gpio  pa9-TX/pa10-RX
#define DEBUG_USART_GPIO_CLK					RCC_APB2Periph_GPIOA
#define DEBUG_USART_GPIO_APBxClkCmd		RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT			GPIOA
#define DEBUG_USART_TX_GPIO_PIN				GPIO_Pin_9
#define	DEBUG_USART_RX_GPIO_PORT			GPIOA
#define DEBUG_USART_RX_GPIO_PIN				GPIO_Pin_10

#define DEBUG_USART_IRQ								USART1_IRQn
#define DEBUG_USART_IRQHandler				USART1_IRQHandler

static void NVIC_Configuration(void);
void USART_Config(void);
void Usart_SendByte(USART_TypeDef *pUSARTx,uint8_t ch);
void Usart_sendString(USART_TypeDef *pUSARTx,char *str);
void DEBUG_USART_IRQHandler(void);


#endif
