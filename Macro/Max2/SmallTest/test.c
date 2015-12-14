#include <stdio.h>
int main()
{
	int a = ({int b = 1; int c = 3; b + c; });	
	printf("%d\n", a);
}
	

