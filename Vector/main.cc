#include "vector.hpp"

using namespace std;
int main()
{
	Vector<int>vec(4, 99);
	for(Vector<int>::iterator it = vec.begin();
	it != vec.end();
	it++)
	{
		cout << *it << endl;
	}
}
