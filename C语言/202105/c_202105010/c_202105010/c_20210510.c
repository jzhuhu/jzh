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

//�ɼ��ֵȼ�
//#include<stdio.h>
//int main()
//{
//	int a;
//	printf("������ɼ���\n");
//	a = getchar();
//	/*scanf_s("%d", &a);*/
//	if (a<60)
//	{
//		printf("�ȼ�ΪE\n");
//	}
//	else if (60 <= a &&a<70)
//	{
//		printf("�ȼ�ΪD\n");
//	}
//	else if (70 <= a &&a<80)
//	{
//		printf("�ȼ�ΪC\n");
//	}
//	else if (80 <= a &&a<90)
//	{
//		printf("�ȼ�ΪB\n");
//	}
//	else if (90<= a &&a<100)
//	{
//		printf("�ȼ�ΪA\n");
//	}
//	else 
//	{
//		printf("�ɼ��������\n");
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
//����һ
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	printf("�������������֣�\n");
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
//������
//#include<stdio.h>
//int main()
//{
//	int a, b, c,t;
//	printf("�������������֣�\n");
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
//	printf("��������������A��B��\n");
//	scanf_s("%d%d", &a, &b);
//	if (a!=b)
//	if (a > b)	printf("A>B\n");
//	else     printf("A<B\n");
//	else     printf("A=B\n");
//	return 0;
//}

//������
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
//	printf("�������������֣�\n");
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
//	case 1:printf("����һ\n"); break;
//	case 2:printf("���ڶ�\n"); break;
//	case 3:printf("������\n"); break;
//	case 4:printf("������\n"); break;
//	case 5:printf("������\n"); break;
//	case 6:printf("������\n"); break;
//	case 7:printf("������\n"); break;
//	default:printf("error\n");
//		break;
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a, b, c,t;
//	printf("����������������\n");
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

//������
//#include<stdio.h>
//int main()
//{
//	int a, b, c, min, max;
//	printf("��������������\n");
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
//���������򣬵��û���������������������������������
//#include<stdio.h>
//int main()
//{
//	double a, b;
//	char c;
//	printf("�������������������������\n");
//	scanf_s("%lf,%lf,%c", &a, &b, &c);
//	switch (c)	
//	{
//		case '+':printf("%lf", a + b); break; 
//		case '-':printf("%lf", a - b); break;
//		case '*':printf("%lf", a*b); break;
//		case '/':printf("%lf", a / b); break;
//		default:printf("�����������������\n");
//		break;
//	}
//	return 0;
//}
//����һ������ж��Ƿ�Ϊ����
//#include<stdio.h>
//int main()
//{
//	int a,b,c,d;
//	printf("���������\n");
//	scanf_s("%d", &a);
//	b = a %4;
//	c = a %100;
//	d = a %400;
//	if (b==0)
//	{
//		if (c!=0)
//		{
//			printf("%d������\n", a);
//		}
//		else if (d==0)
//		{
//			printf("%d������\n", a);
//		}
//		else
//		{
//		if (d == 0)
//			{
//				printf("%d������\n", a);
//			}
//			else
//			{
//				printf("%d��������\n", a);
//			}
//		} 
//	}
//	else
//	{
//		printf("%d��������\n", a);
//	}
//	
//	

//}
//���乫˾�����˷�
//#include<stdio.h>
//int main()
//{
//	float p, w, f, d;
//	int  c, s;
//	printf("�����뵥�ۡ�����������\n");
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
//	printf("���˷�Ϊ%f\n", f);
//	return 0;
//}

 //��ⷽ�̵ĸ�
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a, b, c, disc, p1, p2,x1,x2;
//	printf("������ϵ��A��B��C\n");
//	scanf_s("%lf%lf%lf", &a, &b, &c);
//	disc = pow(b, 2) - 4 * a*c;
//	if (disc<0)
//	{
//		printf("�÷����޽�\n");
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