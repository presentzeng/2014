#ifndef MYSTRING_H  
#define MYSTRING_H  
#include <cstring>  
#include <iostream>  
class MyString{  
public:  
    MyString();//default constructor  
    MyString(const char *ndata);//constructor with argument  
    MyString(const MyString &s);//copy constructor  
    MyString& operator=(const MyString &s);//assignment constructor  
    int getLength();//获得串的长度  
    MyString subString(int n);//获得指定长度的字符串,返回一个对象  
    char operator[](int n);//重载[]，支持下标访问  
    MyString operator+(const MyString &s);//重载+  
    MyString& operator+=(const MyString &s);//重载+=  
    //下面几个也可以用成员函数来重载  


    friend bool operator>(const MyString &s1, const MyString &s2){  
        return strcmp(s1.data,s2.data) > 0 ? true : false;  
    }  
    friend bool operator<(const MyString &s1, const MyString &s2){  
        return strcmp(s1.data,s2.data) < 0 ? true : false;  
    }  
    friend bool operator==(const MyString &s1, const MyString &s2){  
        return strcmp(s1.data,s2.data) == 0 ? true : false;  
    }  
    friend bool operator!=(const MyString &s1, const MyString &s2){  
        return strcmp(s1.data,s2.data) == 0 ? false : true;  
    }  
    //注意重载<<的时候不能改变对象的状态，不然g++的时候就编译不成功了  
    friend std::ostream& operator<<(std::ostream &os, const MyString &s);  
    friend std::istream& operator>>(std::istream &in, MyString &s);  
    ~MyString();//destructor  
private:  
    char *data;  
    int size;//串的长度  
    void copy(const char *p, int nsize);//完成copy功能  
      
};  
#endif  
