#include <stdio.h>
#define COUT(format, art...)\
	printf("%s\n", art)

#define STR(s) #s

int main()
{
	COUT(int, "test");
}
