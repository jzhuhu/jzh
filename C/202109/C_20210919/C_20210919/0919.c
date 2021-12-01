#if (0)
#include<stdio.h>
int main()
{
	int a;
	int *point;
	a = 3;
	point = &a;
	*point = 5;
	printf("%d\t", *point);


}
#endif
#if(0)
//输入a和b两个整数，按照先大后小的顺序输出a和b
#include<stdio.h>
int main()
{
	int a, b;
	int *p1, *p2, *p;
	printf("please input two number:\n");
	scanf_s("%d%d", &a,&b);
	p1 = &a;
	p2 = &b;
	if (a<b)
	{
		//p = p1;
		//p1 = p2;
		//p2 = p;
		p1 = &b;
		p2 = &a;
	}
	printf("a=%d\tb=%d\n", a, b);
	printf("%d\t%d\n", *p1, *p2);
}
#endif
#if(0)
//输入a和b两个整数，按照先大后小的顺序输出a和b
#include<stdio.h>
int main()
{
	int swap(int *p1, int *p2);
	int a, b;
	int *point1, *point2;
	printf("please input two number\n");
	scanf_s("%d%d", &a, &b);
	point1 = &a;
	point2 = &b;
	if (a<b)
	{
		swap(point1, point2);
	}
	printf("%d\t%d\n", *point1, *point2);
	return 0;
}
int swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
#endif
#if(0)
#include<stdio.h>
int main()
{
	void exchange(int *p1,int *p2,int *p3);
	int a, b, c;
	int *point1, *point2, *point3;
	printf("please input three number:\n");
	scanf_s("%d%d%d", &a, &b, &c);
	point1 = &a;
	point2 = &b;
	point3 = &c;
	exchange(point1, point2, point3);
	printf("The order is:%d,%d,%d\n", *point1, *point2, *point3);
	return 0;
}
void exchange(int *p1, int *p2, int *p3)
{
	void swap(int *pt1, int *pt2);
	if (*p1<*p2)
	{
		swap(p1, p2);
	}
	if (*p1<*p3)
	{
		swap(p1, p3);
	}
	if (*p2<*p3)
	{
		swap(p2, p3);
	}
}
void swap(int *pt1, int *pt2)
{
	int temp;
	temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;
}
#endif
//通过指针引用数组元素
//有一个整型数组，里面有10个元素，要求输出全部元素
//#include<stdio.h>
//int main()
//{
//	int a[10];
//	int i;
//	printf("please input 10 number:\n");
//	for ( i = 0; i < 10; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//	for ( i = 0; i < 10; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[10];
//	int i;
//	printf("please input 10 number:\n");
//	for (i = 0; i < 10; i++)
//	{
//		scanf_s("%d", a+i);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(a+i));
//	}
//	printf("\n");
//	return 0;
//}
#if(0)
#include<stdio.h>
int main()
{
	int a[10];
	int i;
	int *p;
	printf("please input 10 number:\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", a+i);
	}
	for (p=a; p < (a+10); p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
	return 0;
}
#endif
#if(0)
#include<stdio.h>
int main()
{
	void inv(int x[], int n);
	int i, a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("The original array:\n");
	for ( i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	inv(a, 10);
	printf("The array has been inverted:\n");
	for ( i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
void inv(int x[], int n)
{
	int temp, i, j;
	int m = (n - 1) / 2;
	for ( i = 0; i <=m; i++)
	{
		j = n - 1 - i;
		temp = x[i];
		x[i] = x[j];
		x[j] = temp;
	}
	return;
}
#endif
#if(0)
#include<stdio.h>
int main()
{
	void inv(int *x, int n);
	int i, a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("The original array:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	inv(a, 10);
	printf("The array has been inverted:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
void inv(int *x, int n)
{
	int temp, *i, *j,*p;
	int m = (n - 1) / 2;
	i = x;
	j = n + x - 1;
	p = x + m;
	for ( ; i <=p; i++,j--)
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
	return;
}
#endif
#include<stdio.h>
int main()
{
	void inv(int *x, int n);
	int i, arr[10];
	int *p = arr;
	printf("The original array:\n");
	for (i = 0; i < 10; i++,p++)
	{
		scanf_s("%d ", p);
	}
	printf("\n");
	p = arr;
	inv(p,10);
	printf("The array has been inverted:\n");
	for (p=arr;p<arr+10;p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
	return 0;
}
void inv(int *x, int n)
{
	int temp, *i, *j, *p;
	int m = (n - 1) / 2;
	i = x;
	j = n + x - 1;
	p = x + m;
	for (; i <= p; i++, j--)
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
	return;
}
