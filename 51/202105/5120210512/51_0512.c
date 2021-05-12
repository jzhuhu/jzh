//#include<reg52.h>
//sbit led=P2^1;
//void main()
//{
//	unsigned char cnt=0;
//	TMOD=0x01;
//	TH0=0xB1;
//	TL0=0xE0;
//	TR0=1;
//	while(1)
//	{
//		if(TF0==1)
//		{
//			TH0=0xB1;
//			TL0=0xE0;
//			TF0=0;	
//	   		cnt++;
//			if(cnt>=50)
//			{
//			cnt=0;
//			led=~led;
//			}
//		}
//	}	
//}
//数码管的应用
//#include<reg52.h>
//sbit q1=P2^2;
//sbit q2=P2^3;
//sbit q3=P2^4;
//sbit a=P0^0;
//sbit b=P0^1;
//sbit c=P0^2;
//sbit d=P0^3;
//sbit e=P0^4;
//sbit f=P0^5;
//sbit g=P0^6;
//sbit dp=P0^7;
//void main()
//{
//	while(1)
//	{
//		q1=1;
//		q2=1;
//		q3=1;
//		a=1;
//		b=0;
//		c=0;
//		d=1;
//		e=1;
//		f=1;
//		g=1;
//		dp=1;
//	}
//
//}
//#include<reg52.h>
//sbit q1=P2^2;
//sbit q2=P2^3;
//sbit q3=P2^4;
//sbit a=P0^0;
//sbit b=P0^1;
//sbit c=P0^2;
//sbit d=P0^3;
//sbit e=P0^4;
//sbit f=P0^5;
//sbit g=P0^6;
//sbit dp=P0^7;
//void main()
//{
//while(1)
//{
//q1=0;
//q2=0;
//q3=0;
//a=0;
//b=1;
//c=1;
//d=0;
//e=0;
//f=0;
//g=0;
//dp=0;
//}
//
//}
//#include<reg52.h>
//sbit a=P2^2;
//sbit b=P2^3;
//sbit c=P2^4;
//void main()
//{
//	while(1)
//	{
//		a=1;
//		b=0;
//		c=0;
//		P0=0x6D;
//	}
//
//
//
//}


//动态数字显示
//#include<reg52.h>
//
//sbit a=P2^2;
//sbit b=P2^3;
//sbit c=P2^4;
//unsigned char code LedChar[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//void main()
//{
//	unsigned char cnt=0,sec=0;
//	a=0;
//	b=0;
//	c=0;
//	TMOD=0x01;
//	TH0=0xB1;
//	TL0=0xE0;
//	TR0=1;
//	while(1)
//	{
//		if(TF0==1)
//	   	{
//			TF0=0;
//			TH0=0xB1;
//			TL0=0xE0;
//			cnt++;
//			if(cnt>=50)
//			{
//				cnt=0;
//				P0=LedChar[sec];
//				sec++;
//				if(sec>=16)
//				{
//					sec=0;
//				}
//			}
//		}
//	}
//}
