#include "MutexLock.h"
#include <assert.h>

MutexLock::MutexLock()
	:IsLocking_(false)
{ assert(!pthread_mutex_init(&mutex_, NULL));}

MutexLock::~MutexLock()
{
	assert(!IsLocking());
	assert(!pthread_mutex_destroy(&mutex_));
}

void MutexLock::lock()
{
	assert(!pthread_mutex_lock(&mutex_));
	IsLocking_ = true;
}

void MutexLock::unlock()
{
	IsLocking_ = false;
	assert(!pthread_mutex_unlock(&mutex_));
}
