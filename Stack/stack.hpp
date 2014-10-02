#ifndef _stack_
#define _stack_
#include <deque>
#include <iostream>
#include <stdexcept>
#include <stdint.h>
#include <vector>
#include <memory>


template<typename T,
typename Alloc = std::allocator<T>,
typename CONT = std::vector<T> >
class stack
{
public:
	/** typedef **/
	typedef int64_t size_type;
	typedef Alloc allocator_type;
private:
	CONT elems_;
	size_type num_;	
	//std::vector<T>elem_;
public:
	/** constructor **/
	stack()
	:num_(0){ std::cout << "construstor\n";}
	//stack(size_type n, const)
		

	/** functions **/
	void push(const T &t);
	void pop();
	T &top();
	
	bool empty() const
	{ return elems_.empty(); }
	size_type size() const
	{ return num_; }
};

/** func **/
template<typename T,
typename Alloc,
typename CONT>
void stack<T, Alloc, CONT>::push(const T &t)
{
	elems_.push_back(t);		
	num_ ++;
}


template<typename T,
typename Alloc,
typename CONT>
void stack<T, Alloc, CONT>::pop()
{
	elems_.pop();
	num_ --;
}


template<typename T,
typename Alloc,
typename CONT>
T &stack<T, Alloc, CONT>::top()
{
	if(elems_.empty())
		throw std::out_of_range("f");
	return elems_.back();
}
#endif /*_stack_*/
