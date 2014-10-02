#include "vector.hpp"

using namespace std;
int main()
{
	Vector<int>vec(4, 99);
	Vector<int>ve = vec;
	
	cout << ve.size() << endl;
}
