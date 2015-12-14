#ifndef _EPOLL_
#define _EPOLL_

#include <sys/epoll.h>
#include <stdint.h>
#define SIZE 2048

//typedef void (*CallBack_t)(const char*, uint32_t cnt, int fd);
typedef void (*CallBack_t)(int, const char*, int);

typedef struct 
{
	int epoll_fd_;//for normal fd
	int listenfd_;//for listen fd
	struct epoll_event events_[SIZE];
	int nready_;//
	CallBack_t callback_;//callback function
} epoll_t;

void epoll_init(epoll_t *, int, CallBack_t);
void epoll_loop(epoll_t *);
void epoll_handle_fd(epoll_t *);

#endif
