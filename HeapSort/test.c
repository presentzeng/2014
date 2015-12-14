#include<stdio.h>
#include<stdlib.h>
#define N 10
void RandInt(int * arry,int len)
{
	srand(time(NULL));
	int index;
	for(index=0;index<len;index++)
	{
		arry[index]=rand()%(2*len);	
	}	
}
void Show(int * arry,int len)
{
	int index;
	for(index=0;index<len;index++)
	{
		printf("%d\t",arry[index]);
	}
	printf("\n");
}
/*
void HeapFix(int *a,int top,int end)//small top
{
	int son;			
	son=top*2+1;
	int temp=a[top];
	while(son<end)
	{
		if(son+1<end && a[son]>a[son+1])//find the smaller one
		{
			son++;		
		}
		if(temp<a[son])
		{
			break;
		}
		a[top]=a[son];
		top=son;
		son=top*2+1;
	}
	a[top]=temp;	
}
*/

void HeapFix(int *a,int top,int end)//small top
{
	int temp=a[top];
	int son;	
	son=top*2+1;
	while(son<end)
	{
		if(son+1<end && a[son]>a[son+1])
		{
			son++;						
		}
		if(temp<son)
		{
			break;
		}
		a[top]=a[son];
		top=son;
		son=top*2+1;
	}
	a[top]=temp;	
}

void HeapSort(int * a, int len)
{
	int index=len/2;
	for(;index>=0;index--)//should be equal
	{
		HeapFix(a,index,len);	
	}
}

void SortArry(int *arry,int len)
{
	int index;
	for(index=len-1;index>0;index--)
	{
		HeapSort(arry,index+1);	
		arry[0]=arry[0]^arry[index];	
		arry[index]=arry[0]^arry[index];	
		arry[0]=arry[0]^arry[index];	
		//int temp=arry[0];
		//arry[0]=arry[index];	
		//arry[index]=arry[0];
	}
}
int main()
{
	int arry[N];
	RandInt(arry,N);
	Show(arry,N);
	printf("after\n");
	//HeapSort(arry,N);
	SortArry(arry,N);
	Show(arry,N);
}
