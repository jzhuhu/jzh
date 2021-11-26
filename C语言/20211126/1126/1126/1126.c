#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#if 0
int main()
{
	int *pi, *pi2, i;
	pi = malloc(25 * sizeof(int));
	printf("0x%x\r\n", pi);
	pi2 = pi;
	printf("0x%x\r\n", pi2);
	for (i = 0; i < 25; i++)
	{
		*pi2++ = i;
	}
	printf("%d\r\n",*(pi2-8));
}
#elif 0
int compare(void const *a, void const *b)
{

	//return (*(int*)a - *(int*)b);
	register int const *pa = a;
	register int const *pb = b;
	return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}
int main()
{
	int *array;
	int n;
	int i;
	printf("please input the number need to input:\r\n");
	scanf_s("%d", &n);
	array = malloc((n+11)*sizeof(int));
	printf("0x%x\r\n",array);
	for (i = 0; i < n; i++)
	{
		printf("The %d number:",i+1);
		scanf_s("%d", array + i);
	}
	
	printf("0x%x\r\n", array);
	qsort(array, n, sizeof(int), compare);
	printf("jzh");
	for ( i = 0; i < n; i++)
	{
		printf("%d\r", *(array + i));
	}
	free(array);
	return 0;

}
#elif 1
char *strcup(char const *string)
{
	char *newstring;
	newstring = malloc(strlen(string) + 1);
	strcpy_s(newstring,sizeof(string)+20, string);
	return newstring;
}
int main()
{
	char *str;
	str = strcup("jzh666");
	while (*str != '\0')
	{
		printf("%c", *str);
		str++;
	}
}

#endif