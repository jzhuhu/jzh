#include<stdio.h>
int main()
{
	void inv(int *x, int n);
	int i, arr[10];
	int *p = arr;
	printf("The original array:\n");
	for (i = 0; i < 10; i++, p++)
	{
		scanf_s("%d ", p);
	}
	printf("\n");
	p = arr;
	inv(p, 10);
	printf("The array has been inverted:\n");
	for (p = arr; p<arr + 10; p++)
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