#include"MyNetOperation.h"
void chan(char * arry)
{
	printf("fucntion pointer\n");
	arry[0]=arry[0]+1;
	arry[1]=arry[1]+1;
}
int main()//server
{
	int fd;
	MySocket(&fd,SOCK_DGRAM,ServerType,MYPORT,MYIP,chan);
	//Chat(&fd,chan,ServerType);
}
