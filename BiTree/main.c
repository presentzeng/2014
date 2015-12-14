#include"Head.h"
int main()
{
	pTree ptree;
	Create(&ptree);			
	printf("\nInOrder Recursion\n");
	InRecursion(ptree);
	printf("\nInOrder\n");
	InorderTravesal2(*ptree);
	//InOrderTraver(*ptree);
	printf("\nPreOrder Recursion\n");
	PreRecursion(ptree);
	printf("\nPreOrder\n");
	PreorderTravesal(*ptree);
	printf("\nAfterOrder\n");
	PostOrder(ptree);
	printf("\nAfterOrder Recursion\n");
	AfterRecursion(ptree);
}

