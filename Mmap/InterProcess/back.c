#include <sys/mman.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <error.h>  
  
#define BUF_SIZE 100  

int main(int argc, char ** argv)
{
	int fd, nread, i;
	struct stat sb;
	char * mapped, buf[BUF_SIZE];

	/* open file */
	if((fd = open(argv[1], O_RDWR)) < 0)
	{
		perror("open");
	}

	/* get file contribute */
	if(fstat(fd, &sb) == -1)
	{
		perror("fstat");
	}
	
	/* mapping */
	if((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0)) == (void *)-1)
	{
		perror("mmap");	
	}

	/* close */
	close(fd);
	
	/* modify one */
	mapped[2] = 'a';

	if(msync((void *)mapped, sb.st_size, MS_SYNC) == -1)
	{
		perror("msync");
	}

	/* release shared space */
	if(munmap((void *)mapped, sb.st_size) == -1)	
	{
		perror("munmap");
	}
	return 0;
}
