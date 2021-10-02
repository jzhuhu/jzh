#include<stdio.h>
int main()
{
	int a = 100, b = 10;
	int *i_point1, *i_point2;
	i_point1 = &a;
	i_point2 = &b;
	printf("%d\t%d\t\n", a, b);
	printf("%d\t%d\t\n", *i_point1, *i_point2);
}