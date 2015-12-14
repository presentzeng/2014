#include <iostream>
#include <pthread.h>
using namespace std;

int s = 1;
int * str = &s;
//int square(volatile int * ptr);
int square(int * ptr);

void *handler(void *args)
{
	//(*str)++;	
	(*str) = ((*str) + 1)%10;
	//std::cout << square(str) << std::endl;
	cout << "str is " << *str << endl;
	cout << "square is " << square(str) << endl;
}
int square(int * ptr)//none volatile 
{
	return * ptr ** ptr;	
}
int main()
{
	pthread_t id;
	void * status;
	int i;
	for(i = 0; i < 10000; i++)
	{
		pthread_create(&id, NULL, handler, NULL);	
	}
	sleep(1);
	pthread_join(id, &status);
}
