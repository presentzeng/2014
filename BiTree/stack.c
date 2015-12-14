#include"Head.h"
void InitStack(pstack  pHead)//initial stack
{
	pHead->base=(elem *)malloc(sizeof(elem)*10);	
	if(!(pHead->base))
		exit(1);
	pHead->top=pHead->base;
	pHead->stacksize=0;
}
int StackNum(pstack pHead)//return stack num
{
	return pHead->top-pHead->base;	
}

int IsFull(pstack pHead)//is stack full
{
	return pHead->top-pHead->base==10;
}
int IsEmpty(pstack pHead)//is stack empty
{
	return pHead->top-pHead->base==0;
}

void PushStack(pstack pHead,elem e)//push elem e into stack
{
	if(IsFull(pHead))
	{
		printf("the stack is full\n");
		return ;	
	}
	*(pHead->top++)=e;
	pHead->stacksize++;	
}
void PopStack(pstack pHead ,elem *e)//pop elem e out stack
{
	if(IsEmpty(pHead))
	{
		printf("the stack is empty\n");
		return ;	
	}
	*e=*(--(pHead->top));
	pHead->stacksize--;
}
void SetValue(pstack pHead)
{
	int index;
	for(index =0;index<7;index++)
	{
		elem e;
		e=(elem)malloc(sizeof(BiTNode));//always remember to malloc
		e->data=index*2;	
		PushStack(pHead,e);
	}	
}

void PrintStack(pstack pHead)
{
	while(!IsEmpty(pHead))
	{
		elem e;
		PopStack(pHead,&e);	
		printf(":%d\n",e->data);
	}
}
/*
void PrintStack(pstack pHead)
{
	//elem * p=pHead->base;
	//printf("stackvalue:%d\n",*(p)->data);
	printf("stackvalue:%d\n",*(pHead->base)->data);
	
	//while(p!=pHead->base)
	//{
	//	p--;
	//	printf("stackvalue:%d\n",*(p)->data);
	//}
	
}
*/
elem GetStackTop(pstack pHead)
{
	return  *(pHead->top-1);	
}
