#include "head.hpp"
using namespace std;

class Test
{
private:
	Test(const Test&);
	void operator=(const Test&);
public:
	Test(){ cout << "Test\n";}
	~Test(){ cout << "~Test\n";}
};

int main()
{
	CounterPtr<Test>ptr(new Test);
	cout << ptr.count() << endl;

	CounterPtr<Test>ptr2(ptr);	
	cout << ptr2.count() << endl;
}
