#include "Thread.h"
#include <iostream>

void func()
{
	while(1)
	{
		std::cout << " hello world \n";
		sleep(1);
	}
}


int main()
{
	Thread obj(&func);
	obj.start();
	obj.join();
}
