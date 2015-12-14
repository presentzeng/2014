#include<unistd.h>
#include<stdio.h>
int main()
{
	
	printf("begin program:\n");	
//	char * buf;
	char buf[1024];	
	int pid;
	int fd[2];//fd[0]for son to read father to write
	pipe(fd);
	pid=fork();
	if(pid==0)
	{
		sleep(1);
		//close(fd[0]);
		printf("int children\n");
		if(-1 == read(fd[1],buf,sizeof(buf)))
		{	
			perror("read");
		}
		//close(fd[1]);
	}
	else
	{
		//close(fd[1]);
		printf("in father process");
		write(fd[0],"hello",6);
		wait();
		//close(fd[0]);		
	}
	
}
