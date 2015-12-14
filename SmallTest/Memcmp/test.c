#include <string.h>
#include <stdio.h>

int main()
{
	char * p = "helao world";
	char * p2 = "hello world";
	int a = memcmp(p, p2, 4);
	printf("%d\n", a);
}

