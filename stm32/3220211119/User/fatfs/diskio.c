/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */
#include "bsp_spi_flash.h"


#define ATA 0
#define SPI_FLASH 1

// Get Drive Status                                                     
DSTATUS disk_status(BYTE pdrv)
{
	int result;

	switch (pdrv) 
		{
			case ATA:
					break;

			case SPI_FLASH :
			result = SPI_FLASH_ReadID();
		}
	if(result==0xef4017)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// Inidialize a Drive

DSTATUS disk_initialize(BYTE pdrv)
{
	switch (pdrv) 
		{
			case ATA:
					break;

		// translate the reslut code here
			case SPI_FLASH :
			SPI_FLASH_Init();
		}
		if(0==disk_status(SPI_FLASH))
			return 0;
		else
			return 1;
}
		



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	LBA_t sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
	sector+=512;

	switch (pdrv)
		{
			case ATA :
				break;
		// translate the reslut code here
			case SPI_FLASH :
		// translate the arguments here
				SPI_FLASH_BuffRead(buff,sector<<12,count<<12);
	}
	return RES_OK;
}




// Write Sector(s) 


#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	LBA_t sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
	uint32_t addr;


	switch (pdrv) 
		{
			case ATA :
				break;

			case SPI_FLASH :
				sector+=512;
				addr=sector<<12;
				SPI_FLASH_SectorErase(addr);
				SPI_FLASH_BufferWrite((u8*)buff,addr,count<<12);
		}
	return RES_OK;
}

#endif


DRESULT disk_ioctl(BYTE pdrv,BYTE cmd,void *buff)
{
	DRESULT status = RES_PARERR;
	switch (pdrv) {
		case ATA:	/* SD CARD */
			break;
    
		case SPI_FLASH:
			switch (cmd) {
        
        case GET_SECTOR_COUNT:
          *(DWORD * )buff = 1536;		
        break;
     
        case GET_SECTOR_SIZE :
          *(WORD * )buff = 4096;
        break;
    
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

__weak DWORD get_fattime(void) {

	return	  ((DWORD)(2015 - 1980) << 25)	/* Year 2015 */
			| ((DWORD)1 << 21)				/* Month 1 */
			| ((DWORD)1 << 16)				/* Mday 1 */
			| ((DWORD)0 << 11)				/* Hour 0 */
			| ((DWORD)0 << 5)				  /* Min 0 */
			| ((DWORD)0 >> 1);				/* Sec 0 */
}



