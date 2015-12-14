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
	//write(sockfd, "hello", 7);
	#define SIZE 1024
	char sendbuf[SIZE + 1] = "";
	int cnt = 0;
	while(1)
	{
		int i;
		for(i = 0; i < 10; i++)
		{
			Send(sockfd, sendbuf, SIZE);	
			printf("cout = %d, Send size = %d\n", ++cnt, SIZE);
		}
		sleep(1);
	}
}
