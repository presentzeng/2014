#ifndef _TCP_
#define _TCP_

#include <sys/epoll.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <netdb.h>
#include <netinet/tcp.h>
#define ERR_EXIT(m)\
	do{\
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

typedef struct sockaddr_in SAI;
typedef struct sockaddr SA;

int32_t Readn(int fd, void *buf, uint32_t count);//rewrite Read with buf
int32_t Writen(int fd, const void *buf, uint32_t count);//rewrite write with buf

void Send_Len(int sockfd, int32_t val);//send length first
int32_t Recv_Len(int sockfd);//recv length first

void SetAddReuse(int sockfd, int optval);//add reuse
void SetPortReuse(int sockfd, int optval);//port reuse

int TcpServer(const char *, uint64_t );//return listenfd
int TcpClient(const char *, uint64_t );//return peerfd
void Connect(int, const char*, uint16_t);//connect server

//const char* GetLocalIp();//return local ip

SAI GetPeerAddr(int peerfd);//get peerfd addr
SAI GetLocalAddr(int peerfd);//get local addr

const char* GetIp(const SAI *addr);//get ip
uint16_t GetPort(const SAI*addr);


const char *GetTcpInfor(int peerfd);//get tcp information

void Send(int, const void*, uint32_t);
uint32_t Recv(int, void*, uint32_t);

#endif /** _TCP_ **/
