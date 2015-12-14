#include <iostream>
#include <stdint.h>

using namespace std;

class num
{
friend ostream &operator <<(ostream &os, num &one);
private:
	int n;
	int *m;
public:
	num()
	{cout << " constructrot \n";}
	explicit num(int i)
	{
		n = i;
		cout<< "with parameter constructor\n";
	}
	~num()
	{
		cout << "destructor" << endl;
	}
	num &operator++()
	{
		n++;
		return *this;
	}
	num operator++(int)
	{
		num temp(n);
		n++;
		return temp;
	}
	int &operator [](int index)
	{
		return m[index];
	}
	void p()
	{ 
		cout << n << endl;
	}
	
};
inline ostream &operator <<(ostream &os, num &one)
{ os << one.n; }
int main()
{
	num obj(4);
	//obj = 5;
	obj.p();

}
