//#include<stdio.h>
//int main()
//{
//
//	printf("%f\n", 1.0 / 3.0);
//	return 0;
//}
  


//#include<stdio.h>
//int main()
//{
//
//
//
//	unsigned short price = 55;
//	printf("%u\n", price);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char c = '?';
//	printf("%d\n%c\n", c, c);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char c1, c2;
//	c1 = 'A';
//	c2 = c1 + 32;
//	printf("%c\n%d\n", c2, c2);
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	float a = 8.5;
//	printf("%d\n", (int)a % 3);
//
//
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c,s,S;
//	a = 3.67;
//	b = 5.43;
//	c = 6.21;
//	s = (a + b + c) / 2;
//	S = sqrt(s*(s - a)*(s - b)*(s - c));
//	printf("%f\t%f\t%f\t%f\t%f\t", a, b, c, s, S);
//
//
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int i = 289;
//	char c ;
//	c = i;
//	printf("%c\n", c);
//
//
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c, disc, x1, x2, p, q;
//	scanf_s("%lf,%lf,%lf", &a, &b, &c);
//	disc = b*b - 4 * a*c;
//	p = -b / (2.0*a);
//	q = sqrt(disc) / (2.0*a);
//	x1 = p + q;
//	x2 = p - q;
//	printf("x1=%6.3f\nx2=%6.3f\n",x1, x2);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char ch = 'a';
//	printf("%5c\n", ch);
//
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	short a = 377;
//	printf("%c\n", a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	
//	printf("%s\n", "CHINA");
//
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	double a=1.0;
//
//	printf("%55.50f\n", a/3);
//
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	double a;
//	a = 1000 / 3.0;
//	printf("%-25.15f\n%25.15f\n",a,a);
//
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	/*char ch = 'a'*/;
//	printf("%E\n",123.456);
//
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = -1;
//	printf("%d\t%o\n", a,a);
//
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	printf("%%\n");
//
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 66, b = 79, c = 89;
//	putchar(a);
//	putchar(b);
//	putchar(c);
//	putchar('\n');
//
//
//
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//
//	putchar('\101');
//	putchar('\'');
//	putchar('\015');
//
//
//
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//	char a, b, c;
//	a=getchar();
//	b = getchar();
//	c = getchar();
//	putchar(a);
//	putchar(b);
//	putchar(c);
//	putchar('\n');
//
//
//
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	putchar(getchar());
//	putchar(getchar());
//	putchar(getchar());
//	putchar('\n');
//
//
//
//	return 0;
//}


#include<stdio.h>
int main()
{
	int a;
	a = getchar();
	a = a + 32;
	putchar(a);
	putchar('\n');

	return 0;
}
