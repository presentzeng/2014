#include "MyString.h"  
#include <iostream>  
#include <cstring>  
using namespace std;  
  
MyString::MyString()
{  
        data = new char[1];  
        *data = '\0';  
        size = 0;  
    }  
MyString::MyString(const char *ndata){  
        size = strlen(ndata);  
        copy(ndata, size);  
    }  
MyString::MyString(const MyString &s){  
        size = s.size;  
        copy(s.data, size);  
    }  
MyString& MyString::operator=(const MyString &s){  
        if (&s != this){  
            delete []data;  
            copy(s.data, s.size);  
            size = s.size;  
        }  
        return *this;  
    }  
    int MyString::getLength(){  
        return size;  
    }  
    MyString MyString::subString(int n){//获得指定长度的字符串,返回一个对象  
        MyString temp;  
        temp.size = n;  
        if (size >= n){  
            delete []temp.data;  
            temp.data = new char[n + 1];  
            char *odata = temp.data;//保存首地址  
            int count = 0;//计数  
            char *ndata = data;//保存当前对象的首地址  
            while (n != count){  
                *odata++ = *ndata++;  
                count++;  
            }  
            *odata = '\0';  
        }  
        return temp;  
  
    }  
    char MyString::operator[](int n){//重载[]，支持下标访问  
        if (size >= n){  
            char *temp = data;  
            int count = 1;//计数  
            while (n != count){  
                temp++;  
                count++;  
            }  
            return *temp;  
        }  
        return '\0';//越界返回\0  
    }  
    MyString MyString::operator+(const MyString &s){  
        MyString temp;  
        temp.size = size + s.size;  
        temp.data = new char[temp.size + 1];//申请合适的内存  
        char *tdata = temp.data;//保存temp的data首地址  
        char *thdata = data;//保存当前对象的data的首地址  
        while (*thdata){  
            *tdata++ = *thdata++;  
        }  
        char *sdata = s.data;   //保存+右边的对象的首地址  
        while (*sdata){  
            *tdata = *sdata;  
            tdata++;  
            sdata++;  
        }  
        *tdata = '\0';//补0  
        return temp;  
    }  
    MyString& MyString::operator+=(const MyString &s){  
        char *odata = data;//保存旧数据的地址  
        size += s.size;  
        copy(data, size + 1);   
        strcat(data,s.data);  
        delete []odata; //删除旧的  
        return *this;  
    }  
    ostream& operator<<(ostream &os, const MyString &s){  
        return os<<s.data;  
    }  
    istream& operator>>(istream &in, MyString &s){  
        char buf[1024];//字符缓冲区  
        in>>buf;  
        s.size = strlen(buf);  
        char *ndata = new char[s.size + 1];  
        char *temp = ndata; //保存ndata的首址  
        int i = 0;  
        while (s.size != i){  
            *temp = buf[i];  
            temp++;  
            i++;  
        }  
        *temp = '\0';  
        s.data = ndata;  
        return in;  
    }  
    MyString::~MyString(){  
        if (data){  
            delete []data;  
            size = 0;  
        }  
    }  
    void MyString::copy(const char *p, int nsize){  
        data = new char[nsize + 1];  
        if (*p != '\0'){  
            strcpy(data,p);  
        }else//空对象来初始化一个空对象  
            *data = '\0';  
    }  
  
