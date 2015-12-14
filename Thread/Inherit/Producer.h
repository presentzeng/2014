#ifndef PRODUCER
#define PRODUCER

#include "Thread.h"
class Buffer;

class Producer : public Thread
{
private:
	Buffer &buffer_;
public:
	Producer(Buffer &buffer);	
	void run();
};

#endif /*PRODUCER*/
