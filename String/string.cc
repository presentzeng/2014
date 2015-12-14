#include "head.h"


string::string()
	:data_(new char[1])
{
	*data_ = '\0';
}

string::string(const char * str)
	:data_(new char[strlen(str)] + 1)
{
	strcpy(data_, str);	
}

string::string(const string &other)
	:data_(new char[other.size() + 1])
{
	strcpy(data_, str);	
}
