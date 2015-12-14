#ifndef _copy_
#define _copy_

class NonCopy
{
protected:
	NonCopy(){}
	~NonCopy(){}
private:
	NonCopy(const NonCopy&);
	void operator=(const NonCopy&);
};


#endif
