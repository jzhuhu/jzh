//#include<stdio.h>
//int main()
//{
//	int a;
//	a = 5;
//	if (a==5)
//	{
//		printf("a equals 5!!\n");
//	}
//	else
//	{
//		printf("a is %d\n", a);
//	}
//	return 0;
//}

//成绩分等级
//#include<stdio.h>
//int main()
//{
//	int a;
//	printf("请输入成绩：\n");
//	a = getchar();
//	/*scanf_s("%d", &a);*/
//	if (a<60)
//	{
//		printf("等级为E\n");
//	}
//	else if (60 <= a &&a<70)
//	{
//		printf("等级为D\n");
//	}
//	else if (70 <= a &&a<80)
//	{
//		printf("等级为C\n");
//	}
//	else if (80 <= a &&a<90)
//	{
//		printf("等级为B\n");
//	}
//	else if (90<= a &&a<100)
//	{
//		printf("等级为A\n");
//	}
//	else 
//	{
//		printf("成绩输入错误\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a;
//	a = getchar();
//
//	printf("%c\n", a);
//
//	return 0;
//}
//方法一
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	printf("请输入三个数字：\n");
//	scanf_s("%d%d%d", &a, &b, &c);
//	if (a < b&&b < c)
//	{
//		printf("%d,%d,%d\n", a, b, c);
//	}
//	if (a < c&&c < b)
//	{
//		printf("%d,%d,%d\n", a, c, b);
//	}
//	if (b < a&&a < c)
//	{
//		printf("%d,%d,%d\n", b, a, c);
//	}
//	if (b < c&&c < a)
//	{
//		printf("%d,%d,%d\n", b, c, a);
//	}
//	if (c < a&&a < b)
//	{
//		printf("%d,%d,%d\n", c, a, b);
//	}
//	if (c < b&&b < a)
//	{
//		printf("%d,%d,%d\n", c, b, a);
//	}
//	return 0;
//}
//方法二
//#include<stdio.h>
//int main()
//{
//	int a, b, c,t;
//	printf("请输入三个数字：\n");
//	scanf_s("%d%d%d", &a, &b, &c);
//	if (a>b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a>c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b>c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d\t%d\t%d\t", a, b, c);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b;
//	printf("请输入两个数字A、B：\n");
//	scanf_s("%d%d", &a, &b);
//	if (a!=b)
//	if (a > b)	printf("A>B\n");
//	else     printf("A<B\n");
//	else     printf("A=B\n");
//	return 0;
//}

//方法二
//#include<stdio.h>
//int main()
//{
//	int a, b;
//	printf("please input A,B:\n");
//	scanf_s("%d%d", &a, &b);
//	if (a==b)	
//	{
//		printf("A=B\n");
//	}
//	else if (a > b)
//	{
//		printf("A>B\n");
//	}
//	else
//	{
//		printf("A<B\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, max;
//	printf("请输入两个数字：\n");
//	scanf_s("%d%d", &a, &b);
//	printf("max=%d\n", a > b?a:b);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char ch;
//	ch = getchar();
//	ch = ch >= 'A'&&ch <= 'Z' ? ch + 32 : ch;
//	printf("%c\n", ch);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i;
//	printf("Please input a number:\n");
//	scanf_s("%d", &i);
//	switch (i)
//	{
//	case 1:printf("星期一\n"); break;
//	case 2:printf("星期二\n"); break;
//	case 3:printf("星期三\n"); break;
//	case 4:printf("星期四\n"); break;
//	case 5:printf("星期五\n"); break;
//	case 6:printf("星期六\n"); break;
//	case 7:printf("星期日\n"); break;
//	default:printf("error\n");
//		break;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c,t;
//	printf("请输入三个整数：\n");
//	scanf_s("%d%d%d", &a, &b, &c);
//	if (a>b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a>c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b>c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("max=%d\tmin=%d\n", c, a);
//	return 0;
//}

//方法二
//#include<stdio.h>
//int main()
//{
//	int a, b, c, min, max;
//	printf("请输入三个数字\n");
//	scanf_s("%d%d%d", &a, &b, &c);
//	if (a<b)
//	{
//		min = a;
//		max = b;
//	}
//	else
//	{
//		min = b;
//		max = a;
//	}
//	if (max<c)
//	{
//		max = c;
//	}
//	if (min>c)
//	{
//		min = c;
//	}
//	printf("max=%d\tmin=%d\n", max, min);
//	return 0;
//}
//计算器程序，当用户输入运算数和四则运算符，输出计算结果
//#include<stdio.h>
//int main()
//{
//	double a, b;
//	char c;
//	printf("请输入运算数和四则运算符：\n");
//	scanf_s("%lf,%lf,%c", &a, &b, &c);
//	switch (c)	
//	{
//		case '+':printf("%lf", a + b); break; 
//		case '-':printf("%lf", a - b); break;
//		case '*':printf("%lf", a*b); break;
//		case '/':printf("%lf", a / b); break;
//		default:printf("输入错误，请重新输入\n");
//		break;
//	}
//	return 0;
//}
//输入一个年份判断是否为闰年
//#include<stdio.h>
//int main()
//{
//	int a,b,c,d;
//	printf("请输入年份\n");
//	scanf_s("%d", &a);
//	b = a %4;
//	c = a %100;
//	d = a %400;
//	if (b==0)
//	{
//		if (c!=0)
//		{
//			printf("%d是闰年\n", a);
//		}
//		else if (d==0)
//		{
//			printf("%d是闰年\n", a);
//		}
//		else
//		{
//		if (d == 0)
//			{
//				printf("%d是闰年\n", a);
//			}
//			else
//			{
//				printf("%d不是闰年\n", a);
//			}
//		} 
//	}
//	else
//	{
//		printf("%d不是闰年\n", a);
//	}
//	
//	

//}
//运输公司计算运费
//#include<stdio.h>
//int main()
//{
//	float p, w, f, d;
//	int  c, s;
//	printf("请输入单价、重量、距离\n");
//	scanf_s("%f,%f,%d", &p, &w, &s);
//	if (s>=3000)
//	{
//		c= 12;
//	}
//	else
//	{
//		c = s / 250;
//	}
//	switch (c)
//	{
//		case 0:d = 0; break;
//		case 1:d = 2; break;
//		case 2:
//		case 3:d = 5; break;
//		case 4:
//		case 5:
//		case 6:
//		case 7:d = 8; break;
//		case 8:
//		case 9:
//		case 10:
//		case 11:d = 10; break;
//		case 12:d = 15; break;
//	}
//	f = p*w*s*(1 - d/100);
//	printf("总运费为%f\n", f);
//	return 0;
//}

 //求解方程的根
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c, disc, p1, p2,x1,x2;
//	printf("请输入系数A、B、C\n");
//	scanf_s("%lf%lf%lf", &a, &b, &c);
//	disc = pow(b, 2) - 4 * a*c;
//	if (disc<0)
//	{
//		printf("该方程无解\n");
//	}
//	else
//	{
//		p1 = -b / (2.0*a);
//		p2 = sqrt(disc) / (2.0*a);
//		x1 = p1 + p2;
//		x2 = p1 - p2;
//		printf("x1=%lf\tx2=%lf\n", x1, x2);
//	}
//	return 0;
//}