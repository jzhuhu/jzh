#if(0)
#include "1118.h"
#include<stdio.h>
int swap(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
	return 0;
}

int main()
{
	int a = 8, b = 4;
	swap(a, b);
	printf("a=%d\tb=%d\t", a, b);
	return 0;
}
#elif(0)
#include "1118.h"
#include<stdio.h>
int swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}

int main()
{
	int a = 8, b = 4;
	swap(&a, &b);
	printf("a=%d\tb=%d\t", a, b);
	return 0;
}
#elif(0)
#include<stdio.h>
int clear_array(int *x,int y)
{
	while (y > 0)
	{
		x[--y] = 0;
	}
}
int main()
{
	int a[10],i;
	for (i = 0; i < 10; i++)
	{
		a[i] = i;
		printf("%d\t", a[i]);
	}
	clear_array(a, 10);
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}
#elif(0)
#include<stdio.h>
void binary_to_ascii(unsigned int value)
{
	unsigned int quotient;
	quotient = value / 10;
	if (quotient != 0)
	{
		binary_to_ascii(quotient);
	}
	putchar(value % 10 + '0');

}
int main()
{
	binary_to_ascii(4396);

	return 0;
}
#elif(0)
#include<stdio.h>
int factorial(unsigned int n)
{
	if (n <= 0)
		return 1;
	else
		return n*factorial(n - 1);

}
int main()
{
	int a;
	a=factorial(5);
	printf("%d\t", a);
	return 0;
}
#elif(0)
#include<stdio.h>
int factorial(unsigned int n)
{
	int result=1;
	for (; n > 0; n--)
	{
		result*=n;
	}
	return result;

}
int main()
{
	int a;
	a = factorial(5);
	printf("%d\t", a);
	return 0;
}
#elif(1)
#include<stdio.h>
#include<stdarg.h>
int average(int n,...)
{
	int i;
	float sum = 0;
	va_list var_arg;
	va_start(var_arg, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(var_arg, int);
	}
	va_end(var_arg);
	return sum/n;

}
int main()
{
	float a;
	a = average(5,1,2,3,4,5);
	printf("%f\t", a);
	return 0;
}

#endif



