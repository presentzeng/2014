#ifndef _MUTEXLOCK_
#define _MUTEXLOCK_

#include "NonCopyable.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

class MutexLock :NonCopyable
{
private:
	pthread_mutex_t mutex_;
	bool IsLocking_;
public:
	MutexLock();	
	~MutexLock();	
	void lock();
	void unlock();
	
	bool IsLocking()const
	{ return IsLocking_; }
	pthread_mutex_t *getMutexPtr()
	{ return & mutex_; }
};

class MutexLockGuard : NonCopyable
{
private:
	MutexLock &mutex_;
public:
	MutexLockGuard(MutexLock &mutex)
	:mutex_(mutex){ mutex_.lock(); }
	~MutexLockGuard()
	{ mutex_.unlock(); }
};
#endif 
