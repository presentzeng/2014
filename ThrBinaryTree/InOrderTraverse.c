#include"Head.h"
int ThrInOrderTraverse(ptree pHead)//it is the head pointer Thrt
{
	ptree p=pHead->leftchild;
	while(p!=pHead)
	{
		
		while(p->Lflag==Link)
		{
			p=p->leftchild;
		}	
		printf("first:%d\n",p->data);
		while(p->Rflag==Thread && p->rightchild!=pHead)
		{
			p=p->rightchild;	
			printf("second:%d\n",p->data);
		}
		
		p=p->rightchild;
		printf("mark\n");
		//sleep(3);
	}	
	return ;
}
