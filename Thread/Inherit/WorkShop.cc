#include "WorkShop.h"
#include "Producer.h"
#include "Consumer.h"

WorkShop::WorkShop(uint32_t BufferSize,
		uint32_t ProducerSize,
		uint32_t ConsumerSize)
	:BufferSize_(BufferSize),
	buffer_(BufferSize_),
	ProducerSize_(ProducerSize),
	ConsumerSize_(ConsumerSize),
	producer_(ProducerSize_, new Producer(buffer_)),
	consumer_(ConsumerSize_, new Consumer(buffer_))
{}

WorkShop::~WorkShop()
{
	for(std::vector<Producer*>::iterator iter = producer_.begin();
	iter != producer_.end();
	++iter)
	{ delete *iter; }

	for(std::vector<Consumer*>::iterator iter = consumer_.begin();
	iter != consumer_.end();
	++iter)
	{ delete *iter; }
}

void WorkShop::StartWorking()
{
	for(std::vector<Producer*>::iterator it = producer_.begin();
	it != producer_.end();
	it++)
	{ (*it)->start(); }

	for(std::vector<Consumer*>::iterator it = consumer_.begin();
	it != consumer_.end();
	it++)
	{ (*it)->start(); }

	for(std::vector<Producer*>::iterator it = producer_.begin();
	it != producer_.end();
	it++)
	{ (*it)->join(); }

	for(std::vector<Consumer*>::iterator it = consumer_.begin();
	it != consumer_.end();
	it++)
	{ (*it)->join(); }
}
