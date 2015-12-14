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
