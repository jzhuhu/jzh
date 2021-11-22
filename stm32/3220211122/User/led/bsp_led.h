#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"
//red led
#define LED1_GPIO_PORT		GPIOB
#define LED1_GPIO_CLK			RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN			GPIO_Pin_5

//green led
#define LED2_GPIO_PORT		GPIOB
#define LED2_GPIO_CLK			RCC_APB2Periph_GPIOB
#define LED2_GPIO_PIN			GPIO_Pin_0

//blue red
#define LED3_GPIO_PORT		GPIOB
#define LED3_GPIO_CLK			RCC_APB2Periph_GPIOB
#define LED3_GPIO_PIN			GPIO_Pin_1

//直接操作寄存器的方式操作io
#define digitalHi(p,i)	{p->BSRR=i;}//输出为高电平
#define digitalLo(p,i)	{p->BRR=i;}//输出为低电平
#define digitalToggle(p,i)	{p->ODR^=i;}//输出为反转

//红色小灯的状态
#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		 digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			 digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

//绿色小灯的状态
#define LED2_TOGGLE  digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		 digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			 digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

//蓝色小灯的状态
#define LED3_TOGGLE  digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF		 digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON			 digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

//红
#define LED_RED				LED1_ON;LED2_OFF;LED3_OFF
//绿色
#define LED_GREEN			LED1_OFF;LED2_ON;LED3_OFF
//蓝色
#define LED_BLUE			LED1_OFF;LED2_OFF;LED3_ON
//黄色
#define LED_YELLOW			LED1_ON;LED2_ON;LED3_OFF
//紫色
#define LED_PUERLE			LED1_ON;LED2_OFF;LED3_ON
//青色
#define LED_CYAN			LED1_OFF;LED2_ON;LED3_ON
//白色
#define LED_WHITE			LED1_ON;LED2_ON;LED3_ON
//黑色
#define LED_RGBOFF			LED1_OFF;LED2_OFF;LED3_OFF

void LED_GPIO_Config(void);

#endif


