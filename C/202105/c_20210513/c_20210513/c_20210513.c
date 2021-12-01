//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n=1,b=1,c;
//	double pi,a;
//	while (n<1000000)//错误示范
//	{
//		c = pow(-1, b);
//		n = n + 2;
//		a = c*(1.0 / n) + 1;
//	}
//	printf("%lf\n", a * 4);
//}
//计算派的值
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int sign = 1;
//	double pi = 0, n = 1, term = 1;
//	while (fabs(term)>=1e-6)
//	{
//		pi = pi + term;
//		n = n + 2;
//		sign = -sign;
//		term = sign / n;
//	}
//	pi = pi * 4;
//	printf("%lf\n", pi);
//
//	return 0;
//}
//方法二
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int sign = 1;
//	double	pi = 0, n = 1, term = 1;
//	do
//	{
//		pi = pi + term;
//		sign = -sign;
//		n = n + 2;
//		term = sign / n;
//
//	} while (fabs(term)>=1e-6);
//	printf("%lf\n", pi * 4);
//
//
//	return 0;
//}
//方法三
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int sign=1;
//	double pi = 0, n = 1, term = 1;
//	for ( ; fabs(term) >= 1e-6; )
//	{
//		pi = pi + term;
//		sign = -sign;
//		n = n + 2;
//		term = sign / n;
//	}
//	printf("%lf\n", pi*4);
//
//	return 0;
//}
//求Fibonacci数列的前40个数
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n = 1,a=1,b=1,c;
//	printf("1\n1\n");
//	while (n<=38)
//	{
//		c = a + b;
//		printf("%d\n", c);
//		a = b;
//		b = c;
//		n = n + 1;
//	}
//
//	return 0;
//}
//方法2
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n = 1, a = 1, b = 1, c;
//	printf("1\n1\n");
//	for ( n = 0; n <38; n++)
//	{
//		c = a + b;
//		printf("%d\n", c);
//		a = b;
//		b = c;
//	}
//方法三
//#include<stdio.h>
//int main()
//{
//	int n = 1, a = 1, b = 1, c;
//	printf("%d\t%d\n", a, b);
//	do
//	{
//		c = a + b;
//		printf("%d\t", c);
//		a = b;
//		b = c;
//		n++;
//		if (n%2==0)
//		{
//			printf("\n");
//		}
//
//	} while (n<=38);
//
//	return 0;
//}
//写一个程序，允许输入一个数m，并判断m是否为素数
//#include<stdio.h>
//int main()
//{
//	int i=2, n;
//	printf("请输入大于3的整数\n");
//	scanf_s("%d", &n);
//	while (n>i)
//	{
//		if (n%i == 0)	{ printf("%d不是素数\n", n); break; }
//		//else
//		//{
//		//	if ((i==n-1)&&((n%i)!=0))
//		//	{
//		//		printf
//		//	}
//		//}
//		//if (true)
//		//{
//
//		//}
//		//i = i + 1;
//		else
//		{
//			printf("%d是素数\n", n); break;
//		}
//		i = i + 1;
//	}
//	return 0;
//}说明该程序无法用while实现
//for
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n=15, i = 2,k;
//	//printf("请输入大于3的整数\n");
//	//scanf_s("%d", &n);
//	k = sqrt(n);
//	for (size_t i = 2; i < n; i++)
//	{
//		if (n%i==0)
//		{
//			break;
//		}
//	}
//	if (i<k)
//	{
//		printf("%d不是素数\n", n);
//	}
//	else
//	{
//		printf("%d是素数\n", n);
//	}
//
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int a = 26 ;
//	float b;
//	b = sqrt(a);
//	printf("%f", b);
//
//	return 0;
//}
//求100-200间全部素数并打印出来
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n , i , k;
//	for (n = 101; n <= 200; n=n+2)
//	{
//		k = sqrt(n);
//		for (i = 2; i <= k; i++)
//		if (n%i == 0)		break;
//		if (i>=k + 1)
//			{
//				printf("%d\n", n);
//			}
//
//	}
//
//
//	return 0;
//}
//译密码
//#include<stdio.h>
//int main()
//{
//	char ch;
//	printf("请输入电文：\n");
//	ch = getchar();
//	while(ch != '\n')
//
//	{
//		if (ch >= 'W'&&ch <= 'Z' || ch >= 'w'&&ch <= 'z')
//		{
//			ch = ch - 22;
//			//printf("%c", ch);
//		}
//		else if (ch >= 'A'&&ch <= 'V' || ch >= 'a'&&ch <= 'v')
//		{
//			ch = ch + 4;
//			//printf("%c", ch);
//		}
//		else
//		{
//			//printf("error\n");
//			break;
//		}
//		printf("%c", ch);
//		ch = getchar();
//		
//	}
//	printf("\n");
//	return 0;
//}

//while语句实现累加
//#include<stdio.h>
//int main()
//{
//	int sum = 0, i = 0;
//	while (i<=100)
//	{
//		sum = sum + i;
//		i++;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//do..while实现100的累加
//#include<stdio.h>
//int main()
//{
//	int i = 0, sum = 0;
//	do
//	{
//		sum = sum + i;
//		i++;
//	} while (i<=100);
//	printf("%d\n", sum);
//	return 0;
////}
//#include<stdio.h>
//int main()
//{
//	char c;
//	for (; (c =getchar())!='\n';)
//	{
//		printf("%c", c);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char c;
//	c = getchar();
//	printf("%c", c);
//
//
//
//	return 0;
//}
#include<stdio.h>
int main()
{
	char c;
	while ((c=getchar())!='\n')
	{
		printf("%c", c);
	}

	printf("\n");
	return 0;
}




