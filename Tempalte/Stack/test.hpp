#ifndef _stack_
#define _stack_
#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T, int MAXSIZE >
class stack
{
private: 
	T elems_ [MAXSIZE];
	int num_;	
public:
	stack();
	void push(const T &);
	void pop();
	T top() const;

	bool empty() const
	{ return 0 == num_; }
	bool full() const
	{ return MAXSIZE == num_; }

	template <typename T2, int MAXSIZE2>
	 stack<T, MAXSIZE>&operator= 
	(const stack<T2, MAXSIZE2> &other);
};//class stack
template <typename T, int MAXSIZE>
stack<T, MAXSIZE>::stack()
:num_(0) {}

template <typename T, int MAXSIZE>
void stack<T, MAXSIZE>::push(const T &elem)
{
	if(full())
		throw std::runtime_error("full");
	elems_[num_++] = elem;
}


template <typename T, int MAXSIZE>
void stack<T, MAXSIZE>::pop()
{
	if(empty())
		throw std::runtime_error("empty");
	--num_;
}

template <typename T, int MAXSIZE>
T stack<T, MAXSIZE>::top() const
{
	return elems_[num_ - 1];
}
template <typename T, int MAXSIZE>
template <typename T2, int MAXSIZE2>
stack<T, MAXSIZE>& stack<T, MAXSIZE>::operator= 
(const stack<T2, MAXSIZE2> &other)
{
	if((void*)this == (void*)&other)
		return *this;

	num_ = 0;
	stack<T2, MAXSIZE>temp(other);	
	
	while(!temp.empty())
	{
		push(temp.top());
		temp.pop();
	}
	return *this;
}
#endif /** _stack_ **/
