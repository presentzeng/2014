#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton * get()
	{ return new Singleton; } 

	static Singleton * get1()
	{ 
		static Singleton *p = new Singleton;
		return p;
	} 
private:
	Singleton() {}
};

int main()
{
	cout << Singleton::get() << endl;
	cout << Singleton::get() << endl;
	return 0;
}
