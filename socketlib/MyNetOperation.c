#include"MyNetOperation.h"
typedef struct Melem
{
	void (*func)();		
	char *msg;	
	int usertype;
	SA *paddr;
	int *fd;	
}elem;
void * send_handler(void * args)
{
	//pthread_detach(pthread_self());

	elem *p=(elem*)args;
	int *fd=p->fd;
	SA *paddr=p->paddr;
	int len=sizeof(SA);
	while(fgets(p->msg,128,stdin)!=NULL)
	{
		sendto(*fd,p->msg,128,0,(pSA)paddr,len);
	}
	close(*fd);
}
void * recv_handler(void * args)
{
	//pthread_detach(pthread_self());
	elem *p=(elem*)args;
	int *fd=p->fd;
	SA *paddr=p->paddr;
	int len=sizeof(SA);
	printf("in thread recv\n");
	pthread_t thd;
	pthread_create(&thd,NULL,send_handler,(void*)args);
	while(recvfrom(*fd,p->msg,128,0,(pSA)paddr,&len)>0)
	{
		if(p->usertype==ServerType)//server
		{
			p->func(p->msg);
			printf("from client:%s\n",p->msg);
			sendto(*fd,p->msg,128,0,(pSA)paddr,len);
		}
		else if(p->usertype==ClientType)
		{
			printf("from server:%s\n",p->msg);
		}
	}
	pthread_join(thd,NULL);
}
void MySocket(OUT int *ofd,IN int nettype,IN int usertype,IN int port,IN char *ip,void(*udpchat)(char*arry))
{
	int fd;
	pthread_t thd,thd1;
	char connectbuf[16];
	memset(connectbuf,0,16);
	int len=sizeof(SA);
	fd=socket(AF_INET,nettype,0);
	SA addr;
	addr.sin_family=AF_INET;	
	addr.sin_port=htons(port);
	addr.sin_addr.s_addr=inet_addr(ip);
	printf("connecting\n");
	if(usertype==ServerType && nettype==SOCK_STREAM)
	{
		SA clientaddr;
		bind(fd,(pSA)&addr,sizeof(SA));
		listen(fd,5);
		*ofd=accept(fd,(pSA)&clientaddr,&len);	
		printf("connected\n");
		return ;
	}
	if(usertype==ClientType && nettype==SOCK_STREAM)//no bind
	{
		*ofd=fd;
		connect(*ofd,(pSA)&addr,len);
		printf("connected\n");
		return ;
	}	
	if(usertype==ServerType && nettype==SOCK_DGRAM)//receive first
	{
		SA clientaddr;
		memset(&clientaddr,0,sizeof(SA));
		int len=sizeof(SA);
		*ofd=fd;
		if(bind(*ofd,(pSA)&addr,sizeof(SA))==-1)
		{
			perror("udp bind");
		}
		recvfrom(*ofd,connectbuf,16,0,(pSA)&clientaddr,&len);
		printf("connect condition:%s\n",connectbuf);
		char buf[128];
		memset(buf,0,128);
		elem Maddr={udpchat,buf,ServerType,&clientaddr,ofd};
		pthread_create(&thd1,NULL,recv_handler,(void*)&Maddr);
		pthread_join(thd1,NULL);
	}
	if(usertype==ClientType && nettype==SOCK_DGRAM)//send first
	{
		*ofd=fd;//without this huge mistake!!!!
		printf("in udp client\n");
		strcpy(connectbuf,"udp connected");
		char buf[128];
		memset(buf,0,128);
		sendto(*ofd,connectbuf,16,0,(pSA)&addr,sizeof(SA));
		elem Maddr={udpchat,buf,ClientType,&addr,ofd};
		pthread_create(&thd1,NULL,recv_handler,(void*)&Maddr);//没有前面的赋值服务器没收到
		pthread_join(thd1,NULL);
	}


