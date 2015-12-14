//#include "Thread.h"
//#include "Buffer.h"
//#include "Producer.h"
//#include "Consumer.h"
#include <iostream>
#include "WorkShop.h"

using namespace std;
//class MyThread : public Thread
//{
//public:
//	void run()
//	{ cout << "hello world\n"; }
//};
int main()
{
	WorkShop shop(5, 10, 10);
	shop.StartWorking();
}
