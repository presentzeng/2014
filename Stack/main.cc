#include "stack.hpp"

using namespace std;
int main()
{
	::stack<int, deque<int> > st;
	st.push(12);
	st.top() = 1;
	cout << st.top() << endl;
}
