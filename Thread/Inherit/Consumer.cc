#include "Consumer.h"
#include "Buffer.h"
#include <iostream>

Consumer::Consumer(Buffer &buffer)
	:buffer_(buffer){}

void Consumer::run()
{
	while(1)
	{
		buffer_.pop();
		std::cout << "consumer size:" << buffer_.size() << std::endl;
		sleep(2);
	}
	
}
