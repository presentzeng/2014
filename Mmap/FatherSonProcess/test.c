#include <sys/mman.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>

#define BUF_SIZE 100

int main()
{
	char * p_map;	

	p_map = (char *)mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS ,-1, 0);
	
	if(fork() == 0)	
	{
		sleep(1);
		printf("child got a message: %s\n", p_map);
		sprintf(p_map, "%s", "hi this is son");
		//munmap();
		exit(0);
	}
	sprintf(p_map, "%s", "this is father");
	sleep(2);
	printf("parent got a message %s\n", p_map);
}

