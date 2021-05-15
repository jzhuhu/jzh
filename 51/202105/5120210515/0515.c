#include<reg52.h>
sbit a=P2^2;
sbit b=P2^3;
sbit c=P2^4;
unsigned char code LedChar[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71} ;
unsigned char LedBuff[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned int cnt=0;
unsigned char flag=0;
unsigned long int sec=100000000;
void main()
{
	a=0;
	b=0;
	c=0;
	TMOD=0x10;
	TR1=1;
	TH1=0xFC;
	TL1=0x18;
	EA=1;
	ET1=1;
	while(1)
	{
		if(flag==1)
		{
			flag=0;
			sec--;
			LedBuff[0]=LedChar[sec%10];
			LedBuff[1]=LedChar[sec/10%10];
			LedBuff[2]=LedChar[sec/100%10];
			LedBuff[3]=LedChar[sec/1000%10];
			LedBuff[4]=LedChar[sec/10000%10];
			LedBuff[5]=LedChar[sec/100000%10];
			LedBuff[6]=LedChar[sec/1000000%10];
			LedBuff[7]=LedChar[sec/10000000%10];
		}
	}
}
void InterruptTime()	interrupt 3
{
	static unsigned char i=0;
	TH1=0xFC;
	TL1=0x18;	
	cnt++;

	if(cnt>=1000)
	{
		cnt=0;
	   	flag=1;
	}
	P0=0x00;
	switch(i)
	{
		case 0:a=0;b=0;c=0;i++;P0=LedBuff[0];break;
		case 1:a=1;b=0;c=0;i++;P0=LedBuff[1];break;
		case 2:a=0;b=1;c=0;i++;P0=LedBuff[2];break;		
		case 3:a=1;b=1;c=0;i++;P0=LedBuff[3];break;		
		case 4:a=0;b=0;c=1;i++;P0=LedBuff[4];break;		
		case 5:a=1;b=0;c=1;i++;P0=LedBuff[5];break;		
		case 6:a=0;b=1;c=1;i++;P0=LedBuff[6];break;		
		case 7:a=1;b=1;c=1;i=0;P0=LedBuff[7];break;			
	}
}