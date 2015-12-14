#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int i;
	pid_t pid=fork();
	if(pid==0)
	{
		printf("child\n");
		//exit(1);
	}
	else if(pid>0)
	{
		printf("father\n");
		wait(NULL);
		exit(1);
	}
	printf("hello world\n");
	return 0;
}
