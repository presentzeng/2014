#include "tcp.h"

void run(int);
int main()
{
	int peerfd = TcpClient("192.168.1.24", 9999);	
	Connect(peerfd, "127.0.0.1", 8976);	
	run(peerfd);
	close(peerfd);
}
void run(int sockfd)
{

#define SIZE 1024
	char sendbuf[SIZE] = "";
	char recvbuf[SIZE] = "";
	//write(sockfd, "hello", 7);
	while(1)
	{
		struct pollfd fds[2];
		fds[0].fd = sockfd;
		fds[0].events = POLLIN;
		fds[1].fd = STDIN_FILENO;
		fds[1].events = POLLIN; 

		int nready = poll(fds, sizeof fds, 5000);		
		sleep(1);
		if(nready == -1)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("poll");
		}else if(nready == 0)
		{
			printf("time out..\n");
			continue;
		}
		
		if(fds[0].revents & POLLIN)
		{
			int nread = Recv(sockfd, recvbuf, sizeof recvbuf);
			if(nread == 0)
			{
				printf("close\n");
				exit(EXIT_SUCCESS);
			}
			printf("recv mst: %s\n", recvbuf);
		}
		if(fds[1].revents & POLLIN)
		{
			fgets(sendbuf, sizeof sendbuf, stdin);
			Send(sockfd, sendbuf, strlen(sendbuf));
		}
		memset(sendbuf, 0, sizeof sendbuf);	
		memset(recvbuf, 0, sizeof recvbuf);	
	}//while(1)
}
