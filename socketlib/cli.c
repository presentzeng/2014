#include"MyNetOperation.h"
void chan(char * arry)
{
	
}
int main()
{
	int fd;
	MySocket(&fd,SOCK_DGRAM,ClientType,MYPORT,MYIP,chan);
	//Chat(&fd,chan,ClientType);
}
