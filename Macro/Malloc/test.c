#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char * ptr = (char *)malloc(10);
	char * ptr1 = (char *)calloc(10, 2);

	int i;
	for(i = 0; i < 100; i++)
	{	
		ptr[i] = 'y';
	}
	printf("%c\n", ptr[44]);
	//int a = sizeof(*ptr1);
	//printf("%d\n", a);	
}

