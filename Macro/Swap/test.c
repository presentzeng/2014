#include <stdio.h>
#define SWAP(a, b)  { a ^= b; b ^= a; a ^= b; }
#define SWAP_ADV(a, b)\
	do\
	{\
		(void) (&a == &b);	\
		typeof(a) _tmp = a;	\
		a = b;			\
		b = _tmp;		\
	}while(0)
				



// What happens now?

int main()
{
	int x = 10;
	int y = 5;
	SWAP_ADV(x, y);
	printf("%d\n", x);
	printf("%d\n", y);
}
