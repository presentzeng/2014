#include<stdlib.h>
#include<stdio.h>
void Rand(int * arry,int len)
{
	int index;
	for(index=0;index<len;index++)
	{
		arry[index]=rand()%(len*2);
	}
	
}
void print(int * arry,int len)
{
	int index;
	for(index=0;index<len;index++)
	{
		printf("%d\t",arry[index]);
	}
}
SelectSort(int * arry,int len)
{
	int index;		
	int Cur;
	int temp;
	for(index=1;index<len;index++)
	{
		if(arry[index]<arry[index-1])	
		{
			temp=arry[index];
			arry[index]=arry[index-1];
			for(Cur=index-1;Cur>=0;Cur--)
			{
				if(arry[Cur-1]>=temp)
				{
					arry[Cur]=arry[Cur-1];	
				}
				else
				{
					break;	
				}
			}
			arry[Cur]=temp;
		}
	}
}
int main()
{
	srand(time(NULL));
	int arry[10];
	Rand(arry,10);
	print(arry,10);
	printf("after\n");
	SelectSort(arry,10);	
	print(arry,10);
}
