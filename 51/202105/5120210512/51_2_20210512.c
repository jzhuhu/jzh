#include<reg52.h>
sbit a=P2^2;
sbit b=P2^3;
sbit c=P2^4;
unsigned char code LedChar[]={0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f};
void main()
{
	unsigned char cnt=0,sec=0;
	a=0;
	b=0;
	c=0;
	TMOD=0x01;
	TH0=0xB1;
	TL0=0xE0;
	TR0=1;
	while(1)
	{
		if(TF0==1)
	   	{
			TF0=0;
			TH0=0xB1;
			TL0=0xE0;
			cnt++;
			if(cnt>=50)
			{
				cnt=0;
				P0=LedChar[sec];
				sec++;
				if(sec>=10)
				{
					sec=0;
				}
			}
		}
	}
}