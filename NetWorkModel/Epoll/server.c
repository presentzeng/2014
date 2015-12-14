#include "tcp.h"

void run(int sockfd);
int main()
{
	//int listenfd = TcpServer("192.168.1.24", 8976);
	int listenfd = TcpServer("127.0.0.1", 8976);
	int peerfd = accept(listenfd, NULL, NULL);//get communication fd
	//printf("%s connected\n", GetTcpInfor(peerfd));	

	run(peerfd);
	close(peerfd);
}

void run(int sockfd)
{
	char buf[1024000];
	int cnt = 0;
	while(1)	
	{
		int32_t nread = Recv(sockfd, buf, sizeof(buf));
		if(nread == 0)
		{
			printf("client close");
			break;
		}
		printf("cout = %d, recevie size = %d\n", ++cnt, nread);
		Send(sockfd, buf, nread);	
		memset(buf, 0, sizeof buf);
		sleep(2);
	}
}
