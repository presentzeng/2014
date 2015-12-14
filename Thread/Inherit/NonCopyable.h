#ifndef NOCOPYABLE
#define NOCOPYABLE

class NonCopyable
{
private:
	NonCopyable(const NonCopyable&);
	void operator = (const NonCopyable&);
public:	
	NonCopyable(){}
	~NonCopyable(){}
};

#endif /* NonCopyable*/
