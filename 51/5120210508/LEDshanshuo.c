#include<reg52.h>
sbit LED=P2^1;
int main()
{
	unsigned int i=0;
	while(1)
	{
		LED=0;
		for(i=0;i<30000;i++);
		LED=1;
		for(i=0;i<30000;i++);
	
	}

}