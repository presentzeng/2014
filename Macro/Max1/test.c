#define max(x,     y) ((x) > (y) ? (x) : (y))
#define min(x,     y) ((x) < (y) ? (x) : (y))

#include <stdio.h>
int main()
{
	int a = 2;
	int b = 4;
	int c = max(a++, ++b);
	printf("%d\n", c);
}
