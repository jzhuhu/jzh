#if(0)
#include<stdio.h>
int main()
{
	void print_star();
	void print_message();
	print_star();
	print_message();
	print_star();
	return 0;
}
void print_star()
{
	printf("****************\n");
}
void print_message()
{
	printf("How do you do!\n");
}
#endif
#if(0)
#include<stdio.h>
float max(float x, float y)
{
	float z;
	z = x > y ? x : y;
	return z;
}
int main()
{
	float max(float x, float y);
	float a, b,c;
	printf("�����������Ƚϵ����֣�\n");
	scanf_s("%f%f", &a, &b);
	c = max(a, b);
	printf("���ֵ��%f\n", c);
	return 0;

}
#endif
#if(0)
#include<stdio.h>
int main()
{
	int f(int a, int b);
	int i = 2, p;
	p = f(i, ++i);//˵��������������������
	printf("%d\n", p);

	return 0;
}
int f(int a, int b)
{
	int c;
	if (a>b)
	{
		c = 1;
	}
	else if (a==b)
	{
		c = 0;
	}
	else
	{
		c = -1;
	}
	return c;
}
#endif
#if(0)
#include<stdio.h>
int main()
{
	float a, b,c;
	float add(float x, float y);
	printf("������a��b��ֵ\n");
	scanf_s("%f%f", &a, &b);
	c = add(a,b);
	printf("%f", c);
	return 0;
}
float add(float x, float y)
{
	float z;
	z = x + y;
	return z;
}
#endif
#if(0)
#include<stdio.h>
int main()
{
	double power(double x, double y);
	double x = 2, y = 3;
	double result;
	result = power(x, y);
	printf("%f\n", result);

}
double power(double x, double y)
{
	double z=1;
	int i;
	for ( i = 1; i < (int)(y+1); i++)
	{
		z = z*x;
	}
	return z;
}
#endif
#if(0)
//����s=2��ƽ���Ľ׳�+3��ƽ���Ľ׳�
#include<stdio.h>
int square(int a);
int factorial(int b);
int main()
{
	int i, s=0;
	for ( i = 2; i < 4; i++)
	{
		s = s + square(i);
	}
	printf("%d\n", s);
	return 0;
}
int square(int a)
{
	int k, r;
	int factorial(int b);
	k = a*a;
	r = factorial(k);
	return r;
}
int factorial(int b)
{
	int i;
	int n = 1;
	for ( i = b; i >0; i--)
	{
		n = n*i;
	}
	return n;
}
#endif
