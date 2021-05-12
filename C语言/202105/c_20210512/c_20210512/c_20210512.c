//用goto语句实现100的累加
//#include<stdio.h>
//int main()
//{
//	int i=1, sum = 0;
//	loop:if (i <= 100)
//	{
//		sum = sum + i;
//		i++;
//		goto loop;
//	}
//		printf("%d\n", sum);
//
//	return 0;
//}
//用while实现100的累加
//#include<stdio.h>
//int main()
//{
//	int i = 1, sum = 0;
//	while (i<=100)
//	{
//		sum = sum + i;
//		i++;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//用do....while实现100的累加
//#include<stdio.h>
//int main()
//{
//	int i = 1, sum=0;
//	do
//	{
//		sum = sum + i;
//		i++;
//	} while (i <= 100);
//	printf("%d\n", sum);
//	return 0;
//}
//用for语句实现100的累加
//#include<stdio.h>
//int main()
//{
//	int i = 1, sum = 0;
//	for ( ; i<=100; )
//	{
//		sum = sum + i;
//		i++;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//统计从键盘输入一行字符的个数
//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	printf("请输入一行字符,以回车键结束：\n");
//	while (getchar()!='\n')
//	{
//		n++;
//	}
//	printf("您一共输入%d个字符\n", n);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 0,n;
//	printf("请输入正整数n\n");
//	scanf_s("%d", &n);
//	while (n--)
//	{
//		printf("%d\n", ++a * 2);//即使只有一个语句也要用大括号括起来
//	}
//
//	return 0;
//}
//循环的嵌套
//#include<stdio.h>
//int main()
//{
//	int i, j, k;
//	for (size_t i = 0; i < 2; i++)
//		for (size_t j = 0; j < 2; j++)
//			for (size_t k = 0; k < 2; k++)
//				printf("%d\t%d\t%d\n", i, j, k);
//	return 0;
//}
//输出图形,使得*与行数相关
//#include<stdio.h>
//int main()
//{
//	int i, j;
//	for (size_t i = 1; i < 7; i++)
//	{
//		if (i>1)
//		{
//			printf("\n");
//		}
//
//		for (size_t j = 1; j <= i; j++)
//		{
//			putchar('*');
//		}
//	}
//	putchar('\n');
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i, j;
//	for (size_t i = 1; i < 7; i++)
//	{
//		for (size_t j = 1; j <= i; j++)
//		{
//			putchar('*');
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}
//有1234四个数字，能组成多少个互不相同且无重复数字的三位数
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	for (size_t a = 1; a < 5; a++)
//	for (size_t b = 1; b < 5; b++)
//	for (size_t c = 1; c < 5; c++)
//	if ((a != b) && (a != c) && (b != c))
//	{
//		printf("%d%d%d\n", a, b, c);
//	}
//
//	return 0;
//}
//计算圆的面积
//#include<stdio.h>
//int main()
//{
//	int r;
//
//	double pi = 3.14159, aera;
//	for (size_t r = 0; r < 10; r++)
//	{
//		aera = pi*r*r;
//		if (aera>100)
//		{
//			break;
//		}
//		printf("r=%d\taera=%6.2lf\n", r, aera);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	char c;
//	while (1)
//	{
//		c = '\0';
//		while (c!=13&&c!=27)
//		{
//			c = getch();
//			printf("%c\n", c);
//		}
//		if (c == 27)	break;
//		i++;
//		printf("The No is %d\n", i);
//	}
//	printf("the end\n");
//	return 0;
//}
//#include<stdio.h>
//#include<conio.h>
//int main()
//{
//	char ch;
//	for (;;)
//	{
//		ch = _getch();
//		if (ch == 27)
//		{
//			break;
//		}
//		if (ch == 13)
//		{
//			continue;
//		}
//		_putch(ch);
//	}
//	_getch();
//}

//把100-200之间不能被3整除的数输出
#include<stdio.h>
int main()
{
	int i;
	for (i = 100; i <= 200; i++)
	{
		if (i % 3 == 0)
		{
			continue;
		}
		printf("%d\n", i);
	}
	return 0;
}
