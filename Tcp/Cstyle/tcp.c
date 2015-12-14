#include "tcp.h"

int TcpServer(const char *host, uint64_t port)//return listenfd
{
	int listenfd = socket(PF_INET, SOCK_STREAM, 0);//initial listenfd
	if(listenfd == -1)
	{
		ERR_EXIT("socket");
	}	
	SetAddReuse(listenfd, 1);//add reuse
	SetPortReuse(listenfd, 1);//port reuse

	SAI addr;
	memset(&addr, 0, sizeof addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);	
	//addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(host == NULL)
	{
		addr.sin_addr.s_addr = INADDR_ANY;//any network card
	}else if(inet_aton(host, &addr.sin_addr) == 0)
	{
		struct hostent *hp = gethostbyname(host);	
		if(hp == NULL)
			ERR_EXIT("gethostbyname");
		addr.sin_addr = *(struct in_addr*)hp->h_addr;

		if(bind(listenfd, (SA*)&addr, sizeof addr) == -1)
		ERR_EXIT("bind");

		if(listen(listenfd, SOMAXCONN) == -1)//skip listen !
		ERR_EXIT("listen");
	} else
	{
		addr.sin_addr.s_addr = inet_addr(host);
		printf("host:%s\n", host);
		if(bind(listenfd, (SA*)&addr, sizeof addr) == -1)
		ERR_EXIT("bind");

		if(listen(listenfd, SOMAXCONN) == -1)//skip listen !
		ERR_EXIT("listen");
	}
	
	return listenfd;
}

void SetAddReuse(int sockfd, int optval)//add reuse
{
	int on = (optval != 0)? 1:0;
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on) < 0)
		ERR_EXIT("setsockopt");
}
void SetPortReuse(int sockfd, int optval)//port reuse
{
#ifdef SO_REUSEPORT
    int on = (optval != 0) ? 1 : 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt SO_REUSEPORT");
#else
    fprintf(stderr, "SO_REUSEPORT is not supported.\n");
#endif //SO_REUSEPORT
}
  
SAI GetPeerAddr(int peerfd)//get peerfd addr
{
	SAI addr;
	memset(&addr, 0, sizeof addr);
	addr.sin_family = AF_INET;
	socklen_t len = sizeof addr;
	if(getpeername(peerfd, (SA*)&addr, &len) == -1)
		ERR_EXIT("getpeername");
	return addr;
}
SAI GetLocalAddr(int peerfd)//get local addr
{
	SAI addr;
	memset(&addr, 0, sizeof addr);
	addr.sin_family = AF_INET;
	socklen_t len = sizeof addr;
	if(getsockname(peerfd, (SA*)&addr, &len) == -1)
		ERR_EXIT("getpeername");
}


const char* GetIp(const SAI *addr)//get ip
{
	return inet_ntoa(addr->sin_addr);
}
uint16_t GetPort(const SAI*addr)
{
	return ntohs(addr->sin_port);
}

const char *GetTcpInfor(int peerfd)//get tcp information
{
	static char infor[100] = "";
	//store information 		
	SAI Peer = GetPeerAddr(peerfd);//get peerfd addr
	SAI Local = GetLocalAddr(peerfd);//get local addr
	
	snprintf(infor, sizeof infor, "%s:%d -> %s:%d",	
	GetIp(&Local),//get ip
	GetPort(&Local),
	GetIp(&Peer),//get port
	GetPort(&Peer));

	return infor;
}
  

int TcpClient(const char* host, uint64_t port)//return peerfd
{
	int peerfd = socket(PF_INET, SOCK_STREAM, 0);		
	if(peerfd == -1)
		ERR_EXIT("socket");	
	
	if(port == 0)//if port=0 then no need to bind
		return peerfd;
	SetAddReuse(peerfd, 1);//add reuse

	SAI addr;	
	memset(&addr, 0, sizeof addr);	
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(host);
	if(bind(peerfd, (SA*)&addr, sizeof addr) == -1)
		ERR_EXIT("bind client");
	return peerfd;
}
void Connect(int sockfd, const char* host, uint16_t port)//connect server
{
	if(host == NULL)	
	{
		fprintf(stderr, "host cannot be NULL\n");
		exit(EXIT_FAILURE);
	}
	
	SAI seraddr;	
	memset(&seraddr, 0, sizeof seraddr);
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(port);
	if(inet_aton(host, &seraddr.sin_addr) == 0)//addr is no valid
	{
		struct hostent *hp = gethostbyname(host);		
		if(hp == NULL)
			ERR_EXIT("gethostbyname");
		seraddr.sin_addr = *(struct in_addr*)hp->h_addr;
	}	
	if(connect(sockfd, (SA*)&seraddr, sizeof seraddr))	
		ERR_EXIT("connect");
}

//write
int32_t Writen(int fd, const void *buf, uint32_t count)//rewrite write with buf
{
	uint32_t nleft = count;//how many left
	uint32_t nwrite;
	const char* bufp = (const char*)buf;
	
	while(nleft > 0)	
	{
		nwrite = write(fd, bufp, nleft);
		if( nwrite <= 0)
		{
			if(nwrite == -1 && errno == EINTR)
				continue;
			return -1;
		}
		nleft -= nwrite;
		bufp += nwrite;
	}
	return (count - nleft);
}

void Send_Len(int sockfd, int32_t val)//send length first
{
	int32_t temp = htonl(val);
	if(Writen(sockfd, &temp, sizeof(int32_t)) != sizeof(int32_t))
		ERR_EXIT("Send_Len");
		
}

void Send(int fd, const void* buf, uint32_t size)
{
	Send_Len(fd, size);	
	if(Writen(fd, buf, size) != size)
		ERR_EXIT("Send");
}

int32_t Readn(int fd, void *buf, uint32_t count)//rewrite Read with buf
{
	int nread;
	int nleft = count;
	char *bufp = (char*)buf;

	while(nleft > 0)
	{
		nread = read(fd, bufp, nleft);					
		if(nread == -1)
		{
			if(errno == EINTR)
				continue;
			return -1;	
		}	
		else if(nread == 0)
			break;
		nleft -= nread;
		bufp += nread;
	}
	return count - nleft;	
}
int32_t Recv_Len(int sockfd)//recv length first
{
	int32_t temp;
	int nread = Readn(sockfd, &temp, sizeof(int32_t));
	if(nread == -1)
		ERR_EXIT("Recv_Len");
	else if(nread < sizeof(int32_t))
		return 0;
	return ntohl(temp);//mistake for ntohs
}
uint32_t Recv(int sockfd, void* buf, uint32_t size)
{
	int32_t len = Recv_Len(sockfd);
	if(len == 0)
		return 0;
	else if(len > (int32_t)size)	
	{
		fprintf(stderr, "bufsize is no enough");
		exit(EXIT_FAILURE);
	}
	
	int32_t nread = Readn(sockfd, buf, len);	
	if(nread == -1)
		ERR_EXIT("Recv");
	else if((int32_t)nread < len)
	{
		return 0;
	}

	return len;
}
