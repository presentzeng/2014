#include "head.h"

using namespace std;

int main()
{
	SmartPtr ptr(new type);
	cout << ptr.getPtr() << endl;
	ptr->func();	
	//ptr.resetPtr();
	ptr.resetPtr(new type);
	cout << ptr.getPtr() << endl;
}
