//习题3.1
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n;
//	printf("请输入年份：\n");
//	scanf_s("%d", &n);
//	double p, r = 0.07;
//	p = pow(1 + r, n);
//	printf("国民生产总值增长了%f\n", p);
//
//	return 0;
//}

//习题3.2

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double r1 = 0.015, r2 = 0.021, r3 = 0.0275, r4 = 0.03, r5 = 0.0035, p1, p2, p3, p4, p5,s;
//	p1 = 1000 * (1 + 5*r4);//一次性存5年
//	p2 = 1000 * (1 + 2 * r2)*(1 + 3 * r3);//先存2年再存3年
//	p3 = 1000 * (1 + 3 * r3)*(1 + 2 * r2);//先存3年再存2年
//	p4 = 1000 * (1 + r1)* (1 + r1)* (1 + r1)* (1 + r1)* (1 + r1);//一年一年存
//	s = pow(1 + r5 / 4, 20);
//	p5 = 1000 * s;
//	printf("p1=%f\np2=%f\np3=%f\np4=%f\np5=%f\n", p1, p2, p3, p4, p5);
//		return 0;
//}

//习题3.3
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int d = 300000, p = 6000;
//	double r = 0.01,m;
//	m = (log(p) - log(p - d*r)) / log(1 + r);
//	printf("%5.1f\n", m);
//
//	return 0;
//}
//习题3.4
//#include<stdio.h>
//int main()
//{
//	int c1, c2;
//	c1 = 97;
//	c2 = 98;
//	printf("%c,%c\n", c1, c2);//说明用char赋值时范围在0到127之间
//	printf("%d,%d\n",c1, c2);
//
//	return 0;
//}
//习题3.5
//#include<stdio.h>
//int main()
//{
//	int a, b;
//	float x, y;
//	char c1, c2;
//	scanf_s("a=%db=%d", &a, &b);
//	scanf_s("%f%e", &x, &y);
//	scanf_s("%c%c", &c1, &c2);
//	printf("a=%d,b=%d,x=%f,y=%f,c1=%c,c2=%c\n", a, b, x, y, c1, c2);
//		return 0;
//}
//习题3.6
//#include<stdio.h>
//int main()
//{
//	char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a';
//	c1 += 4;
//	c2 += 4;
//	c3 += 4;
//	c4 += 4;
//	c5 += 4;
//	printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a';
//	c1 += 4;
//	c2 += 4;
//	c3 += 4;
//	c4 += 4;
//	c5 += 4;
//	putchar(c1);
//	putchar(c2);
//	putchar(c3);
//	putchar(c4);
//	putchar(c5);
//	putchar('\n');
//	return 0;
//}
//习题3.7 
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	float r,l,s,S,v,V,pai=3.14;
//	int h;
//	printf("请输入圆半径和圆柱高：\n");
//	scanf_s("%f,%d", &r, &h);
//	l = 2 * pai*r;
//	s = pai*pow(r, 2);
//	S = 4 * pai*pow(r, 2);
//	v = 4 / 3 * pai*pow(r, 3);
//	V = s*h;
//	printf("圆周长为：%-5.2f\n圆面积为：%-5.2f\n圆球表面积为：%-5.2f\n圆球体积为：%-5.2f\n圆柱体积为：%-5.2f\n", l, s, S, v, V);
//	return 0;
//}
//习题3.8
//#include<stdio.h>
//int main()
//{
//	char c1, c2;
//	c1 = getchar();
//	c2 = getchar();
//	putchar(c1);
//	putchar(c2);
//	putchar('\n');
//	printf("%c%c\n", c1, c2);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	char c = 'k';
//	int i = 1, j = 2, k = 3;
//	float x = 3e+5, y = 0.85;
//	printf("%d,%d\n", 'a' + 5 < c, -i - 2 * j >= k + 1);
//	printf("%d,%d\n", 1 < j < 5, 25 <= x + y);
//	printf("%d,%d\n", i + j + k == -2 * j, k == j == i + 5);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char c = 'k';
//	int i = 1, j = 2, k = 3;
//	float x = 3e+5, y = 0.85;
//	printf("%d,%d\n", !x*!y, !!!x);
//	printf("%d,%d\n", x || i&&j - 3, i < j&&x < y); 
//	printf("%d,%d\n", i == 5 && c && (j = 8), x + y || i + j + k);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b, max;
//	printf("请输入两个数字:\n");
//	scanf_s("%d%d", &a, &b);
//	max = a;
//	if (max < b)
//	{
//		max = b;
//	}
//	printf("max=%d", max);
//	
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b;
//	printf("请输入两个数字：\n");
//	scanf_s("%d%d", &a, &b);
//	if (a>b)
//	{
//		printf("max=%d\n", a);
//	}
//	else
//	{
//		printf("max=%d\n", b);
//	}
//	return 0;
//}

#include<stdio.h>
int main()
{
	char c;
	printf("请输入一个字符:\n");
	c = getchar();
	if (c < 32)	printf("这是一个控制符\n");
	else if (c>='0'&&c<='9')
	{
		printf("这是一个数字\n");
	}
	else if (c>='A'&&c<='Z')
	{
		printf("这是一个大写字母\n");
	}
	else if (c >= 'a'&&c <= 'z')
	{
		printf("这是一个小写字母\n");
	}
	else
	{
		printf("这是其他字符\n");
	}
	return 0;
}