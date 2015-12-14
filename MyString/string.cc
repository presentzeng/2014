#include "head.h"
using namespace std;
/** constructor **/
String::String()
{
	str_ = new char;
	*str_ = 0;
	len_ = 0;	
}
String::String(char * arr)
:str_(new char[strlen(arr) + 1])//add one for '\0'
{
	
	strcpy(str_, arr);	
	len_ = strlen(str_);
}

String::String(const char * arr)
:str_(new char[strlen(arr) + 1])
{
	strcpy(str_, arr);	
	len_ = strlen(str_);
}
/** destructor **/
String::~String()
{
	delete[] str_;
	len_ = 0;
}
/** copy constructor & assiment **/
String::String(String & obj)
{

}
/** print **/
void String::p()
{
	int index = 0;
	while(index < len_)
	{
		cout << str_[index] << endl;
		index++;
	}
}
/** overload **/

String operator + (const String &s1, const String &s2)
{
}
void String::operator += (String &obj)
{
	char * src = new char[obj.len_ + len_ +1];
	strcpy(src, str_);
	strcat(src, obj.str_);
	delete[] str_;	
	str_ = src;
}
void String::operator += (String const&obj)
{
	char * src = new char[obj.len_ + len_ +1];
	strcpy(src, str_);
	strcat(src, obj.str_);
	delete[] str_;	
	str_ = src;
}
