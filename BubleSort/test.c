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
void BubleSort(int * arry, int len)
{
	int top,end;		
	int Cur;
	int temp;
	top=0;
	end=len;
	while(top<end)
	{
		for(Cur=top;Cur<end-1;Cur++)//from top to end
		{
			if(arry[Cur]>arry[Cur+1])	
			{
				temp=arry[Cur];
				arry[Cur]=arry[Cur+1];
				arry[Cur+1]=temp;
			}	
		}		
		end--;
		if(top>=end)
			break;
		for(Cur=end-1;Cur>=top;Cur--)//from end to top 
		{
			if(arry[Cur]>arry[Cur+1])	
			{
				temp=arry[Cur];
				arry[Cur]=arry[Cur+1];
				arry[Cur+1]=temp;
			}	
				
		}		
		top++;
	}
}
int main()
{
	int arry[N];
	RandInt(arry,N);
	Show(arry,N);
	printf("after\n");
	BubleSort(arry,N);
	Show(arry,N);
}
