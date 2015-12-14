#include "MutexLock.h"
#include "Thread.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int64_t getUTime();

class Single
{
public:
	static Single * get()
	{
		if(p == NULL)
		{
		      mutex.lock();	
		      if(p == NULL)	
		      {
		      	p = new Single;
		      }
		      mutex.unlock();	
		}
			return p;
	}
private:
	Single(){}
	static Single * p;

	static MutexLock mutex;
};
Single * Single::p = NULL;
MutexLock Single::mutex;

class ThreadSon : public Thread
{
	public:
		void run()
		{
			cout << Single::get() << endl;
			cout << Single::get() << endl;
		}
};
int N = 1000 ;
int main()
{
	int64_t start = getUTime();
	ThreadSon th[N];
	for(int x = 0; x != N; x++)	
	{
		th[x].start();
	}
	for(int x = 0; x != N; x++)	
	{
		th[x].join();
	}
	int64_t end= getUTime();
	cout << "duration" << double(end - start) << endl;
}

int64_t getUTime()
{
	struct timeval tv;
	::memset(&tv, 0, sizeof tv);
	if(gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		exit(EXIT_FAILURE);
	}
	int64_t current = tv.tv_usec;
	current += tv.tv_sec * 1000 * 1000;
	return current;
}
