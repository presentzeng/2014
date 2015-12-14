#include "head.h"

SmartPtr::SmartPtr(type *ptr)
	:ptr_(ptr)
{
	std::cout << "ptr constructor\n";
}
void SmartPtr::resetPtr(type *ptr)
{
	if(ptr != ptr_)//reset ptr_ to ptr_
	{
		delete ptr_;
		ptr_ = ptr;
	}
}
