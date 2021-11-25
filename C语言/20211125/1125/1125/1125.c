#include<stdio.h>
#include<stddef.h>
#if 0
int main()
{
	int a;
	struct MyStruct
	{
		char a;
		int b;
		char c;
	};
	a=offsetof(struct MyStruct,c);
	printf("%d", a);
}
#elif 0
int main()
{
	int a;
	struct MyStruct
	{
		int a;
		char b;
		char c;
	};
	a = offsetof(struct MyStruct, c);
	printf("%d",a);
}
#elif 0
int main()
{
	union 
	{
		float f;
		int i;
	}fi;
	fi.f = 3.14159;
	printf("%f", fi.f);
	putchar(10);
	printf("%d", fi.f);
}
#elif 0
int main()
{
	union MyUnion
	{
		int a;
		float b;
		char c[4];
	}x = {5};

	printf("%d", x.a);
	putchar(10);
	printf("%f", x.b);
	putchar(10);
	printf("%d", x.c);
	putchar(10);
}
#elif 0
int main()
{
	union MyUnion
	{
		int a ;
		int b;
		int c;
	}x ;

	printf("%d", x.a);
	putchar(10);
	printf("%d", x.b);
	putchar(10);
	printf("%d", x.c);
	putchar(10);
}
#elif 1
int main()
{
	enum MyUnion
	{
		 a ,
		 b=2,
		 c,
	}x;

	printf("%d", a);
	putchar(10);
	printf("%d", b);
	putchar(10);
	printf("%d", c);
	putchar(10);
}
#endif