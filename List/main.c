#include "list.h"
#include <stdio.h>
int IsEmpty(struct list_head *Lnode)
{
	if(list_empty(Lnode))
	{
		printf("yes it is empty");	
	}
	else
	{
		printf("no it is not empty");	
	}
}
int main()
{
	LIST_HEAD(Lnode);	
	IsEmpty(&Lnode);	
}
