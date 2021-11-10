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
	EEPROM_ERROR("I2C等待超时！errorCode=%d",errorCode);
	return 0;
}
uint32_t I2C_EE_ByteWrite(u8* pBuffer,u8 WriteAddr)
{
	//generate start single
	I2C_GenerateSTART(EEPROM_I2Cx,ENABLE);
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	//wait sb=1
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_MODE_SELECT))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(0));
		}
	}
	//send address
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	I2C_Send7bitAddress(EEPROM_I2Cx,EEPROM_ADDRESS,I2C_Direction_Transmitter);

	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(1));
		}
	}
	//send data
	I2C_SendData(EEPROM_I2Cx,WriteAddr);
	I2CTimeout=I2CT_FLAG_TIMEOUT;	
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(2));
		}
	//send data
	I2C_SendData(EEPROM_I2Cx,*pBuffer);
	I2CTimeout=I2CT_FLAG_TIMEOUT;		
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	{
		if((I2CTimeout--)==0)
		{
			return (I2C_TIMEOUT_UserCallback(3));
		}		
	}
	//send stop
	I2C_GenerateSTOP(EEPROM_I2Cx,ENABLE);
}
	return	1;
}

//wait eeprom ready
void I2C_EE_WaitEepromStandbyState(void)
{
	vu16 SR1_Tmp=0;
	do
	{
		//generate start single
		I2C_GenerateSTART(EEPROM_I2Cx,ENABLE);
		//read register SR1
		SR1_Tmp=I2C_ReadRegister(EEPROM_I2Cx,I2C_Register_SR1);
		//write eeprom address
		I2C_Send7bitAddress(EEPROM_I2Cx,EEPROM_ADDRESS,I2C_Direction_Transmitter);
	}while(!(I2C_ReadRegister(EEPROM_I2Cx,I2C_Register_SR1)&0x02));
	I2C_ClearFlag(EEPROM_I2Cx,I2C_FLAG_AF);
	//send stop
	I2C_GenerateSTOP(EEPROM_I2Cx,ENABLE);
	
}
//write many byte
uint32_t I2C_EE_BytesWrite(u8 *pBuffer,u8 WriteAddr,u16 NumByteToWrite)
{
	uint16_t i;
	uint32_t res;
	for(i=0;i<NumByteToWrite;i++)
	{
		I2C_EE_WaitEepromStandbyState();
		res=I2C_EE_ByteWrite(pBuffer++,WriteAddr++);
	}
	return res;
}

//write page 
uint8_t I2C_EE_PageWrite(u8 *pBuffer,u8 WriteAddr,u8 NumByteToWrite)
{
	I2CTimeout=I2CT_LONG_TIMEOUT;
	while(I2C_GetFlagStatus(EEPROM_I2Cx,I2C_FLAG_BUSY))
	{
		if((I2CTimeout--)==0)
		{
			return	(I2C_TIMEOUT_UserCallback(4));
		}
	}
	I2C_GenerateSTART(EEPROM_I2Cx,ENABLE);
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_MODE_SELECT))
	{
		if((I2CTimeout--)==0)
		{
			return	(I2C_TIMEOUT_UserCallback(5));
		}		
	}
	//send eeprom address
	I2C_Send7bitAddress(EEPROM_I2Cx,EEPROM_ADDRESS,I2C_Direction_Transmitter);
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if((I2CTimeout--)==0)
		{
			return	(I2C_TIMEOUT_UserCallback(6));
		}	
	}
	//send write address
	I2C_SendData(EEPROM_I2Cx,WriteAddr);
	I2CTimeout=I2CT_FLAG_TIMEOUT;
	while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	{
		if((I2CTimeout--)==0)
		{
			return	(I2C_TIMEOUT_UserCallback(7));
		}		
	}
	while(NumByteToWrite--)
	{
		I2C_SendData(EEPROM_I2Cx,*pBuffer);
		pBuffer++;
		I2CTimeout=I2CT_FLAG_TIMEOUT;
		while(!I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			if((I2CTimeout--)==0)
			{
				return	(I2C_TIMEOUT_UserCallback(8));
			}		
		}	
	}
		I2C_GenerateSTOP(EEPROM_I2Cx,ENABLE);
		return 1;	
}
//many byte write
/**
*@brief 把很多字节写到eepron中
*@param
*		@arg pBuffer:缓冲区指针
*		@arg WriteAddr:eeprom写地址
*		@arg NumByteToRead:写入数据个数
*		@retval	无
*/
void I2C_EE_BufferWrite(u8 *pBuffer,u8 WriteAddr,u16 NumByteToWrite)
{
	//不想写了。太累了，没意思

}	
/**
*@brief 从eeprom中读取多个字节
*@param 
*@arg pBuffer:空数组首指针，也就是将读出的数据存放到此
*@arg ReadAddr：eeprom读地址
*@arg NumByteToRead:读出数据的个数
*/

uint32_t I2C_EE_BufferRead(uint8_t* pBuffer,uint8_t ReadAddr,u16 NumByteToRead)
{
	I2CTimeout=I2CT_LONG_TIMEOUT;
	while(I2C_GetFlagStatus(EEPROM_I2Cx,I2C_FLAG_BUSY))
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
		if(NumByteToRead==1)
		{
			I2C_AcknowledgeConfig(EEPROM_I2Cx,DISABLE);
			I2C_GenerateSTOP(EEPROM_I2Cx,ENABLE);
		}
		I2CTimeout=I2CT_LONG_TIMEOUT;
		while(I2C_CheckEvent(EEPROM_I2Cx,I2C_EVENT_MASTER_BYTE_RECEIVED)==0)
		{
			if((I2CTimeout--)==0)
			{
				return (I2C_TIMEOUT_UserCallback(3));
			}
		}
		*pBuffer=I2C_ReceiveData(EEPROM_I2Cx);
		pBuffer++;
		NumByteToRead--;
	}
	I2C_AcknowledgeConfig(EEPROM_I2Cx,ENABLE);
	return 1;
}

