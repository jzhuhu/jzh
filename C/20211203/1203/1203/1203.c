#include<stdio.h>
#define DUBGE	printf("FILE is %s,LINE is %d\r\n\
x=%d,y=%d,z=%d",__FILE__,__LINE__,x,y,z)
#define SQUARE(x)	(x)*(x)
int main()
{
	int x=0, y=5, z=0;
	//x *= 2;
	//y += x;
	//z = x*y;
	//DUBGE;
	y = SQUARE(5+1);
	printf("%d\r\n", y);
	return 0;
}