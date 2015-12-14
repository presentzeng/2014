#ifndef _ptr_
#define _ptr_
#include <iostream>
#include <stdlib.h>

class num
{
public:
	num()
	{std::cout << "constructor\n";}
	~num()
	{std::cout << "destructor\n";}
	void func()
	{std::cout << "it is a test func\n";}
};
template<typename type>
class SmartPtr
{
	private:
		SmartPtr(const SmartPtr &);//disable
		void operator=(const SmartPtr);

		type * ptr_;
	public:
		/** constructor **/
		SmartPtr(type *ptr = NULL);//default parameter
		~SmartPtr()
		{std::cout <<"ptr destructor\n";delete ptr_;}
		void resetPtr(type *ptr = NULL);

		type &operator*()
		{ return *ptr_; }	
		type &operator*()const
		{ return *ptr_; }

		type *operator->()
		{ return ptr_; }
		type *operator->()const
		{ return ptr_; }

		const type * getPtr()const
		{ return ptr_; }
};





	template<typename type>
	SmartPtr<type>::SmartPtr(type *ptr)
:ptr_(ptr)
{
	std::cout << "ptr constructor\n";
}
	template<typename type>
void SmartPtr<type>::resetPtr(type *ptr)
{
	if(ptr != ptr_)//reset ptr_ to ptr_
	{
		delete ptr_;
		ptr_ = ptr;
	}
}
#endif

