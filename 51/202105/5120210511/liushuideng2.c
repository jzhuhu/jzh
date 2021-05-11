//流水灯右移操作
//#include<reg52.h>
//void main()
//{
//	unsigned int i=0;
//	unsigned char cnt=0;
//	while(1)
//	{
//	 	P2=~(0x01<<cnt);
//		for(i=0;i<40000;i++);
//		cnt++;
//		if(cnt>=8)
//		{
//			cnt=0;
//		}
//	}
//}
//流水灯左移
//#include<reg52.h>
//void main()
//{
//	unsigned int i=0;
//	unsigned char cnt=0;
//	while(1)
//	{
//	 	P2=~(0x80>>cnt);
//		for(i=0;i<30000;i++);
//		cnt++;
//		if(cnt>=8)
//		{
//			cnt=0;
//		}
//	}
//}
//多功能流水灯
//#include<reg52.h>
//void main()
//{
//	unsigned int i=0;
//	unsigned char dir=0;
//	unsigned char shift=0x01;
//	while(1)
//	{
//		P2=~shift;
//		for(i=0;i<30000;i++);
//		if(dir==0)
//		{
//			shift=shift<<1;
//			if(shift==0x80)
//			{
//				dir=1;
//			}
//		}
//		else
//		{
//			shift=shift>>1;
//			if(shift==0x01)
//			{
//				dir=0;
//			}
//		}
//	}

//}
#include<reg52.h>
sbit led=P2^2;
void main()
{
	while(1)
	{
		led=1;
	}

}
