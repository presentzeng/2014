#include"Head.h"
int main()
{
	ptree Thrt;
	ptree tree;	
	Create(&tree);	
	InOrderThreading(&Thrt,tree);
	ThrInOrderTraverse(Thrt);
	
}
