#include <cstdio>
#include <climits>
using namespace std;

//turn s to "s"
#define STR(s) #s

//put a and b together
#define CONS(a, b) int(a##b)

//test define
#define A 345

//mid level
#define STR_(s) STR(s)
int main()
{
	STR(you);
	// "you"
	
	printf("%d\n", CONS(2, 3));
	//int(23)

	printf("%s\n", STR(A));	
	//will print A

	printf("%s\n", STR_(A));
	//will print 345
}
