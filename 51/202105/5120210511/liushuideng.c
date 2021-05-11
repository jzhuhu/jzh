//#include<reg52.h>
//sbit led=P2^1;
//void main()
//{
//	unsigned int i=0;
//	while(1)
//   {
//   		led=0;
//		for(i=0;i<30000;i++);
//		led=1;
//		for(i=0;i<30000;i++);
//
// 	}
//}
#include<reg52.h>
void main()
{
	unsigned int i=0;
	while(1)
 	{
		P2=0xFE;
		for(i=0;i<30000;i++);
		P2=0xFD;
		for(i=0;i<30000;i++);  
		P2=0xFB;
		for(i=0;i<30000;i++);  
		P2=0xF7;
		for(i=0;i<30000;i++);  
		P2=0xEF;
		for(i=0;i<30000;i++);  
		P2=0xFDDF;
		for(i=0;i<30000;i++);  
		P2=0xBF;
		for(i=0;i<30000;i++);  
		P2=0x7F;
		for(i=0;i<30000;i++);  
	}
}