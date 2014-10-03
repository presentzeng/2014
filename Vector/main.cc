#include "vector.hpp"

using namespace std;
int main()
{
	Vector<int>vec(4, 99);
	Vector<int>ve(2, 88);
	
	
	Vector<int>::iterator it = vec.begin();	
	it ++;
	vec.insert(it, ve.begin(), ve.begin() + 2);	


	vec.erase(vec.begin() + 1);
	for(Vector<int>::iterator it = vec.begin();
	it != vec.end();
	it++)
	{
		cout << *it << endl;
	}
	
}
