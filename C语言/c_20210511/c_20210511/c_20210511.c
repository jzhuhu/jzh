//����һ���ַ����б��Ƿ�Ϊ��д��ĸ�������ת����Сд���������ֱ�����
//#include<stdio.h>
//int main()
//{
//	char c1, c2;
//	printf("������һ���ַ���\n");
//	c1 = getchar();
//	c2 = (c1 >= 'A'&&c1 <= 'Z' )? (c1 + 32) : c1;
//	putchar(c2);
//	putchar('\n');
//	return 0;
//}
//ʵ�ַ��ź���
//#include<stdio.h>
//int main()
//{
//	float a;
//	printf("������һ�����֣�\n");
//	scanf_s("%f", &a);
//	if (a >= 0)
//	{
//		if (a > 0)
//		{
//			printf("1\n");
//		}
//		else
//		{
//			printf("0\n");
//		}
//	}
//	else printf("-1\n");
//
//	return 0;
//}

//�ɵȼ��ó�ѧ���ĳɼ���Χ
//#include<stdio.h>
//int	main()
//{
//	char g;
//	printf("���������ĵȼ���\n");
//	g = getchar();
//	switch (g)
//	{
//	case 'A':printf("85����\n"); break;
//	case 'B':printf("70-84\n"); break;
//	case 'C':printf("60-69\n"); break;
//	case 'D':printf("60����\n"); break;
//	default:printf("�������\n");
//		break;
//	}
//	return 0;
//}
//����������abc�ɼ������룬�������������
//#include<stdio.h>
//int main()
//{
//	int a, b, c,max;
//	printf("��������������\n");
//	scanf_s("%d%d%d", &a, &b, &c);
//	max = a > b ? a : b;
//	if (max<c)
//	{
//		max = c;
//	}
//	printf("max=%d\n", max);
//	return 0;
//}
//����С��1000��������Ҫ�����ƽ���������������������������֣���Ҫ�����Ƿ�С��1000
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int a, b;
//	printf("������С��1000������\n");
//	scanf_s("%d", &a);
//	if (a>1000||a<0)
//	{
//		printf("���ݴ�������������,ʹ������С��1000\n");
//		scanf_s("%d", &a);
//	}
//	
//	b = sqrt(a);
//	printf("%d\n", b);
//
//	return 0;
//}
//����ѭ��
//#include<stdio.h>
//#include<math.h>
//#define M 1000
//int main()
//{
//	int a, b;
//	printf("������һ��С��1000������\n");
//	scanf_s("%d", &a);
//	while (a>M||a<0)
//	{
//		printf("���ݴ�������������,ʹ������С��1000\n");
//		scanf_s("%d", &a);
//		b = sqrt(a);
//	}
//	printf("%d\n", b);
//
//	return 0;
//}
//�ֶκ����ļ���
//#include<stdio.h>
//int main()
//{
//	float x, y;
//	scanf_s("%f", &x);
//	if (x<1)
//	{
//		y = x;
//	}
//	else if (x>=1&&x<10)
//	{
//		y = 2.0*x - 1;
//	}
//	else
//	{
//		y = 3.0*x - 11;
//	}
//	printf("%f", y);
//	return 0;
//}
//����ɼ�������ȼ�
//#include<stdio.h>
//int main()
//{
//	int grade, b;
//	scanf_s("%d", &grade);
//	b = grade / 10;
//	if (b<6)
//	{
//		b = 5;
//	}
//	switch (b)
//	{
//	case 9:printf("��ĳɼ��ȼ�ΪA\n"); break;
//	case 8:printf("��ĳɼ��ȼ�ΪB\n"); break;
//	case 7:printf("��ĳɼ��ȼ�ΪC\n"); break;
//	case 6:printf("��ĳɼ��ȼ�ΪD\n"); break;
//	case 5:printf("��ĳɼ��ȼ�ΪE\n"); break;
//	}
//	return 0;
//}
//�α���
//#include<stdio.h>
//int main()
//{
//	float score;
//	char grade;
//	printf("���������ĳɼ���\n");
//	scanf_s("%f", &score);
//	while (score>100||score<0)
//	{
//		printf("�ɼ������������������\n");
//		scanf_s("%f", &score);
//	}
//	switch ((int)(score/10))
//	{
//	case 10:
//	case 9:printf("��ĳɼ��ȼ�ΪA\n"); break;
//	case 8:printf("��ĳɼ��ȼ�ΪB\n"); break;
//	case 7:printf("��ĳɼ��ȼ�ΪC\n"); break;
//	case 6:printf("��ĳɼ��ȼ�ΪD\n"); break;
//	case 5:
//	case 4:
//	case 3:
//	case 2:
//	case 1:
//	case 0:printf("��ĳɼ��ȼ�ΪE\n"); break;
//	}
//	return 0;
//}
//����һ��������5λ������
#include<stdio.h>
int main()
{
	int num,a,b,c,d,e;
	printf("��������������0-99999����\n");
	scanf_s("%d", &num);
	while (num<=0||num>=100000)
	{
		printf("�����������������\n");
		scanf_s("%d", &num);
	}
	if (num>9999)
	{
		printf("������Ϊ5λ��\n");
		a = num / 10000;
		b = (num - a * 10000) / 1000;
		c = (num - a * 10000 - b * 1000) / 100;
		d = (num - a * 10000 - b * 1000 - c * 100) / 10;
		e = num - a * 10000 - b * 1000 - c * 100 - d * 10;
		printf("%d\t%d\t%d\t%d\t%d\n", a, b, c, d, e);
		printf("%d%d%d%d%d\n", e, d, c, b, a);

	}
	else if (num<=9999&&num>999)
	{
		printf("������Ϊ4λ��\n");
		b = (num / 1000);
		c = (num - b*1000) / 100;
		d = (num  - b * 1000 - c * 100) / 10;
		e = num - b * 1000 - c * 100 - d * 10;
		printf("%d\t%d\t%d\t%d\n",  b, c, d, e);
		printf("%d%d%d%d\n", e, d, c, b);
	}
	else if (num<=999 && num>99)
	{
		printf("������Ϊ3λ��\n");
		c = num  / 100;
		d = (num - c * 100) / 10;
		e = num  - c * 100 - d * 10;
		printf("%d\t%d\t%d\n", c, d, e);
		printf("%d%d%d\n", e, d, c);
	}
	else if (num<=99 && num>9)
	{
		printf("������Ϊ2λ��\n");
		d = num  / 10;
		e = num - d * 10;
		printf("%d\t%d\n",  d, e);
		printf("%d%d", e, d);

	}
	else 
	{
		printf("������Ϊ1λ��\n");
		printf("%d\n", num);
		printf("%d\n", num);
	}

	return 0;
}