#include <iostream>
using namespace std;

int main()
{
	string a = "abcdefg";	
	const char b[10] = "hello";
	cout << a.substr(4).data() << endl;
}

