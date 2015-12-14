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
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1)
		ERR_EXIT("socket");
	//address reuse
	int on = 1;
	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on) < 0)
		ERR_EXIT("setsocketopt");

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof addr);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(8976);
	//bind	
	if(bind(listenfd, (struct sockaddr*)&addr, sizeof addr) == -1)
		ERR_EXIT("bind");

	if(listen(listenfd, SOMAXCONN) == -1)
		ERR_EXIT("listen");
	int peerfd = accept(listenfd, NULL, NULL);
	char buf[123] = "";
	read(peerfd, buf, sizeof buf);	

	printf("buf::%s\n", buf);

	SAI localaddr;	 
	
	socklen_t len = sizeof localaddr;
	getsockname(peerfd, (SA*)&localaddr, &len);//get localaddr
		
	char * p = inet_ntoa(localaddr.sin_addr);
	uint16_t s = ntohs(localaddr.sin_port);
	printf("ip :%s\n", p);
	printf("port :%d\n", s);

	close(peerfd);
	close(listenfd);
}
