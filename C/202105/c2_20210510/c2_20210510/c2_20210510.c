#include<stdio.h>
int main()
{
	int a;
	printf("��������ݣ�\n");
	scanf_s("%d", &a);
	if ((a%4==0&&a%100!=0)||a%400==0)
	{
		printf("%d������\n", a);
	}
	else
	{
		printf("%d��������\n", a);
	}
	return 0;
}