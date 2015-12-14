#include "Thread.h"

Thread::Thread(CallBack Call)
	:ThreadId(0),
	IsRunning(false),
	CallFunc(std::move(Call)) {}


Thread::~Thread()
{
	if(IsRunning)
	{
		pthread_detach(ThreadId);
	}
}

void *Thread::StaticRun(void *arg)
{
	Thread * pt = static_cast<Thread*>(arg);
	pt->CallFunc();
	return NULL;
}

void Thread::start()
{
	pthread_create(&ThreadId, NULL, StaticRun, this);
	IsRunning = true;
}

void Thread::join()
{
	pthread_join(ThreadId, NULL);	
	IsRunning = false;
}
