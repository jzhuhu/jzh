//��10������Ԫ�����θ�ֵΪ0-9�����Ұ����������
#if (0)
#include<stdio.h>
int main()
{
	int a[10],i;
	for ( i = 0; i < 10; i++)
	{
		scanf_s("%d", &i);
		a[i] = i;
	}
	for ( i = 9; i>=0; i--)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#endif
#if(0)
#include<stdio.h>
int main()
{
	int i, a[20] = { 1, 1 };
	for ( i = 2; i < 20; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	for ( i = 0; i < 20; i++)
	{
		if (i % 5 == 0 && i>0)
		{
			printf("\n");
		}
		printf("%-5d", a[i]);

	}
	printf("\n");
	return 0;
}
#endif
//����10������Ȼ��ʹ������С�������
#if(0)
#include<stdio.h>
int main()
{
	int a[10], i,j,temp;
	printf("����������10������\n");
	for ( j = 0; j < 10; j++)
	{
		scanf_s("%d", &a[j]);
	}
	printf("\n");
	for (i = 0; i < 9; i++)
	{
		for ( j = 0; j < 9-i; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for ( j = 0; j < 10; j++)
	{
		printf("%d ", a[j]);
	}
	return 0;
}
#endif

#if(0)
//ѡ�񷨶�10����������
#include<stdio.h>
int main()
{
	int i,j,a[10],min,temp;
	printf("������10����ֵ\n");
	for ( i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("\n");
	for ( i = 0; i < 9; i++)
	{
		min = i;
		for ( j = i+1; j < 10; j++)
		{
			if (a[min]>a[j])
			{
				min = j;
			}
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
	for ( i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#endif
#if(0)
#include<stdio.h>
int main()
{
	int i;
	char ch[20] = {"I am a student."};
	/*for ( i = 0; i < 15; i++)
	{
		printf("%c", ch[i]);
	}
	printf("\n");
*/
	printf("%s\n",ch);
	return 0;
}
#endif
#include<stdio.h>
int main()
{
	char ch[6];
	scanf_s("%s", ch);
	puts(ch);
	return 0;
}