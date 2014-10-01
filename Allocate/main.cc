#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test
{
public:
	Test(){ cout << "constructor\n"; }
	~Test(){ cout << "destructor\n"; }

	Test(const Test &t)
	{
		cout << " copy \n";
	}
	
};

int main()
{
	allocator<Test>alloc;
	Test * pt = alloc.allocate(3);	
	alloc.construct(pt, Test());	
	alloc.construct(pt+1, Test());	
	alloc.construct(pt+2, Test());	
	alloc.destroy(pt);
	alloc.destroy(pt+1);
	alloc.destroy(pt+2);
	
	alloc.deallocate(pt, 3);	
}
