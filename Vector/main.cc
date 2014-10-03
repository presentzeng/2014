#include "vector.hpp"

using namespace std;
int main()
{
	Vector<int>vec;
	for(int index = 1; index < 5; index++)
	{
		vec.push_back(index);
	}
	Vector<int>::reverse_iterator it = vec.begin();
	cout << *it << endl;
}
