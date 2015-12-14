#ifndef _BUFFER_
#define _BUFFER_

#include <stdint.h>
#include "NonCopyable.h"
#include "MutexLock.h"
#include "Condition.h"
#include <queue>

class Buffer : NonCopyable
{
private:
	mutable MutexLock mutex_;
	Condition full_;
	Condition empty_;

	uint32_t size_;
	std::queue<int> queue_;
public:
	Buffer(uint32_t size);	
	void push(int val);
	int pop();

	bool empty() const;	
	int32_t size() const;
};
#endif /*_BUFFER_*/
