#ifndef THREAD
#define THREAD

#include "NonCopyable.h"
#include <pthread.h>
#include <sys/types.h>

class Thread : NonCopyable
{
private:
	static void * runInThread(void * arg);
	pthread_t threadId_;
	bool IsRunning_;
public:
	Thread();	
	~Thread();	
	
	virtual void run() = 0;
	
	void start();
	void join();
	
	pthread_t getThreadId() const
	{ return threadId_; }
};
#endif 
