#include "Thread.h"
#include <iostream>
#include <assert.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

Thread::Thread()
:threadId_(0),
IsRunning_(false){}

Thread::~Thread()
{
	if(IsRunning_)
	{
		pthread_detach(threadId_);
	}
}

void *Thread::runInThread(void *arg)
{
	Thread *pt = static_cast<Thread*>(arg);
	pt->run();	
	return NULL;
}


void Thread::start()
{
	pthread_create(&threadId_, NULL, Thread::runInThread, this);
	IsRunning_ = true;
}

void Thread::join()
{
	assert(IsRunning_);
	pthread_join(threadId_, NULL);
	IsRunning_ = false;
}


