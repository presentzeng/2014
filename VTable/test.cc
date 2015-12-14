#include <iostream>

using namespace std;

class base
{
private:
	virtual void p()
	{cout << "base\n";}
};

class derived : public base
{
public:
	//void p()
	//{ cout << "derived";}
};

typedef void(*Func)(void);
int main()
{
	//base *p = new derived();
	//p->p();

	derived obj;	
	Func p = (Func)*((int*)*(int*)(&obj + 0));//will call base::p();
	p();
}
