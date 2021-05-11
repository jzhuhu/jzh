#include<stdio.h>
//int main()
//{
//	printf("%d\n", sizeof(short));
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b, c, d;
//	unsigned u;
//	a = 12, b = -24, u = 10;
//	c = a + u;
//	d = b + u;
//	printf("a+u=%d,b+u=%d\n", c, d);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	double a, b;
//	a = 123456.789e5;
//	b = a + 20;
//	printf("%f\n", a);
//	printf("%f\n", b);
//	return 0;
//}
//#include<stdio.h>
//void main()
//{
//	printf("%f\n", 3/2.0);
//
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 5, b = 6, c = 7;
//	printf("ab c\tde\rf\n");
//	printf("hijk\tL\bM\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a, b;
//	a = 'a';
//	b = 'b';
//	printf("%c,%c\n", a, b);
//	printf("%d,%d\n", a, b);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a, b;
//	a = 'a';
//	b = 'b';
//	a = a - 32;
//	b = b - 32;
//	printf("%c,%c\n%d,%d\n", a, b, a, b);
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a;
//	int b;
//	a = 33;
//	b = 33;
//	printf("%c,%c\n", a, b);
//	printf("%d,%d\n", a, b);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	float PI = 3.14159;
//	int s, r = 5;
//	s = r*r*PI;
//	printf("s=%d\n", s);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	float f = 5.75;
//	printf("(int)f=%d,F=%f\n", (int)f, f);
//
//
//
//
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//
//
//	printf("\n\n%d,%d\n", 20 / 7, -20 / 7);
//	printf("%f,%f\n", 20.0 / 7, -20.0 / 7);
//	return 0;
//
////}
//#include<stdio.h>
//int main()
//{
//
//
//
//	printf("%d\n", 100 % 3);
////
////	return 0;
////}
//#include<stdio.h>
//int main()
//{
//
//
//
//	printf("7¡Â2=%d...........%d", 7 / 2, 7 % 2);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 8;
//	//printf("%d\n", ++i);
//	//printf("%d\n", --i);
//	//printf("%d\n", i++);
//	//printf("%d\n", i--);
//
//	printf("%d\n", -i--); 
//	printf("%d\n", -i++);
//
//
//
//
//
//
//
//
////}
//#include<stdio.h>
//int main()
//{
//	int i = 5, j = 5, p, q;
//	p = i++ + i++ + i++;
//	q =++j + ++j + ++j;
//	printf("%d,%d,%d,%d", p, q, i, j);
//
//
//
//
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a, b = 322;
//	float x, y = 8.88;
//	char c1 = 'k', c2;
//	a = y;
//	x = b;
//	a = c1;
//	c2 = b;
//	printf("%d,%f,%d,%c\n", a, x, a, c2);
//
//
//
//
//	return 0;
//}
#include<stdio.h>
int main()
{

	int a= 2, b = 4, c = 6, x, y;
	y = (x = a + b), (b + c);
	printf("y=%d,x=%d", y, x);


	return 0;
}