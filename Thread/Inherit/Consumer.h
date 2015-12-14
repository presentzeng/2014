#ifndef CONSUMER
#define CONSUMER

#include "Thread.h"

class Buffer;

class Consumer : public Thread
{
private:
	Buffer &buffer_;
public:
	void run();
	Consumer(Buffer &buffer);
};

#endif /*CONSUMER*/
