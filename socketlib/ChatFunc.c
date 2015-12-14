#include"MyNetOperation.h"
typedef struct Melem
{
	int *fd;
	void (*func)();
	char *msg;
	int *usertype;
}elem;
void * talkto(void * args)
{
	//pthread_detach(pthread_self());
	elem *p=(elem *)args;
	while(fgets(p->msg,128,stdin)!=NULL)
	{
		write(*(p->fd),p->msg,strlen(p->msg));
	}
}
void * receive(void * args)
{
	//pthread_detach(pthread_self());
	pthread_t thd1;
	pthread_create(&thd1,NULL,talkto,(void *)args);	
	printf("in receive thread\n");
	elem *p=(elem *)args;
	while(read(*(p->fd),p->msg,128)>0)
	{
		if(*(p->usertype)==ServerType)
		{
			printf("from client:%s\n",p->msg);	
			p->func(p->msg);
			write(*(p->fd),p->msg,strlen(p->msg));
		}
		else if(*(p->usertype)==ClientType)
		{
			printf("from server:%s\n",p->msg);	
		}
	}
	pthread_join(thd1,NULL);	
}
void Chat(OUT int *ofd,void (*func)(char *arry),int usertype)
{
	char msg[128];
	memset(msg,0,128);
	pthread_t thd;
	elem fd={ofd,func,msg,&usertype};
	pthread_create(&thd,NULL,receive,(void *)&fd);	
	pthread_join(thd,NULL);	
}
