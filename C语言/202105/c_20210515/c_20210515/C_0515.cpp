//#include<stdio.h>
//int main()
//{
//	double i=1,sum3=0,sum=0;
//	int n = 1, sum1 = 0,sum2 = 0, k = 0;
//
//
//
//	while (n <= 100)
//	{
//		sum1 = sum1 + n;
//		n = n + 1;
//	}
//	while (k <= 50)
//	{
//		sum2 = sum2 + k*k;
//		k = k + 1;
//	}
//	while (i<=10)
//	{
//		sum3 = sum3 + 1/ i;
//		i++;
//	}
//	sum = sum1 + sum2 + sum3;
//	printf("%lf\n", sum);
//	return 0;
//}
//方法二
//#include<stdio.h>
//int main()
//{
//	int n1 = 4, n2 = 3, n3 = 2;
//	double	s1 = 0, s2 = 0, s3 = 0, k;
//	for ( k = 1; k <=n1; k++)
//	{
//		s1 = s1 + k;
//	}
//	for (k = 1; k <= n2; k++)
//	{
//		s2 = s2 + k;
//
//	}
//	for (k = 1; k <= n3; k++)
//	{
//		s3 = s3 + 1/k;
//	}
//	printf("%lf\n", s1 + s2 + s3);
//
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i,a,b,c,d;
//	for ( i = 100; i <=999; i++)
//	{
//		a = i % 10;
//		b = i / 10 % 10;
//		c = i / 100 % 10;
//		d = a*a*a+b*b*b+c*c*c;
//		if (d==i)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//第六章数组
//#include<stdio.h>
//int main()
//{
//	int i, a[10]={1,2,3,4,5};
//	//for ( i = 0; i <10; i++)
//	//{
//	////	a[i] = i;
//	//}
//	for ( i = 9; i >=0; i--)
//	{
//		printf("%d\n", a[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i, a[5] = { 3, 4, 5 }, b[5];
//
//	for ( i = 0; i < 5; i++)
//	{
//		printf("%6d", a[i]);
//	}
//	printf("\n");
//	for ( i = 0; i < 5; i++)
//	{
//		printf("%6d", b[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int i, max, a[10];
//	printf("请输入10个数字\n");
//	for ( i = 0; i < 10; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//	max = a[0];
//	for ( i = 0; i < 10; i++)
//	{
//		if (a[i]>max)
//		{
//			max = a[i];
//	}
//
//	}
//	printf("max=%d\n", max);
//	return 0;
//}

#include<stdio.h>
int main()
{
	int i;
	int a[20] = { 1, 1 };
	for ( i = 2; i <=20; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	printf("%d\t", a[i]);
	printf("\n");

	return 0;
}