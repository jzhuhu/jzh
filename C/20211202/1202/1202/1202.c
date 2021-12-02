#include<stdio.h>
#include<stdlib.h>
#include "node.h"
#if 0
int	compare(void const *x, void const *y)
{
	if (*(int*)x == *(int*)y)
		return 0;
	else
		return 1;
}
Node *search_list(Node *node, void const *value, int(*compare_p)(void *x, void *y))
{
	while (node!=NULL)
	{
		if (compare_p(&node->value, value) == 0)
			break;
		node = node->link;
	}
	return node;
}

int main()
{
	int(*compare_p)(void *x, void *y) = &compare;
	Node a, b, c,*temp;
	a.value = 1; b.value = 2; c.value = 3;
	a.link = &b; b.link = &c; c.link = NULL;
	temp = search_list(&a, &(c.value), compare_p);
	printf("%d\r\n", temp->value);
	return 0;
}
#elif 0
double add(double x, double y)
{
	return x + y;

}
double sub(double x, double y)
{
	return x - y;

}
double mul(double x, double y)
{
	return x * y;

}
double div(double x, double y)
{
	return x / y;

}
//double (*oper_function[])(double x, double y) = { add, sub, mul, div };
int main()
{

	double result=0;
	double(*oper_function[])(double x, double y) = { add, sub, mul, div };
	result = oper_function[0](3, 4);
	printf("%f\n", result);
	return 0;
}
#elif 1



#endif