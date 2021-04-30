//#include<stdio.h>
//int main()
//{
//	char a, b, c;
//	printf("请输入字符a,b,c:\n");
//	scanf_s("%c%c%c", &a, &b, &c);
//	printf("%c,%c,%c\n", a - 32, b - 32, c - 32);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	char a = 'B', b = 'o', c = 'k';
//	putchar(a); putchar(b); putchar(c); putchar('\t');
//	putchar('a'); putchar('b');
//	putchar('\n');
//	putchar(b); putchar(c);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char c;
//	printf("input a character\n");
//	c = getchar();
//	putchar(c);
//	putchar('\n');
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int a = 88, b = 89;
//	printf("%d%d\n", a, b);
//	printf("%d,%d\n", a, b);
//	printf("%c,%c\n",a, b);
//	printf("%e,%o\n", a, b);
//


//#include<stdio.h>
//int main()
//{
//	int a = 15;
//	float b = 123.1234567;
//	double c = 12345678.1234567;
//	char d = 'p';
//	printf("a=%d,%5d,%o,%x\n", a, a, a, a);
//	printf("b=%f,%lf,%5.4lf,%e\n", b, b, b, b);
//	printf("c=%lf,%f,%8.4lf\n",c, c, c);
//	printf("d-%c,%8c\n", d, d);
//


//#include<stdio.h>
//int main()
//{
//	int i = 8;
//	printf("%d\n%d\n%d\n%d\n%d\n%d\n",++i, --i, i++, i--, -i++, -i--);
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	int i = 8;
//	printf("%d\n", ++i);
//	printf("%d\n", --i);
//	printf("%d\n", i++);
//	printf("%d\n", i--);
//	printf("%d\n", -i++);
//	printf("%d\n", -i--);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	printf("input a,b,c\n");
//	scanf_s("%2d%3d%4d", &a, &b, &c);
//	printf("a=%d,b=%d,c=%d\n", a, b, c);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	char a, b;
//	printf("input character a,b\n");
//	scanf_s("%c,%c", &a, &b);
//	printf("%c%c\n",a,b);
//
//}
//
//#include<stdio.h>
//int  main()
//{
//	int a;
//	long b;
//	float c;
//	double d;
//	char e;
//	printf("\n int:%d \n long:%d \n float:%d \n double:%d \n char:%d \n", sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e));
//
//
//
//	return 0;
//}
#include<stdio.h>
#include<math.h>
int main()
{
	float a, b, c, s, S;
	printf("请输入三角形的三边长a、b、c:\n");
	scanf_s("%f,%f,%f", &a, &b, &c);
	s = (a + b + c) /2;
	S = sqrt(s*(s - a)*(s - b)*(s - c));
	printf("%f\n", S);
	return 0;
}