#include <iostream>
#include <string.h>
#include <stdint.h>

using namespace std;

template<typename T>
const T &max(const T &a, const T &b)
{
	cout << "two parameter\n"; 
	return a > b ? a : b;
}

const char * max(const char * a, const char * b)
{
	cout << "in char \n";
	return ::strcmp(a, b) > 0 ? a : b;
}


template<typename T>
const T &max(const T &a, const T &b, const T &c)
{
	::max(a, ::max(b, c));
	cout << "three parameter\n"; 
	
}
int main()
{
	::max(1 ,2, 3);
	cout  << ::max("a","b") << endl;
}

