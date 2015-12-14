#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void * handler(void *arg)
{
	pthread_detach(pthread_self());
	cout << "hello world" << endl;
}

int main()
{
	pthread_t pd;
	pthread_create(&pd, NULL, handler, NULL);
	sleep(1);
}
