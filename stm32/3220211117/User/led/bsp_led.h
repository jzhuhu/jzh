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

//ֱ�Ӳ����Ĵ����ķ�ʽ����io
#define digitalHi(p,i)	{p->BSRR=i;}//���Ϊ�ߵ�ƽ
#define digitalLo(p,i)	{p->BRR=i;}//���Ϊ�͵�ƽ
#define digitalToggle(p,i)	{p->ODR^=i;}//���Ϊ��ת

//��ɫС�Ƶ�״̬
#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		 digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			 digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

//��ɫС�Ƶ�״̬
#define LED2_TOGGLE  digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		 digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			 digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

//��ɫС�Ƶ�״̬
#define LED3_TOGGLE  digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF		 digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON			 digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

//��
#define LED_RED				LED1_ON;LED2_OFF;LED3_OFF
//��ɫ
#define LED_GREEN			LED1_OFF;LED2_ON;LED3_OFF
//��ɫ
#define LED_BLUE			LED1_OFF;LED2_OFF;LED3_ON
//��ɫ
#define LED_YELLOW			LED1_ON;LED2_ON;LED3_OFF
//��ɫ
#define LED_PUERLE			LED1_ON;LED2_OFF;LED3_ON
//��ɫ
#define LED_CYAN			LED1_OFF;LED2_ON;LED3_ON
//��ɫ
#define LED_WHITE			LED1_ON;LED2_ON;LED3_ON
//��ɫ
#define LED_RGBOFF			LED1_OFF;LED2_OFF;LED3_OFF

void LED_GPIO_Config(void);

#endif


