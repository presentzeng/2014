#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <functional>

using namespace std;


//typedef void(*Func)();
typedef function<void(void)>Func;
void p()
{
	cout << "hello\n";
}

class base
{
public:
	base(Func call)
	:CallBack(call)
	{}
	
	void run()
	{
		CallBack();
	}			
private:
	Func CallBack;	
};

int main()
{
	base obj(&p);
	obj.run();
}
