#include "tcp.h"
#include "epoll.h"

void run(int, const char*, int);
int main()
{
	int listenfd = TcpServer("127.0.0.1", 8976);
	epoll_t et;
	epoll_init(&et, listenfd, &run);


	while(1)
	{	
		epoll_loop(&et);	
		epoll_handle_fd(&et);
	}
	//epoll_destroy(&et);
	close(et.epoll_fd_);
	close(listenfd);	
}

void run(int sockfd, char const *buf, int count)
{
	printf("recv%s\n", buf);	
	Send(sockfd, buf, strlen(buf));
}
