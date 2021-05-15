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

//#include<stdio.h>
//int main()
//{
//	int i;
//	int a[20] = { 1, 1 };
//	for (i = 2; i <20; i++)
//	{
//		a[i] = a[i - 1] + a[i - 2];
//	}
//	for ( i = 0; i < 20; i++)
//	{
//		if (i % 5 == 0&&i!=0)
//		{
//			printf("\n");
//		}
//		printf("%d\t", a[i]);
//
//	}
//	printf("\n");
//
//	return 0;
//}
//用冒泡法对十个数排序（由小到大）---起泡法
//#include<stdio.h>
//int main()
//{
//	int a[10], i,j, b;
//	printf("请输入10个数字\n");
//	for ( i = 0; i < 10; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//	for (j = 0; j < 9; j++)
//	{
//		for (i = 0; i < 9 - j; i++)
//		{
//			if (a[i]>a[i + 1])
//			{
//				b = a[i];
//				a[i] = a[i + 1];
//				a[i + 1] = b;
//			}
//		}
//	}
//		for ( i = 0; i < 10; i++)
//		{
//			printf("%d\t", a[i]);
//		}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i, j,sum=0;
//	int a[5][3] = { { 80, 75, 92 }, { 61, 65, 71 }, { 59, 63, 70 }, { 85, 87, 90 }, {76,77,85} };
//	for ( i = 0; i <3; i++)
//	{
//		for (j = 0; j <=5; j++)
//		{
//			sum = sum + a[i][j];
//			if (j==4)
//			{
//				printf("%d\t%f\n", sum, sum / 5.0); sum = 0; continue;
//			}
//
//		}
//	}
//
//	return 0;
//}
//将一个二维数组行和列互换，存到另外一个二维数组中
//#include<stdio.h>
//int main()
//{
//	int a[2][3] = { 1, 2, 3, 4, 5, 6 };
//	int b[3][2], i, j;
//	for ( i = 0; i < 2; i++)
//	{
//		for ( j = 0; j < 3; j++)
//		{
//			printf("%-5d", a[i][j]);
//			b[j][i] = a[i][j];
//		}
//		printf("\n");
//	}
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 2; j++)
//		{
//			printf("%-5d", b[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//有一个3*4的矩阵，要求输出最大的那个元素值，以及所在的行号和列号
//#include<stdio.h>
//int main()
//{
//	int a[3][4] = { 1, 2, 3, 4, 9, 8, 7, 6, -10, 10, -5, 2 };
//	int row, colum, i, j, max;
//	max = a[0][0];
//	for ( i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (a[i][j]>=max)
//			{
//				max = a[i][j];
//				row = i + 1;
//				colum = j + 1;
//			}
//		}
//	}
//	printf("%d\t%d\t%d\n", max, row, colum);
//	return 0;
//}
//从键盘输入9个整数，保留在二维数组里面。按照原来的位置输出第一行和第一列所有元素
#include<stdio.h>
int main()
{
	int a[3][3];
	int i, j;
	char d = 32;
	printf("请输入9个整数：\n");
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	for ( i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if ((i%2==0)&&(j%2==0))
			{
				a[i][j] = d;
			}
			if ((i % 2 == 0) && (j % 2 == 0))
			{
				printf("%-5c", a[i][j]);
			}
			else
			{
				printf("%-5d", a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}