#include"Head.h"
void InThreading(ptree pHead,ptree *pPre)
{
	ptree pCur=pHead;
	//ptree (*pPre); //ptree (*pPre)=pCur (totally wrong no need to set value)
	if(pCur)
	{
		InThreading(pCur->leftchild,pPre);		
		if(!pCur->leftchild)
		{
			pCur->Lflag=Thread;
			pCur->leftchild=(*pPre);
		}
		
		if(!(*pPre)->rightchild)
		{
			(*pPre)->Rflag=Thread;
			(*pPre)->rightchild=pCur;
		}	
		
		(*pPre)=pCur;//mark the (*pPre)
		InThreading(pHead->rightchild,pPre);		
	}
}
void InOrderThreading(ptree *Thrt,ptree pHead)
{
	ptree pPre;
	if(!((*Thrt)=(ptree)malloc(sizeof(TreeNode))))//initial	
	{
		exit(-1);	
	}
	(*Thrt)->Lflag=Link;		
	(*Thrt)->Rflag=Thread;
	(*Thrt)->rightchild=(*Thrt);
	if(!pHead)//if pHead is NULL
	{
		(*Thrt)->leftchild=(*Thrt);//point back 
	}
	else
	{
		(*Thrt)->leftchild=pHead;
		pPre=(*Thrt);			
		InThreading(pHead,&pPre);	
		pPre->rightchild=(*Thrt);
		pPre->Rflag=Thread;	
		(*Thrt)->rightchild=pPre;
	}	
	return ;
}

