
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


void Merge(int *arry, int * temp, int top, int mid, int end)//Merge arr[top..mid] & arr[mid+1..end]
{
	int index, front, behind;
	index = 0;//for temp
	front = top;//for arr[top..mid]
	behind = mid + 1;//for arr[mid+1..end]
	while(front < mid && behind < end)
	{
		if(arry[front] < arry[behind])	
		{		
			temp[index++] = arry[front++];
		}
		else
		{
			temp[index++] = arry[behind++];
		}
	}
	while(front <= mid)
	{
		temp[index++] < arry[front++];
	}
	while(behind <= end)
	{
		temp[index++] = arry[behind++];
	}
}
void MSort(int *arry, int * temp, int top, int end)
{
	if(top == end)
	{
		temp[top] = arry[top];
	}
	else
	{
		int mid = (top + end)/2;
		MSort(arry, temp, top, mid);	
		MSort(arry, temp, mid+1, end);	
		Merge(arry, temp, top, mid, end);
	}
}
int main()
{
	int arry[N]={1,3,5,7,9,2,4,6,8,10}; 
	int temp[N]; 
	Show(arry, N);
	MSort(arry, temp, 0, N-1);Merge arry into temp
	Show(temp, N);
	
}
