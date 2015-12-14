#include <iostream>
#include <string.h>

class string
{
public:
	string();
	string(const char* str = NULL);
	string(const string &other);
	~string(void);
	string &operator = (const string *other);
	
	int size()
	{ return strlen(data_); }
private:
	char * data_;
};
