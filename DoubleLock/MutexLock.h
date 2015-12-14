#ifndef _Lock_
#define _Lock_

#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "NonCopy.h"

class MutexLock : NonCopy
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
	bool IsLocked()
	{ return IsLocking; }
private:
	pthread_mutex_t mutex;	
	bool IsLocking;
};
#endif
