#include <stdio.h>
typedef struct mystruct
{
	int a;	
	char b;
}My;

void InitArray()
{
	int plat[5] = { [0 ... 4] = -1 };	
	int i;
	for(i = 0; i < 5; i++)
	{	
		printf("%d\n", plat[i]);
	}
}

void InitStruct()
{
	My one = {
		.a = 13,			
		.b = 'h',
	};	
	printf("%d\n", one.a);	
}
int main()
{
	InitStruct();
}
