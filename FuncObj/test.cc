#include <iostream>

using namespace std;

class test
{
public:
	void operator()()
	{
		cout << "hi\n";
	}
	void operator()(int)
	{
		cout << "b\n";
	}
};

int main()
{
	test t;	
	t();
	t(22);
}
