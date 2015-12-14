#include "head.h"
using namespace std;
int main()
{
	String s("99");
	const String s1("abce");
	s += s1;
	cout << s;
}
