#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define ERR_EXIT(m)\
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

typedef struct sockaddr SA;
typedef struct sockaddr_in SAI;

int main()
{
	int peerfd = socket(AF_INET, SOCK_STREAM, 0);
	if(peerfd == -1)
		ERR_EXIT("socket");	

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof addr);	
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(8976);
	socklen_t len = sizeof addr;
	
	if(connect(peerfd, (struct sockaddr*)&addr, len) == -1)
		ERR_EXIT("connect");	
			
	write(peerfd, "hello", 7);		

	SAI localaddr;	 
	
	getpeername(peerfd, (SA*)&localaddr, &len);//get peer addr

	socklen_t len1 = sizeof localaddr;
	char * p = inet_ntoa(localaddr.sin_addr);
	uint16_t s = ntohs(localaddr.sin_port);
	printf("ip :%s\n", p);
	printf("port :%d\n", s);

	
	return 0;
}
