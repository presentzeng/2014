#include"Head.h"
void Create(pTree * Head)
{
	int ch;
	printf("input Node value\n");
	scanf("%d",&ch);
	if(ch==-1)
		(*Head)=NULL;
	else 
	{
		if(!((*Head)=(pTree)malloc(sizeof(BiTNode))))
			exit(-2);
		(*Head)->data=ch;
		Create(&((*Head)->leftchild));
		Create(&((*Head)->rightchild));
	}
	return ;


}

void InOrderTraver(BiTNode Head)//InOrder travel
{
	sqstack stack;	
	InitStack(&stack);	
	PushStack(&stack,&Head);//push head into stack
	elem  e;
	//e=(elem )malloc(sizeof(BiTNode));
	while(!IsEmpty(&stack))
	{
		while((e=GetStackTop(&stack)))//push the left child
		{
			PushStack(&stack,e->leftchild);
		}	

		PopStack(&stack,&e);//pop NULL	
		if(!(IsEmpty(&stack)))//start to traver
		{
			PopStack(&stack,&e);	
			printf("%d\t",e->data);
			PushStack(&stack,e->rightchild);
		}
	}
	return ;
}


void InorderTravesal2(BiTNode Head)//inorder
{
	sqstack stack;			
	InitStack(&stack);	
	pTree temp;//=(pTree)malloc(sizeof(BiTNode));the malloc is unnecessary
	temp=&Head;
	while(!IsEmpty(&stack)||temp)
	{
		while(temp)
		{
			PushStack(&stack,temp);
			temp=temp->leftchild;
		}
		PopStack(&stack,&temp);	
		printf("%d\t",temp->data);
		temp=temp->rightchild;
	}
	return ;	
}
int PreRecursion(pTree pHead)//PreOrder Travesal
{
	elem temp;	
	temp=pHead;	
	if(temp)
	{
		printf("%d\t",temp->data);
		if(PreRecursion(temp->leftchild))	
			if(PreRecursion(temp->rightchild))	
				return 1;
		return 0;	
	}
	else
	{
		return 1;
	}
}

void PreorderTravesal(BiTNode Head)//Preorder
{
	sqstack stack;			
	InitStack(&stack);	
	pTree temp;//=(pTree)malloc(sizeof(BiTNode));
	temp=&Head;
	while(!IsEmpty(&stack)||temp)
	{
		if(temp)
		{
			printf("%d\t",temp->data);
			PushStack(&stack,temp);
			temp=temp->leftchild;
		}
		else
		{
			PopStack(&stack,&temp);//when break if temp is NULL
			temp=temp->rightchild;
		}
	}
	return ;	
}
int InRecursion(pTree pHead)//InOrder Travesal 
{
	elem temp;	
	temp=pHead;	
	if(temp)
	{
		if(InRecursion(temp->leftchild))	
			printf("%d\t",temp->data);
		if(InRecursion(temp->rightchild))	
			return 1;
		return 0;	
	}
	else
	{
		return 1;
	}

}
int AfterRecursion(pTree pHead)//InOrder Travesal 
{
	elem temp;	
	temp=pHead;	
	if(temp)
	{
		if(AfterRecursion(temp->leftchild))	
			if(AfterRecursion(temp->rightchild))	
				printf("%d\t",temp->data);
		return 1;
		return 0;	
	}
	else
	{
		return 1;
	}

}
int PostOrder(pTree pHead)
{
	sqstack stack;
	InitStack(&stack);		
	elem pCur=pHead;	
	elem pPre=NULL;
	pCur=pHead;
	while(pCur || !IsEmpty(&stack))	
	{
		while(pCur)	
		{
			PushStack(&stack,pCur);	
			pCur=pCur->leftchild;
		}
		pCur=GetStackTop(&stack);//only get number no need to pop cause you gonna need it again
		if(pCur->rightchild==NULL || pCur->rightchild==pPre)
		{
			printf("%d\t",pCur->data);	
			pPre=pCur;	
			PopStack(&stack,&pCur);
			pCur=NULL;
		}
		else
		{
			pCur=pCur->rightchild;	
		}
	}//while
} 
