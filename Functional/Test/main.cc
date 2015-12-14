#include<functional>
#include <iostream>

using namespace std;

void fun(const string &s)
{
	cout <<  s  << endl; 
}

int main()
{
	function<void (const string &)>f = & fun;
	f("hello world");	
}
