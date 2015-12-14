#include <iostream>
#include <string.h>
#include <stdint.h>

using namespace std;

template<typename T>
class test
{
private:
	T data_;	
public:	
	test(const T &o):data_(o) {}
	void p()const;
};

template<typename T>
void test<T>::p()const
{
	cout << data_ << endl;
}

int main()
{
	test<int>t(12);
	t.p();
	
}
