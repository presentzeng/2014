#ifndef _Tree_
#define _Tree_
#include<stdio.h>
#include<stdlib.h>
#define  Link 11
#define  Thread 1
typedef struct Node
{
	int data;
	struct Node * leftchild,*rightchild;
	int Lflag, Rflag;
}*ptree,TreeNode;
void Create(ptree * Head);
int ThrInOrderTraverse(ptree pHead);
void InOrderThreading(ptree *Thrt,ptree pHead);
#endif
