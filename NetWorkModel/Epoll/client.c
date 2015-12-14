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
	
	int epoll_fd = epoll_create(2);

	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = sockfd;
	if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sockfd, &ev) == -1)
		ERR_EXIT("epoll_clt");

	ev.events = EPOLLIN;
	ev.data.fd = STDIN_FILENO;
	if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, STDIN_FILENO, &ev) == -1)
		ERR_EXIT("epoll_clt");

	struct epoll_event events[2];
	while(1)	
	{
		int nready = epoll_wait(epoll_fd, events, sizeof events, 5000);
		if(nready == -1)	
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("epoll_wait");
		}else if(nready == 0)
		{
			printf("timeout...\n");	
			continue;
		}
		
		int i;	
		for(i = 0; i < 2; i++ )
		{
			int fd = events[i].data.fd;
			if(fd == sockfd && events[i].events &EPOLLIN)
			{
				int nread = Recv(sockfd, recvbuf, sizeof recvbuf);
				if(nread == 0)
				{
					printf("close..\n");
					exit(EXIT_SUCCESS);
				}
				printf("recv :%s", recvbuf);
			}//if
			if(fd ==STDIN_FILENO && events[i].events & EPOLLIN)
			{
				fgets(sendbuf, sizeof sendbuf, stdin);
				Send(sockfd, sendbuf, strlen(sendbuf));
			}
		}
		memset(sendbuf, 0, sizeof sendbuf);
		memset(recvbuf, 0, sizeof recvbuf);
	}//while(1)
}
