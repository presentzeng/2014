#include "test.hpp"
#include <deque>

using namespace std;
int main()
{
	try
	{
		stack<int, 5>s;
		stack<int, 10>s1;
		//s = s1;
	}
	catch(exception & e)
	{
		cout << e.what();
	}
}	
