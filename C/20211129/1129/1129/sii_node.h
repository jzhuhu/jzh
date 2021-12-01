#ifndef SLL_NODE_H
#define SLL_NODE_H

#include<stdlib.h>
#include<stdio.h>

#define False 0
#define Ture 1
typedef struct NODE
{
	struct NODE *link;
	int value;


}Node;
#endif /*SLL_NODE_H*/