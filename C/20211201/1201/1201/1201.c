#include<stdio.h>
#if 0
int main()
{
	int i;
	int *pi;
	static int **ppi;
	printf("%d\n", ppi);
	printf("%d\n", &ppi);
	*ppi = 5;
}
#elif 1
int f( int a,int  b)
{
	return a*b;
}


int main()
{
	int h;
	int (*fp)(int a,int b)=f;
	h = (*fp)(2, 3);
	printf("%d\n", h);
}
#endif
