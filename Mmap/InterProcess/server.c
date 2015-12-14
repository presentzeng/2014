#include <sys/mman.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUF_SIZE 100

int main(int argc, char ** argv)
{
	int fd, nread, i;
	struct stat sb;
	char *mapped, buf[BUF_SIZE];
	
	if((fd = open(argv[1], O_RDWR)) < 0)
	{
		perror("open");
	}

	/* get file attribute */
	if(fstat(fd, &sb) == -1)
	{
		perror("fstat");
	}

	/* mapping the file to the
	process's address space */
	if((mapped = (char *)mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == (void *)-1)
	{
		perror("mmap");
	}

	/* close file descriptor*/
	close(fd);
//	printf("%s", mapped);

	/* modify one word */
	mapped[2] = '9';
	//if(msync((void *)mapped, sb.st_size, MS_SYNC) == -1)
	//{
	//	perror("msync");
	//}

	///* release shared space */
	//if(munmap((void *)mapped, sb.st_size) == -1)	
	//{
//		perror("munmap");
//	}
	return 0;
}
