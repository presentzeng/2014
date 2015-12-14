#define min(type, x, y)\
	({ type __x = (x); type __y = (y); __x < __y ? __x: __y; })
#define max(type, x, y)\
	({ type __x = (x); type __y = (y); __x > __y ? __x: __y; })

#include <stdio.h>
int main()
{
	int x = 2;
	int y = 4;
	int a = max(int, x++, y++);	
	printf("%d\n", a);
}
	

