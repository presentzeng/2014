#include <string.h>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <iosfwd>
#include <string>

class StringPiece
{
private:
	const char * ptr_;
	int length_;

public:
	StringPiece():ptr_(NULL), length_(0){}

	StringPiece(const char* str)
	:ptr_(str),
	length_((str == NULL) ? 0 : static_cast<int>(strlen(str))) {}

	StringPiece(const std::string &str)
	:ptr_(str.data()),
	length_(static_cast<int>(str.size())){}

	StringPiece(const char *offset, int len)	
	:ptr_(offset),
	length_(len) {}

	const char * data() const { return ptr_; }//return ptr itself
	int size() const{ return length_; }
	int length()const{ return length_; }
	bool empty() const { return length_ == 0; }//is empty

	void clear()
	{
		ptr_ = NULL;
		length_ = 0;
	}
	
	void set(const char *data, int len)
	{
		ptr_ = data;
		length_ = len;
	}
	void set(const char * str)
	{
		ptr_ = str;
		if(str == NULL)
		{	
			length_ = static_cast<int>(strlen(str));
		}
		else
		{	
			length_ = 0;
		}
	}
	
	void set(const void *data, int len)
	{
		ptr_ = reinterpret_cast<const char *>(data);
		length_ = len;
	}
		
	char operator[](int i)const { return ptr_[i];}
	
	void remove_prefix(int n)
	{
		ptr_ += n;
		length_ -= n;
	}

	void remove_suffix(int n)
	{
		length_ -= n;
	}

	int compare(const StringPiece &x) const;
	
	//std::string as_string() const{}
	/** return in string form **/
	std::string toString()
	{
		return std::string(data(), size());	
	}
};
