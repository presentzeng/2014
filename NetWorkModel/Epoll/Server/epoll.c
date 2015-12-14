#include "epoll.h"
#include "tcp.h"

static void epoll_add_fd(epoll_t *et, int fd);
static void epoll_del_fd(epoll_t*, int);

void epoll_init(epoll_t *et, int listenfd, CallBack_t callback)
{
	et->epoll_fd_ = epoll_create(SIZE);
	if(et->epoll_fd_ == -1)
		ERR_EXIT("epoll_create");
	
	et->listenfd_ = listenfd;	
	memset(&et->events_, 0, sizeof(et->events_));
	et->callback_ = callback;
	
	epoll_add_fd(et, listenfd);
}

void epoll_loop(epoll_t *et)
{
	int nready;
	do
	{
		nready = epoll_wait(et->epoll_fd_, et->events_, sizeof(et->events_), 5000);
		//if success return 1
	}while(nready == -1 && errno == EINTR);

	if(nready == -1)	
		ERR_EXIT("epoll wait");
	else if(nready == 0)
		et->nready_ = 0;
	else
		et->nready_ = nready;
}

void epoll_handle_fd(epoll_t *et)
{
	int i;
	for(i = 0; i < et->nready_; ++i)
	{
		int fd = et->events_[i].data.fd;
		if(fd == et->listenfd_)//listen	//mistake for fd == et->events_[i].data.fd
		{
			if(et->events_[i].events & EPOLLIN)
			{
				int peerfd = accept(et->listenfd_, NULL, NULL);
				if(peerfd == -1)
					ERR_EXIT("accept");

				epoll_add_fd(et, peerfd);
				printf("connected");
				printf("%s \n", GetTcpInfor(peerfd));
			}
		}
		else//client fd
		{
			if(et->events_[i].events & EPOLLIN)
			{
				char recvbuf[1024] = "";
				uint32_t  nread = Recv(fd, recvbuf, sizeof recvbuf);//read
				if(nread == 0)	
				{
					epoll_del_fd(et, fd);
					close(fd);
					continue;
				}
				printf("Recv:%s\n", recvbuf);
				et->callback_(fd, recvbuf, sizeof recvbuf);
				memset(recvbuf, 0, sizeof recvbuf);
			}
		}
	}
}
static void epoll_del_fd(epoll_t *et, int fd)
{
	struct epoll_event ev;	
	ev.data.fd = fd;
	if(epoll_ctl(et->epoll_fd_, EPOLL_CTL_DEL, fd, &ev) == -1)
		ERR_EXIT("epoll del fd");
}
static void epoll_add_fd(epoll_t *et, int fd)	
{
	struct epoll_event ev;	
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	if(epoll_ctl(et->epoll_fd_, EPOLL_CTL_ADD, fd, &ev) == -1)	
		ERR_EXIT("epoll add fd");	

}
