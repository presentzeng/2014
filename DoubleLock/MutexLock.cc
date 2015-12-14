#include "MutexLock.h"

MutexLock::MutexLock()
{
	IsLocking = false;
	assert(!pthread_mutex_init(&mutex, NULL));
}
MutexLock::~MutexLock()
{
	assert(!IsLocked());
	assert(!pthread_mutex_destroy(&mutex));
}

void MutexLock::lock()
{
	assert(!pthread_mutex_lock(&mutex));
	IsLocking = true;
}

void MutexLock::unlock()
{
	assert(!pthread_mutex_unlock(&mutex));
	IsLocking = false;
}
