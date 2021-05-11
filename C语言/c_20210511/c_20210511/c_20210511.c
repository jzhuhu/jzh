//输入一个字符，判别是否为大写字母，如果是转换成小写，如果不是直接输出
//#include<stdio.h>
//int main()
//{
//	char c1, c2;
//	printf("请输入一个字符：\n");
//	c1 = getchar();
//	c2 = (c1 >= 'A'&&c1 <= 'Z' )? (c1 + 32) : c1;
//	putchar(c2);
//	putchar('\n');
//	return 0;
//}
//实现符号函数
//#include<stdio.h>
//int main()
//{
//	float a;
//	printf("请输入一个数字：\n");
//	scanf_s("%f", &a);
//	if (a >= 0)
//	{
//		if (a > 0)
//		{
//			printf("1\n");
//		}
//		else
//		{
//			printf("0\n");
//		}
//	}
//	else printf("-1\n");
//
//	return 0;
//}

//由等级得出学生的成绩范围
//#include<stdio.h>
//int	main()
//{
//	char g;
//	printf("请输入您的等级：\n");
//	g = getchar();
//	switch (g)
//	{
//	case 'A':printf("85以上\n"); break;
//	case 'B':printf("70-84\n"); break;
//	case 'C':printf("60-69\n"); break;
//	case 'D':printf("60以下\n"); break;
//	default:printf("输入错误\n");
//		break;
//	}
//	return 0;
//}
//有三个整数abc由键盘输入，输出其中最大的数
//#include<stdio.h>
//int main()
//{
//	int a, b, c,max;
//	printf("请输入三个数字\n");
//	scanf_s("%d%d%d", &a, &b, &c);
//	max = a > b ? a : b;
//	if (max<c)
//	{
//		max = c;
//	}
//	printf("max=%d\n", max);
//	return 0;
//}
//输入小于1000的正数，要求输出平方根（如果不是整数输出整数部分），要求检查是否小于1000
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int a, b;
//	printf("请输入小于1000的整数\n");
//	scanf_s("%d", &a);
//	if (a>1000||a<0)
//	{
//		printf("数据错误，请重新输入,使得数据小于1000\n");
//		scanf_s("%d", &a);
//	}
//	
//	b = sqrt(a);
//	printf("%d\n", b);
//
//	return 0;
//}
//利用循环
//#include<stdio.h>
//#include<math.h>
//#define M 1000
//int main()
//{
//	int a, b;
//	printf("请输入一个小于1000的整数\n");
//	scanf_s("%d", &a);
//	while (a>M||a<0)
//	{
//		printf("数据错误，请重新输入,使得数据小于1000\n");
//		scanf_s("%d", &a);
//		b = sqrt(a);
//	}
//	printf("%d\n", b);
//
//	return 0;
//}
//分段函数的计算
//#include<stdio.h>
//int main()
//{
//	float x, y;
//	scanf_s("%f", &x);
//	if (x<1)
//	{
//		y = x;
//	}
//	else if (x>=1&&x<10)
//	{
//		y = 2.0*x - 1;
//	}
//	else
//	{
//		y = 3.0*x - 11;
//	}
//	printf("%f", y);
//	return 0;
//}
//输入成绩后输出等级
//#include<stdio.h>
//int main()
//{
//	int grade, b;
//	scanf_s("%d", &grade);
//	b = grade / 10;
//	if (b<6)
//	{
//		b = 5;
//	}
//	switch (b)
//	{
//	case 9:printf("你的成绩等级为A\n"); break;
//	case 8:printf("你的成绩等级为B\n"); break;
//	case 7:printf("你的成绩等级为C\n"); break;
//	case 6:printf("你的成绩等级为D\n"); break;
//	case 5:printf("你的成绩等级为E\n"); break;
//	}
//	return 0;
//}
//课本答案
//#include<stdio.h>
//int main()
//{
//	float score;
//	char grade;
//	printf("请输入您的成绩：\n");
//	scanf_s("%f", &score);
//	while (score>100||score<0)
//	{
//		printf("成绩输入错误，请重新输入\n");
//		scanf_s("%f", &score);
//	}
//	switch ((int)(score/10))
//	{
//	case 10:
//	case 9:printf("你的成绩等级为A\n"); break;
//	case 8:printf("你的成绩等级为B\n"); break;
//	case 7:printf("你的成绩等级为C\n"); break;
//	case 6:printf("你的成绩等级为D\n"); break;
//	case 5:
//	case 4:
//	case 3:
//	case 2:
//	case 1:
//	case 0:printf("你的成绩等级为E\n"); break;
//	}
//	return 0;
//}
//给出一个不多于5位的整数
#include<stdio.h>
int main()
{
	int num,a,b,c,d,e;
	printf("请输入正整数（0-99999）：\n");
	scanf_s("%d", &num);
	while (num<=0||num>=100000)
	{
		printf("输入错误，请重新输入\n");
		scanf_s("%d", &num);
	}
	if (num>9999)
	{
		printf("该数字为5位数\n");
		a = num / 10000;
		b = (num - a * 10000) / 1000;
		c = (num - a * 10000 - b * 1000) / 100;
		d = (num - a * 10000 - b * 1000 - c * 100) / 10;
		e = num - a * 10000 - b * 1000 - c * 100 - d * 10;
		printf("%d\t%d\t%d\t%d\t%d\n", a, b, c, d, e);
		printf("%d%d%d%d%d\n", e, d, c, b, a);

	}
	else if (num<=9999&&num>999)
	{
		printf("该数字为4位数\n");
		b = (num / 1000);
		c = (num - b*1000) / 100;
		d = (num  - b * 1000 - c * 100) / 10;
		e = num - b * 1000 - c * 100 - d * 10;
		printf("%d\t%d\t%d\t%d\n",  b, c, d, e);
		printf("%d%d%d%d\n", e, d, c, b);
	}
	else if (num<=999 && num>99)
	{
		printf("该数字为3位数\n");
		c = num  / 100;
		d = (num - c * 100) / 10;
		e = num  - c * 100 - d * 10;
		printf("%d\t%d\t%d\n", c, d, e);
		printf("%d%d%d\n", e, d, c);
	}
	else if (num<=99 && num>9)
	{
		printf("该数字为2位数\n");
		d = num  / 10;
		e = num - d * 10;
		printf("%d\t%d\n",  d, e);
		printf("%d%d", e, d);

	}
	else 
	{
		printf("该数字为1位数\n");
		printf("%d\n", num);
		printf("%d\n", num);
	}

	return 0;
}