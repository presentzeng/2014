#include "head.hpp"

using namespace std;

int main()
{
	SmartPtr<num>ptr(new num);
	//SmartPtr ptr(new type);
	cout << ptr.getPtr() << endl;
	ptr->func();	
	////ptr.resetPtr();
	//ptr.resetPtr(new type);
	//cout << ptr.getPtr() << endl;
}
