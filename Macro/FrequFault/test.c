#ifndef NULL
#define NULL (void *)0
#endif // #ifndef NULL
//defining specific constants

//false demonstration about parentheses of variable

#define MULT(x, y) x*y

//false demonstration about error space
#define MULT1 (x, y) x*y

//false demonstration about parentheses of expression
#define ADD_FIVE(v) (v) + 5

int main()
{
	//example one
	int x = MULT(2 + 3, 4 + 1);
	//we expect 5 * 5
	//the truth is 2 + 3 * 4 + 1

	int x = MULT1(2 + 3, 4 + 1);
	//we expect 2 + 3 * 4 + 1
	//the truth is (x, y) x*y(2 + 3, 4 + 1);

	int y = ADD_FIVE(4) * 4;
	//we expect 9 * 4
	//thre truth is 4 + 5 * 4
}

