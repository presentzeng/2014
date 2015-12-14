#include "Thread.h"

Thread::Thread()
	:ThreadId(0),
	IsRunning(false){}
Thread::~Thread()
{
	if(IsRunning)
	{ assert(!pthread_detach(ThreadId));}
}

void *Thread::handler(void *arg)
{
	Thread *pt = static_cast<Thread*>(arg);
	pt->run();
	return NULL;
}

void Thread::start()
{
	assert(!pthread_create(&ThreadId, NULL, handler, this));
	IsRunning = true;
}

void Thread::join()
{
	assert(!pthread_join(ThreadId, NULL));
	IsRunning = false;
}


