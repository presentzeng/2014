#include "Producer.h"
#include "Buffer.h"
#include <iostream>
#include <stdlib.h>

Producer::Producer(Buffer &buffer)
	:buffer_(buffer)
{}

void Producer::run()
{
	while(1)
	{
		int num = rand() % 100;	
		std::cout << "size" << buffer_.size();
		buffer_.push(num);
		sleep(2);
	}
} 


