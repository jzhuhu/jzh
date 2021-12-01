#include"sii_node.h"
#if 0
int sll_insert(Node *current, int new_value)
{
	Node *new;
	Node *previous;
	while ((current!=NULL)&(current->value < new_value))
	{
		previous = current;
		current = current->link;
	}

	new = malloc(sizeof(Node));
	if (new == NULL)
	{
		return False;
	}
	new->value = new_value;
	new->link = current;
	previous->link = new;
	return Ture;
}
int main()
{
	Node a, b, c, *head, *p;
	a.value = 5;
	b.value = 10;
	c.value = 15;
	head = &a;
	a.link = &b;
	b.link = &c;
	c.link = NULL;
	sll_insert(&a,16);
	p = head;
	do
	{
		printf("%d\n", p->value);
		p = p->link;
	} while (p!=NULL);
}
#elif 1
int sll_insert(Node **rootp, int new_value)
{
	Node *new;
	Node *previous;
	Node *current;
	current = *rootp;
	previous = NULL;
	while ((current != NULL)&&(current->value < new_value))
	{
		previous = current;
		current = current->link;
	}

	new = malloc(sizeof(Node));
	if (new == NULL)
	{
		return False;
	}
	new->value = new_value;
	new->link = current;
	if (previous==NULL)
	{
		*rootp = new;
	}
	else
	{
		previous->link = new;
	}
	return Ture;
}
int main()
{
	Node a, b, c, *head, *p,*a1,**a2;
	a.value = 5;
	b.value = 10;
	c.value = 15;
	head = &a;
	a.link = &b;
	b.link = &c;
	c.link = NULL;
	a1 = &a;
	a2 = &a1;
	sll_insert(a2, 3);
	p = head;
	do
	{
		printf("%d\n", p->value);
		p = p->link;
	} while (p != NULL);
}
#endif