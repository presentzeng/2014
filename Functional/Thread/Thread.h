#ifndef _THREAD_
#define _THREAD_

#include<functional>
#include<pthread.h>

class Thread 
{
private:
	Thread(const Thread&);
	void operator=(const Thread&);
public:	
	typedef std::function<void()>CallBack;
	
	Thread(CallBack CallFunc);
	~Thread();

	void start();
	void join();

	static void * StaticRun(void *);

private:
	pthread_t ThreadId;	
	bool IsRunning;
	CallBack CallFunc;
};

#endif
