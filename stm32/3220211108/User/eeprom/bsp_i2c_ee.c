#include "bsp_i2c_ee.h"
#include "bsp_usart.h"
#include <stdio.h>
uint32_t EEPROM_ADDRESS;
uint32_t I2CTimeout;
static void I2C_GPIO_Config(void)
{
	//configrate GPIO_InitStructure
	GPIO_InitTypeDef GPIO_InitStructure;
	//open gpio clk
	EEPROM_I2C_GPIO_APBxClock_FUN(EEPROM_I2C_GPIO_CLK,ENABLE);
	//open gpio clk
	EEPROM_I2C_APBxClock_FUN(EEPROM_I2C_CLK,ENABLE);
	//i2c scl
	GPIO_InitStructure.GPIO_Pin=EEPROM_I2C_SCL_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(EEPROM_I2C_SCL_PORT,&GPIO_InitStructure);
	//i2c sda
	GPIO_InitStructure.GPIO_Pin=EEPROM_I2C_SDA_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(EEPROM_I2C_SDA_PORT,&GPIO_InitStructure);
}

static void I2C_Mode_Config(void)
{
	I2C_InitTypeDef I2C_InitStructure;
	//configrate i2c
	I2C_InitStructure.I2C_ClockSpeed=I2C_Speed;
	I2C_InitStructure.I2C_Mode=I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle=I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1=I2Cx_OWN_ADDRESS7;
	I2C_InitStructure.I2C_Ack=I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;
	//init i2c
	I2C_Init(EEPROM_I2Cx,&I2C_InitStructure);
	//ENABLE I2C
	I2C_Cmd(EEPROM_I2Cx,ENABLE);
}

//init eeprom
void I2C_EE_Init(void)
{
	I2C_GPIO_Config();
	I2C_Mode_Config();
	EEPROM_ADDRESS=EEPROM_Block0_ADDRESS;
}
static uint32_t I2C_TIMEOUT_UserCallback(uint8_t errorCode)
{
	EEPROM_ERROR("I2CµÈ´ý³¬Ê±£¡errorCode=%d",errorCode);
	return 0;
}
uint32_t I2C_EE_ByteWrite(u8* pBuffer,u8 WriteAddr)
{
	//generate start single
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	I2C_GenerateSTART(EEPROM_I2Cx,ENABLE);
	//wait sb=1
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_MODE_SELECT))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(0));
		}
	}
	//send address
	I2C_Send7bitAddress(EEPROM_I2Cx,EEPROM_ADDRESS,I2C_Direction_Transmitter);
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(1));
		}
	}
	//send data
	I2C_SendData(EEPROM_I2Cx,WriteAddr);
	I2CTimeout=I2CT_FLAG_TIMEOUT;	
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTING))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(2));
		}
	//send data
	I2C_SendData(EEPROM_I2Cx,*pBuffer);
	I2CTimeout=I2CT_FLAG_TIMEOUT;		
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTING))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(3));
		}		
	}
	//send stop
	I2C_GenerateSTOP(EEPROM_I2Cx, ENABLE);
}
	return	1;
}

uint8_t I2C_EE_BufferRead(uint8_t* pBuffer,uint8_t ReadAddr,u16 NumByteToRead)
{
	I2CTimeout=I2CT_LONG_TIMEOUT;
	while(!I2C_GetFlagStatus(EEPROM_I2Cx,I2C_FLAG_BUSY))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(9));
		}	
	}
	//generate start single
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	I2C_GenerateSTART(EEPROM_I2Cx,ENABLE);
	//wait sb=1
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_MODE_SELECT))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(10));
		}
	}
	//send address
	I2C_Send7bitAddress(EEPROM_I2Cx,EEPROM_ADDRESS,I2C_Direction_Transmitter);
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(11));
		}
	}	
	I2C_Cmd(EEPROM_I2Cx,ENABLE);
	//send data
	I2C_SendData(EEPROM_I2Cx,ReadAddr);
	I2CTimeout=I2CT_FLAG_TIMEOUT;	
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTING))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(12));
		}	
	}
//generate start single
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	I2C_GenerateSTART(EEPROM_I2Cx,ENABLE);
	//wait sb=1
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_MODE_SELECT))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(13));
		}
	}	
	//send address
	I2C_Send7bitAddress(EEPROM_I2Cx,EEPROM_ADDRESS,I2C_Direction_Receiver);
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(14));
		}
	}	
	while(NumByteToRead)
	{
		
	
	
	}
}