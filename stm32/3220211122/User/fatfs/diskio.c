///*-----------------------------------------------------------------------*/
///* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2014        */
///*-----------------------------------------------------------------------*/
///* If a working storage control module is available, it should be        */
///* attached to the FatFs via a glue function rather than modifying it.   */
///* This is an example of glue functions to attach various exsisting      */
///* storage control modules to the FatFs module with a defined API.       */
///*-----------------------------------------------------------------------*/
//#if 0
//#include "diskio.h"		/* FatFs lower layer API */
//#include "bsp_spi_flash.h"
///* Definitions of physical drive number for each drive */
//#define ATA 0
//#define SPI_FLASH 1


///*-----------------------------------------------------------------------*/
///* Get Drive Status                                                      */
///*-----------------------------------------------------------------------*/

//DSTATUS disk_status (
//	BYTE pdrv		/* Physical drive nmuber to identify the drive */
//)
//{

//	int result;

//	switch (pdrv) {
//	case ATA :
//		break;
//	case SPI_FLASH :
//		result = SPI_FLASH_ReadID();
//	}
//	if(result==0xef4017)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}



///*-----------------------------------------------------------------------*/
///* Inidialize a Drive                                                    */
///*-----------------------------------------------------------------------*/

//DSTATUS disk_initialize (
//	BYTE pdrv				/* Physical drive nmuber to identify the drive */
//)
//{

//	switch (pdrv) {
//	case ATA :
//		break;

//		// translate the reslut code here


//	case SPI_FLASH :
//		SPI_FLASH_Init();

//		// translate the reslut code here

//	}
//	if(0==disk_status(SPI_FLASH))
//		return 0;
//	else
//		return 1;
//}



///*-----------------------------------------------------------------------*/
///* Read Sector(s)                                                        */
///*-----------------------------------------------------------------------*/

//DRESULT disk_read (
//	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
//	BYTE *buff,		/* Data buffer to store read data */
//	DWORD sector,	/* Sector address in LBA */
//	UINT count		/* Number of sectors to read */
//)
//{


//	switch (pdrv) {
//	case ATA :
//		// translate the arguments here

//		break;

//		// translate the reslut code here


//	case SPI_FLASH :
//		// translate the arguments here
//		sector+=512;

//		SPI_FLASH_BuffRead(buff,sector<<12,count<<12);

//		// translate the reslut code here
//	}
//	return RES_OK;
//}



///*-----------------------------------------------------------------------*/
///* Write Sector(s)                                                       */
///*-----------------------------------------------------------------------*/

//#if _USE_WRITE
//DRESULT disk_write (
//	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
//	const BYTE *buff,	/* Data to be written */
//	DWORD sector,		/* Sector address in LBA */
//	UINT count			/* Number of sectors to write */
//)
//{
//	uint32_t addr;

//	switch (pdrv) {
//	case ATA :
//		// translate the arguments here

//		break;


//	case SPI_FLASH:
//		// translate the arguments here

//		sector+=512;
//		addr=sector<<12;
//		SPI_FLASH_SectorErase(addr);
//		SPI_FLASH_BufferWrite((u8*)buff,addr,count<<12);



//	}

//		return RES_OK;
//}
//#endif


///*-----------------------------------------------------------------------*/
///* Miscellaneous Functions                                               */
///*-----------------------------------------------------------------------*/

//#if _USE_IOCTL
//DRESULT disk_ioctl (
//	BYTE pdrv,		/* ������ */
//	BYTE cmd,		  /* ����ָ�� */
//	void *buff		/* д����߶�ȡ���ݵ�ַָ�� */
//)
//{
//	DRESULT status = RES_PARERR;
//	switch (pdrv) {
//		case ATA:	/* SD CARD */
//			break;
//    
//		case SPI_FLASH:
//			switch (cmd) {
//        /* ����������1536*4096/1024/1024=6(MB) */
//        case GET_SECTOR_COUNT:
//          *(DWORD * )buff = 1536;		
//        break;
//        /* ������С  */
//        case GET_SECTOR_SIZE :
//          *(WORD * )buff = 4096;
//        break;
//        /* ͬʱ������������ */
//        case GET_BLOCK_SIZE :
//          *(DWORD * )buff = 1;
//        break;        
//      }
//      status = RES_OK;
//		break;
//    
//		default:
//			status = RES_PARERR;
//	}
//	return status;
//}
//#endif

//__weak DWORD get_fattime(void) {
//	/* ���ص�ǰʱ��� */
//	return	  ((DWORD)(2015 - 1980) << 25)	/* Year 2015 */
//			| ((DWORD)1 << 21)				/* Month 1 */
//			| ((DWORD)1 << 16)				/* Mday 1 */
//			| ((DWORD)0 << 11)				/* Hour 0 */
//			| ((DWORD)0 << 5)				  /* Min 0 */
//			| ((DWORD)0 >> 1);				/* Sec 0 */
//}
//#elif 1
/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2013        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control module to the FatFs module with a defined API.        */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */
#include "ff.h"
#include "bsp_spi_flash.h"


/* Ϊÿ���豸����һ�������� */
#define ATA			    0     // Ԥ��SD��ʹ��
#define SPI_FLASH		1     // �ⲿSPI Flash

/*-----------------------------------------------------------------------*/
/* ��ȡ�豸״̬                                                          */
/*-----------------------------------------------------------------------*/
DSTATUS disk_status (
	BYTE pdrv		/* ������ */
)
{

	DSTATUS status = STA_NOINIT;
	
	switch (pdrv) {
		case ATA:	/* SD CARD */
			break;
    
		case SPI_FLASH:      
      /* SPI Flash״̬��⣺��ȡSPI Flash �豸ID */
      if(0xef4017 == SPI_FLASH_ReadID())
      {
        /* �豸ID��ȡ�����ȷ */
        status &= ~STA_NOINIT;
      }
      else
      {
        /* �豸ID��ȡ������� */
        status = STA_NOINIT;;
      }
			break;

		default:
			status = STA_NOINIT;
	}
	return status;
}

/*-----------------------------------------------------------------------*/
/* �豸��ʼ��                                                            */
/*-----------------------------------------------------------------------*/
DSTATUS disk_initialize (
	BYTE pdrv				/* ������ */
)
{
  uint16_t i;
	DSTATUS status = STA_NOINIT;	
	switch (pdrv) {
		case ATA:	         /* SD CARD */
			break;
    
		case SPI_FLASH:    /* SPI Flash */ 
      /* ��ʼ��SPI Flash */
			SPI_FLASH_Init();
      /* ��ʱһС��ʱ�� */
      i=500;
	    while(--i)
			{
				SPI_Flash_WAKEUP();
			}
      /* ����SPI Flash */
      /* ��ȡSPI FlashоƬ״̬ */
      status=disk_status(SPI_FLASH);
			break;
      
		default:
			status = STA_NOINIT;
	}
	return status;
}


/*-----------------------------------------------------------------------*/
/* ����������ȡ�������ݵ�ָ���洢��                                              */
/*-----------------------------------------------------------------------*/
DRESULT disk_read (
	BYTE pdrv,		/* �豸������(0..) */
	BYTE *buff,		/* ���ݻ����� */
	DWORD sector,	/* �����׵�ַ */
	UINT count		/* ��������(1..128) */
)
{
	DRESULT status = RES_PARERR;
	switch (pdrv) {
		case ATA:	/* SD CARD */
			break;
    
		case SPI_FLASH:
      /* ����ƫ��2MB���ⲿFlash�ļ�ϵͳ�ռ����SPI Flash����6MB�ռ� */
      sector+=512;      
      //SPI_FLASH_BufferRead(buff, sector <<12, count<<12);
		SPI_FLASH_BuffRead(buff,sector<<12,count<<12);
      status = RES_OK;
		break;
    
		default:
			status = RES_PARERR;
	}
	return status;
}

/*-----------------------------------------------------------------------*/
/* д������������д��ָ�������ռ���                                      */
/*-----------------------------------------------------------------------*/
#if _USE_WRITE
DRESULT disk_write (
	BYTE pdrv,			  /* �豸������(0..) */
	const BYTE *buff,	/* ��д�����ݵĻ����� */
	DWORD sector,		  /* �����׵�ַ */
	UINT count			  /* ��������(1..128) */
)
{
  uint32_t write_addr; 
	DRESULT status = RES_PARERR;
	if (!count) {
		return RES_PARERR;		/* Check parameter */
	}

	switch (pdrv) {
		case ATA:	/* SD CARD */      
		break;

		case SPI_FLASH:
      /* ����ƫ��2MB���ⲿFlash�ļ�ϵͳ�ռ����SPI Flash����6MB�ռ� */
			sector+=512;
      write_addr = sector<<12;    
      SPI_FLASH_SectorErase(write_addr);
      SPI_FLASH_BufferWrite((u8 *)buff,write_addr,count<<12);
      status = RES_OK;
		break;
    
		default:
			status = RES_PARERR;
	}
	return status;
}
#endif


/*-----------------------------------------------------------------------*/
/* ��������                                                              */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT disk_ioctl (
	BYTE pdrv,		/* ������ */
	BYTE cmd,		  /* ����ָ�� */
	void *buff		/* д����߶�ȡ���ݵ�ַָ�� */
)
{
	DRESULT status = RES_PARERR;
	switch (pdrv) {
		case ATA:	/* SD CARD */
			break;
    
		case SPI_FLASH:
			switch (cmd) {
        /* ����������1536*4096/1024/1024=6(MB) */
        case GET_SECTOR_COUNT:
          *(DWORD * )buff = 1536;		
        break;
        /* ������С  */
        case GET_SECTOR_SIZE :
          *(WORD * )buff = 4096;
        break;
        /* ͬʱ������������ */
        case GET_BLOCK_SIZE :
          *(DWORD * )buff = 1;
        break;        
      }
      status = RES_OK;
		break;
    
		default:
			status = RES_PARERR;
	}
	return status;
}
#endif

__weak DWORD get_fattime(void) {
	/* ���ص�ǰʱ��� */
	return	  ((DWORD)(2015 - 1980) << 25)	/* Year 2015 */
			| ((DWORD)1 << 21)				/* Month 1 */
			| ((DWORD)1 << 16)				/* Mday 1 */
			| ((DWORD)0 << 11)				/* Hour 0 */
			| ((DWORD)0 << 5)				  /* Min 0 */
			| ((DWORD)0 >> 1);				/* Sec 0 */
}



//#endif

