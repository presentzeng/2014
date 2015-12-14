#include "Readn.h"


void Init(Readn_t *rp, int fd)
{
	rp->fd_ = fd;
	rp->cnt_ = 0;
	rp->ptr_ = rp->buffer_;
	memset(rp->buffer_, 0, SIZE);
}


int32_t Read(Readn_t *rp, char *buf, uint32_t n)
{
	while(rp->cnt_ <= 0)
	{
		int32_t nread = read(rp->fd_, rp->buffer_, SIZE);
		if(nread == -1)
		{
			return -1;	
		}
		else if(nread ==0 )
			return 0;

		rp->cnt_ = nread;//buf size
		rp->ptr_ = rp->buffer_;	
	}
	uint32_t cnt = (rp->cnt_ < n)?rp->cnt_ : n;
	memcpy(buf, rp->ptr_, cnt);
	rp->ptr_ += cnt;	
	rp->cnt_ -= cnt;
	
	return cnt;
}
