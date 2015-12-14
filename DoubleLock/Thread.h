#ifndef _Thread_
#define _Thread_

#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "NonCopy.h"
class Thread : NonCopy
{
public:
	Thread();	
	
	virtual ~Thread();

	void start();
	void join();
	
	virtual void run() = 0;
	
	pthread_t GetId() const
	{ return ThreadId; }
private:
	static void * handler(void *arg);
	pthread_t ThreadId;
	bool IsRunning;
};

#endif
