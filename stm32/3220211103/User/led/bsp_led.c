#include "bsp_led.h"
//#include "stm32f10x.h"
void LED_GPIO_Config(void)
{
	//定义一个gpioinit类型的指针
	GPIO_InitTypeDef GPIO_InitStructure;
	//开启时钟
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK|LED2_GPIO_CLK|LED3_GPIO_CLK, ENABLE);
	//选择控制引脚
	GPIO_InitStructure.GPIO_Pin=LED1_GPIO_PIN;
	//mode=pull-push
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	//set speed 50mhz
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	//init gpioB
	GPIO_Init(LED1_GPIO_PORT,&GPIO_InitStructure);
	//选择控制引脚
	GPIO_InitStructure.GPIO_Pin=LED2_GPIO_PIN;	
	//init gpioB
	GPIO_Init(LED2_GPIO_PORT,&GPIO_InitStructure);	
	//选择控制引脚
	GPIO_InitStructure.GPIO_Pin=LED3_GPIO_PIN;	
	//init gpioB
	GPIO_Init(LED3_GPIO_PORT,&GPIO_InitStructure);	
//close led1
	GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);
//close led2
	GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);
//close led3
	GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);
}
