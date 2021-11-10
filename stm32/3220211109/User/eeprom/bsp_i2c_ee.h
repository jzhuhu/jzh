#ifndef BSP_I2C_EE_H
#define BSP_I2C_EE_H
#include "stm32f10x.h"

#define             EEPROM_I2Cx                                I2C1
#define             EEPROM_I2C_APBxClock_FUN                   RCC_APB1PeriphClockCmd
#define             EEPROM_I2C_CLK                             RCC_APB1Periph_I2C1
#define             EEPROM_I2C_GPIO_APBxClock_FUN              RCC_APB2PeriphClockCmd
#define             EEPROM_I2C_GPIO_CLK                        RCC_APB2Periph_GPIOB     
#define             EEPROM_I2C_SCL_PORT                        GPIOB   
#define             EEPROM_I2C_SCL_PIN                         GPIO_Pin_6
#define             EEPROM_I2C_SDA_PORT                        GPIOB 
#define             EEPROM_I2C_SDA_PIN                         GPIO_Pin_7




#define I2C_Speed              400000  


#define I2Cx_OWN_ADDRESS7      0X0A   


#define I2C_PageSize           8


#define I2CT_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define I2CT_LONG_TIMEOUT         ((uint32_t)(10 * I2CT_FLAG_TIMEOUT))


#define EEPROM_DEBUG_ON         0

#define EEPROM_INFO(fmt,arg...)           printf("<<-EEPROM-INFO->> "fmt"\n",##arg)
#define EEPROM_ERROR(fmt,arg...)          printf("<<-EEPROM-ERROR->> "fmt"\n",##arg)
#define EEPROM_DEBUG(fmt,arg...)          do{\
                                          if(EEPROM_DEBUG_ON)\
                                          printf("<<-EEPROM-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)




#define EEPROM_Block0_ADDRESS 0xA0   

																					
void I2C_EE_Init(void);
uint32_t I2C_EE_ByteWrite(u8* pBuffer,u8 WriteAddr);
uint32_t I2C_EE_BytesWrite(u8 *pBuffer,uint8_t WriteAddr,uint16_t NumByteToWrite);
uint8_t I2C_EE_PageWrite(u8 *pBuffer,u8 WriteAddr,u8 NumByteToWrite);																					
uint32_t I2C_EE_BufferRead(uint8_t* pBuffer,uint8_t ReadAddr,u16 NumByteToRead);																					
#endif /*BSP_I2C_EE.H*/
