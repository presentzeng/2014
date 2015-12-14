#ifndef _ptr_
#define _ptr_
#define DISABLE_COPY_ASSIGN(name)\
	name(const name&);\
	void operator=(const name&)
#include <iostream>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

class String
{
private:	
	/** member value **/
	char * str_;
	int len_;
public:
	/** constructor **/	
	String();
	String(char * arr);
	String(const char * arr);
	/** destructor **/
	~String();
	/** copy constructor & assiment **/
	String(String & obj);
	
	/** capacity **/
	int size()
	{ return len_; }
	int length()	
	{ return len_; }
	/** print **/
	void p();

	/** overload **/	

	friend std::ostream &operator << (std::ostream& os, const String & obj);
	friend std::istream &operator >> (std::istream& is, String & obj);

	friend String operator + (const String &s1, const String &s2);
	
	char &operator[](int index)
	{ return str_[index]; }
	void operator += (String &obj);
	void operator += (String const &obj);
};

inline std::istream &operator >> (std::istream& is, String & obj)
{
	char temp[1024];
	if(is >> temp)
		strcpy(obj.str_, temp);
}
inline std::ostream &operator << (std::ostream& os, const String & obj)
{
	os  << obj.str_;
}
#endif
