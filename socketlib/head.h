#ifndef _NET_OPERATION_
#define _NET_OPERATION_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <netdb.h>
#define IN
#define OUT
#define  ClientType 1
#define  ServerType 0
#define MYPORT 9999
#define MYIP "192.168.0.173"
#define MY_ASSERT(flag,msg) ((flag)? NULL:(fprintf(stdout,msg),exit(1)))
typedef struct sockaddr_in SA;
typedef int Status;
typedef struct sockaddr* pSA;
void MySocket(OUT int *ofd,IN int nettype,IN int usertype,IN int port,IN char *ip);
void chat(IN int *ofd);
#endif
