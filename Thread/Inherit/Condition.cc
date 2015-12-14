#include "Condition.h"
#include "MutexLock.h"
#include <assert.h>


Condition:: Condition(MutexLock &mutex)	
	:mutex_(mutex)
{
	assert(!pthread_cond_init(&cond_, NULL));
}
Condition:: ~Condition()
{
	assert(!pthread_cond_destroy(&cond_));
}

void Condition::wait()
{
	assert(mutex_.IsLocking());
	assert(!pthread_cond_wait(&cond_, mutex_.getMutexPtr()));
}
void Condition::notify()
{
	assert(!pthread_cond_signal(&cond_));
}
void Condition::notifyAll()
{
	assert(!pthread_cond_broadcast(&cond_));
}

