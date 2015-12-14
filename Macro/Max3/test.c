#include <stdio.h>
int foo()
{
	printf("%s\n", "hello");
}
int main()
{
	typeof(foo()) s = 23;
	printf("%d\n", s);
}
