#include"MyNetOperation.h"
#define N 10 
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

int QuickOne(int *arry,int head,int tail)
{
	int temp=arry[head];
	int top=head;	
	int end=tail;
	while(top<end)
	{
		while(arry[end]>=temp && top<end)
		{
			 end--;	
		}
		arry[top]=arry[end];
		while(arry[top]<=temp && top<end)
		{
			top++;
		}
		arry[end]=arry[top];
	}
	arry[top]=temp;
	return top;
}
/*
int QuickOne(int *arry,int head,int tail)
{
	int pivot=arry[head];	
	while(head<tail)
	{
		while(head<tail && arry[tail]>=pivot)
		{
			tail--;
		}
		arry[head]=arry[tail];
		while(head<tail && arry[head]<=pivot)
		{
			head++;
		}
		arry[tail]=arry[head];
	}
	arry[tail]=pivot;
	return tail;
}
*/
void QuickSort(int * arry,int head,int tail)
{
	int pivot;
	if(head<tail)
	{
		pivot=QuickOne(arry,head,tail);	
		QuickSort(arry,head,pivot-1);
		QuickSort(arry,pivot+1,tail);
	}
}
int main()
{
	srand(time(NULL));
	int arry[N];
	Rand(arry,N);
	print(arry,N);
	printf("after\n");
	QuickSort(arry,0,9);	
	//QuickOne(arry,0,9);	
	print(arry,N);
}
