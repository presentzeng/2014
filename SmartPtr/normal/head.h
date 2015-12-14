#ifndef _ptr_
#define _ptr_
#include <iostream>
#include <stdlib.h>
class type
{
public:
	type()
	{std::cout << "constructor\n";}
	~type()
	{std::cout << "destructor\n";}
	void func()
	{std::cout << "it is a test func\n";}
};
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


#endif
	
