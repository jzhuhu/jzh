//#include<stdio.h>
//int main()
//{
//	float  amount, total, aver;
//	int i;
//	for ( i = 0,total=0; i <=100000; i++)
//	{
//		printf("����������\n");
//		scanf_s("%f", &amount);
//		total = total + amount;
//		if (total >= 100000) break;
//	}
//	aver = total / i;
//	printf("%f", aver);
//
//	return 0;
//}
//���100-200���ܱ�3��������
//#include<stdio.h>
//int main()
//{
//	int i;
//	for (size_t i = 100; i <=200; i++)
//	{
//		if ((i%3)!=0)
//		{
//			printf("%d\t", i);
//		}
//		else
//		{
//			continue;
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i;
//	for (size_t i = 100; i <=200; i++)
//	{
//		if (i%3==0)
//			continue;
//		printf("%d\t", i);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i, j,n=1;
//	for (size_t i = 1; i < 5; i++)
//	{
//		for (size_t j = 1; j <6; j++,n=n+1)
//		{
//			if (i==3&&j==1)
//			{
//				continue;
//			}
//			printf("%d\t", i*j);
//			if (n%5==0)
//			{
//				printf("\n");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//��pai�Ľ���ֵ
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int sign=1;
//	double	sum = 0, term = 1.0, n = 1.0;
//	while ((fabs(term))>=(1e-6))
//	{
//		sum = sum + term;
//		n = n + 2;
//		sign = -sign;
//		term = sign / n;
//	}
//	sum = sum * 4;
//	printf("%lf", sum);
//	return 0;
//}
//Fibonacci����
//#include<stdio.h>
//int main()
//{
//	int a=1, b=1,c,n;
//	printf("%d\t%d\t", a, b);
//	for (size_t n = 1; n <= 38; n++)
//	{
//		c = a + b;
//		printf("%d\t",c);
//		a = b;
//		b = c;
//	}
//	return 0;
//}
//������
//#include<stdio.h>
//int main()
//{
//	int f1, f2,i;
//	for (size_t i = 1,f1=1,f2=1; i <=20; i++)
//	{
//		printf("%12d\t%12d\t", f1, f2);
//		if (i % 2 == 0)
//		{
//			printf("\n");
//		}
//		f1 = f1 + f2;
//		f2 = f2 + f1;
//	}
//	printf("\n");
//
//	return 0;
//}
//���һ������3�������㣬�ж����Ƿ�Ϊ����
//#include<stdio.h>
//int main()
//{
//	int i, n;
//	printf("������һ������3������\n");
//	scanf_s("%d", &n);
//	for (size_t i = 2; i <=n; i++)
//	{
//		if (n%i==0)
//		{
//			break;
//		}
//		if (i<n)
//		{
//			printf("%d��������\n", n); break;
//		}
//		else
//		{
//			printf("%d������\n", n); break;
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i, n, k;
//	printf("���������3������\n");
//	scanf_s("%d", &n);
//	k = sqrt(n);
//	for (size_t i = 2; i <=k; i++)
//	{
//		if (n%i == 0)		break;
//		if (i<=k)
//		{
//			printf("%d��������\n", n); break;
//		}
//		else
//		{
//			printf("%d������\n", n); break;
//		}
//	}
//	return 0;
//}
//��100-200��ȫ������
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int k,m=0;
//	int n, i;
//	for (n =101; n<=200; n=n+2)
//	{
//		k = sqrt(n);
//		for (i = 2; i<=k; i++)
//		{
//			if (n%i == 0)	break;
//			if (i>=k+1)
//			{
//				printf("%d", n);
//				m += 1;
//			}
//			if (m%10==0)
//			{
//				printf("\n");
//			}
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i;
//	for (size_t i = 0; i <3; i++)
//	{
//		printf("%d", i);
//	}
//
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int k, m = 0, n, i;
//	for (n = 101; n <= 200; n = n + 2)
//	{
//		k = sqrt(n);
//		for (i = 2; i <= k; i++)
//		{
//			if (n%i == 0)	break;
//			if (i >= k + 1)
//			{
//				printf("%d\t", n); break;
//				m += 1;
//			}
//			if (m % 10 == 0)
//			{
//				printf("\n");
//			}
//		}
//	}
//	printf("\n");
//	return 0;
//}
//��������������m��n�����Լ������С������
//#include<stdio.h>
//int main()
//{
//	int a, b, c,d,e;
//	printf("������������������\n");
//	scanf_s("%d%d", &a, &b);
//	if (a<b)
//	{
//		c = a;
//		a = b;
//		b = c;
//	}
//	e = a*b;
//	while (b!=0)
//	{
//		d = a%b;
//		a = b;
//		b = d;
//	}
//	printf("���Լ��Ϊ��%d", a);
//	printf("��󹫱���Ϊ��%d", e / a);
//	return 0;
//}
//����һ���ַ����ֱ�ͳ��Ӣ����ĸ���ո����֡������ַ��ĸ���
//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 1;
//	char ch;
//	while ((ch=getchar())!='\n')
//	{
//		if ((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
//		{
//			a++;
//		}
//		else if (ch==32)
//		{
//			b++;
//		}
//		else if (ch>=48&&ch<=57)
//		{
//			c++;
//		}
//		else
//		{
//			d++;
//		}
//	}
//	printf("%d\t%d\t%d\t%d\n", a, b, c, d);
//
//	return 0;
//}
//��Sn
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	long int sum=0,sum1=0;
//	int a, n,i;
//	printf("����������a��a��λ��n��\n");
//	scanf_s("%d%d",& a,& n);
//	for ( i = 0; i <n; i++)
//	{
//		sum = sum + a*pow(10, i);
//		sum1 = sum1 + sum;
//	}
//	printf("���ǵĺ�Ϊ%d\n", sum1);
//	return 0;
//}
//��n!���ۼ�
//#include<stdio.h>
//int main()
//{
//	int n;
//	long long int  sum = 0, a = 1, b = 1;
//	for (n = 1; n <= 20; n++)
//	{
//		while (a <= n)
//		{
//			b = b*a;
//			a = a + 1;
//			if (a == n + 1)
//			{
//				sum = sum + b;
//			}
//
//		}
//		a = 1;
//		b = 1;
//	}
//	printf("%lld\n", sum);
//}

//int main() 
//{
//	double a = 1, sum = 0;
//	int i; 
//	for (i = 1; i <= 20; i++){ a *= i; sum += a; }
//	printf("%ld\n", sum);

//
//
//	return 0;
//}


