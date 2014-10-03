#ifndef _vec_
#define _vec_
#include <stdlib.h>
#include <stddef.h>
#include <iostream>
#include <memory>
#include <stdint.h>



template<typename T, typename Alloc = std::allocator<T> >
class Vector
{
public:
	typedef T value_type;
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T& reference;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef int32_t size_type;
	typedef Alloc allocator_type;
	typedef ptrdiff_t difference_type;
public:
	/**constructor **/
	Vector(){ create();}
	Vector(size_type n, const T& val = T())
	{ create(n, val); }

	Vector(const Vector &v)
	{ create(v.begin(), v.end());}
	/** member function **/
	void push_back(const T&);
	/** insert **/
	iterator insert(iterator po, const value_type &val);
	void insert(iterator po, size_type n, const value_type &v);	
	template<typename In>
	void insert(iterator po, In fist, In last);	

	/** erase **/
	iterator erase(iterator po);	
	iterator erase(iterator fi, iterator la);

	iterator begin(){ return data_; }
	iterator begin()const{ return data_; }

	iterator end() { return avail_; }
	iterator end()const { return avail_; }
	
	size_type size()const{ return avail_ - data_; }
	size_type capacity()const{ return limit_ - data_; }

	reference back(){ return *end();}	
	reference back()const{ return *end();}	

	reference front(){ return *begin();}	
	reference front()const{ return *begin();}	

	/** overload **/
	reference operator[](size_type n)
	{ return data_[n]; }
	reference operator[](size_type n)const
	{ return data_[n]; }
	Vector &operator=(const Vector &v);
private:
	/** base function **/
	void create();
	void create(size_type n, const T& val);
	template<typename In>
	void create(In, In);
	void expand();	
	void add(const T&);
	void uncreate();
private:
	/** member value **/
	iterator data_;//first
	iterator avail_;//last
	iterator limit_;//last memory

	std::allocator<T> alloc_;//tool
};//class Vector





/** overload **/

template<typename T, typename Alloc>
Vector<T, Alloc> &Vector<T, Alloc>:: operator=(const Vector &v)
{
	if(this != &v)	
	{
		uncreate();	
		create(v.begin(), v.end());
	}
	//return *this;//this sentence is not necessary
}

/** base fucntion **/
template<typename T, typename Alloc>
void Vector<T, Alloc>::uncreate()
{
	if(data_)	
	{
		iterator it(avail_);	
		while(it != data_)
			alloc_.destroy(--it);
	}


	alloc_.deallocate(data_, limit_ - data_);	
	data_ = limit_ = avail_ = NULL;
}

template<typename T, typename Alloc>
void Vector<T, Alloc>::create()
{
	data_ = avail_ = limit_ = NULL;
}

template<typename T, typename Alloc>
void Vector<T, Alloc>::create(size_type n, const T& val)
{
	//allocate n
	data_ = alloc_.allocate(n);	
	uninitialized_fill(data_, data_ + n, val);		
	avail_ = limit_ = data_ + n;
	//resize 
}

template<typename T, typename Alloc>
template<typename In>
void Vector<T, Alloc>::create(In i, In j)
{
	data_ = alloc_.allocate(j-i);
	avail_ = limit_ = uninitialized_copy(i, j, data_);
}


template<typename T, typename Alloc>
void Vector<T, Alloc>::expand()
{
	size_type current_size = limit_ - data_;
	size_type new_size = (current_size*2 > 1)? current_size*2 : 1;	

	iterator new_data = alloc_.allocate(new_size);
	iterator new_avail = uninitialized_copy(data_, avail_, new_data);
	uncreate();
	
	data_ = new_data;	
	avail_ = new_avail;
	limit_ = data_ + new_size;
}


template<typename T, typename Alloc>
void Vector<T, Alloc>::add(const T&val)
{
	alloc_.construct(avail_++, val);	
}

/** member function **/
template<typename T, typename Alloc>
typename Vector<T, Alloc>::iterator 
Vector<T, Alloc>::insert(iterator po, const value_type &val)
{
	difference_type pos = po - data_;
	insert(po, 1, val);	
}


template<typename T, typename Alloc>
void Vector<T, Alloc>::
insert(iterator po, size_type n, const value_type &v)	
{
	difference_type pos = po - data_;
	while(static_cast<size_type>(limit_ - avail_) < n)
	{ expand();}
	po = data_ + pos;
	size_type len = avail_ - po;
	uninitialized_copy(po, po + len, po + n);
	uninitialized_fill(po, po + n, v);
	avail_ += n;
	
}


template<typename T, typename Alloc>
template<typename In>
void Vector<T, Alloc>::
insert(iterator po, In first, In last)	
{
	difference_type pos = po - data_;
	size_type n = last -first;
	while(static_cast<size_type>(limit_ - avail_) < n)
	{ expand();}
	po = data_ + pos;
	size_type len = avail_ - po;
	uninitialized_copy(po, po + len, po + n);
	copy(first, last, po);
	//uninitialized_fill(po, po + n, v);
	
	avail_ += n;

}

template<typename T, typename Alloc>
typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator po)	
{
	copy(po + 1, avail_, po);	
	alloc_.destroy(--avail_);
	//return position;	
}

template<typename T, typename Alloc>
typename Vector<T, Alloc>::iterator Vector<T, Alloc>::erase(iterator first, iterator last)
{
	difference_type len = avail_ - last;
	copy(last, avail_, first);
	
	iterator it(first + len);	

	while(avail_ != it)
		alloc_.destroy(--avail_);
}

template<typename T, typename Alloc>
void Vector<T, Alloc>::push_back(const T&t)
{
	if(avail_ == limit_ )//full
		expand();
	add(t);
}


#endif /*_vec_*/
