#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
	int data;	
	struct BiTNode *leftchild,*rightchild;
}*pTree,BiTNode;
typedef pTree elem;
typedef struct sqstack
{
	elem* base;
	elem* top;
	int stacksize;
}sqstack,* pstack;
void InitStack(pstack  Head);
void PrintStack(pstack pHead);
void SetValue(pstack pHead);//set randn value
void PopStack(pstack pHead ,elem *e);
void PushStack(pstack pHead,elem e);//push e into stack
int IsFull(pstack pHead);
int IsEmpty(pstack pHead);
int StackNum(pstack pHead);//stack num
void Create(pTree * pHead);//creat tree
void InOrderTraver(BiTNode Head);//trave tree
elem GetStackTop(pstack pHead);//return the top value
int InRecursion( pTree ptree);//InOrder Travesal
int PreRecursion(pTree pHead);//PreOrder Travesal
int AfterRecursion(pTree pHead);//AfterOrder Travesal 
void PreorderTravesal(BiTNode Head);//Preorder
int PostOrder(pTree pHead);//AfterOrder Travesal
