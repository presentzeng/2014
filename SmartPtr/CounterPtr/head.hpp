#ifndef _ptr_
#define _ptr_
#include <iostream>
#include <stdlib.h>

template<typename type>
class CounterPtr
{
private:
	void dispose()
	{
		if(--*count_ == 0)
		{
			delete ptr_;
			delete count_;
		}
	}

	type *ptr_;
	size_t *count_;
public:
	typedef type value_type; 
	typedef type* pointer;
	typedef const type* const_pointer;
	typedef type& referrence;
	typedef const type& const_referrence;

	explicit CounterPtr(type *p = NULL);
	CounterPtr(const CounterPtr<type>&other);	
	~CounterPtr();	
	size_t count() const { return *count_;}
	CounterPtr<type>&operator=(const CounterPtr<type>&other);

	type &operator*()throw()
	{ return *ptr_; }	
	type &operator*()const throw()
	{ return *ptr_; }

	type *operator->()throw()
	{ return ptr_; }
	type *operator->()const throw()
	{ return ptr_; }

	int32_t swap(CounterPtr<type>&other)throw()
	{
		std::swap(ptr_, other.ptr_);
		std::swap(count_, other.count_);
		return 1;
	}

	void reset() throw()
	{ dispose(); }
	void resetPtr()
	{ dispose(); }


	type * getPtr()const throw()
	{ return ptr_; }
};

template<typename T>
CounterPtr<T>::CounterPtr(T *p)
	:ptr_(p), count_(new size_t(1))
{}

template<typename T>
CounterPtr<T>::CounterPtr(const CounterPtr<T>&other)
	:ptr_(other.ptr_), count_(other.count_)
	{ ++*count_; }

template<typename T>
 CounterPtr<T>::~CounterPtr()
{ dispose(); }

template<typename T>
CounterPtr<T>&CounterPtr<T>::operator = (const CounterPtr<T>&other)
{
	++*other.count_;
	dispose();
	ptr_ = other.ptr_;
	count_ = other.count_;
	return *this;
}


#endif
