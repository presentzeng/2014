#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	if(argc != 2)
	{
		fprintf(stderr, "Usage %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int i;
	//for(i = 0; i < argc; i++)
	//{
	//	printf("%s\n", argv[i]);
	//}
		printf("argv[1] :%s\n", argv[1]);
	if(stat(argv[1], &sb) == -1);
	{
		perror("stat");	
		//exit(EXIT_FAILURE);
	}
	switch(sb.st_mode & S_IFMT)
	{
		case S_IFSOCK: printf("socket\n"); break;
		case S_IFREG: printf("regular\n"); break;
		case S_IFDIR: printf("DIC\n"); break;
		case S_IFIFO: printf("fifo\n"); break;
		case S_IFBLK: printf("socket\n"); break;
		default : printf("unknow");
	}
	
}


