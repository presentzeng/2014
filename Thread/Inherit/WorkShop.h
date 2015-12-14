#ifndef WORKSHOP
#define WORKSHOP

#include "NonCopyable.h"
#include "Buffer.h"
#include <vector>

class Producer;
class Consumer;

class WorkShop : NonCopyable
{
public:
	WorkShop(uint32_t buffersize,
	uint32_t ProducerSize,
	uint32_t ConsumerSize);
	~WorkShop();
	void StartWorking();
private:
	uint32_t BufferSize_;
	Buffer buffer_;
	
	uint32_t ProducerSize_;
	uint32_t ConsumerSize_;
	
	std::vector<Producer*>producer_;
	std::vector<Consumer*>consumer_;
};
#endif
