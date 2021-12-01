//#include<stdio.h>
//int main()
//{
//	int i, t;
//	t = 1, i = 2;
//	while (i <= 5)
//	{
//		t = t*i;
//		i = i + 1;
//	}
//	printf("%d\n", t);
//	return 0;
//}
#include<stdio.h>
int main()
{
	int sign = 1;
	double deno = 2.0, sum = 1.0, term;
	while (deno<=100)
	{
		sign = -sign;
		term = sign / deno;
		sum = sum + term;
		deno = deno + 1;
	}
	printf("%f\n", sum);
	return 0;
}