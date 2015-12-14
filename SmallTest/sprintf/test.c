#include <stdio.h>

int main()
{
	char dest[20] = "hello world";
	char src[50];
	printf("%s\n", dest);
	sprintf(src, "%d puls %s is %s", 1, "you", "nizhidaode");	
	printf("%s\n", src);
}
