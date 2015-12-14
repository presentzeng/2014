#include <stdio.h>
#define min(x, y)({\
	typeof(x) _x = (x);\
	typeof(y) _y = (y);\
	(void) (&_x == &_y);\
	_x < _y ? _x : _y;})



int main()
{
	int a = 3;
	double b = 7;
	int c = min(a++, b++);
	printf("%d\n", c);
}

