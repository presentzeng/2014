#include <sys/mman.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <error.h> 

#define BUF_SIZE 100

int main(int argc, char **argv)
{
	int fd, nread, i;
	struct stat sb;
	char * mapped, buf[BUF_SIZE];

	/* open file */
	if((fd = open(argv[1], O_RDWR)) < 0)
	{
		perror("open");
	}

	/* get file attribute */
	if(fstat(fd, &sb) == -1)
	{
		perror("fstat");
	}

	/* mapping */
	if((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1)
	{
		perror("mmap");
	}
	/* file exists in memory */
	close(fd);
	
	/* keep checking */
	while(1)
	{
		printf("%s\n", mapped);
		sleep(2);	
	}
	return 0;
}
