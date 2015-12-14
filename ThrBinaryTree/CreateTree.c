#include"Head.h"
void Create(ptree * Head)
{
	int ch;
	printf("input Node value\n");
	scanf("%d",&ch);
	if(ch==-1)
		(*Head)=NULL;
	else 
	{
		if(!((*Head)=(ptree)malloc(sizeof(TreeNode))))
			exit(-2);
		(*Head)->data=ch;
		(*Head)->Lflag=11;
		(*Head)->Rflag=11;
		Create(&((*Head)->leftchild));
		Create(&((*Head)->rightchild));
	}
	return ;
}
