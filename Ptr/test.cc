#include <iostream>
#include <string>

using namespace std;

class foo
{
public:
	void f(int a)
	{ cout << a << endl; }
	static void bar(int a)
	{ cout << a << endl;}
};

int main()
{
	void (*p)(int)  = foo::bar;
	p(123);

	void (foo::*p1)(int) = &foo::bar;
	//foo f;
	//(f.*p1)(4567);

}
