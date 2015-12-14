#ifndef _READ_
#define _READ_

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10
typedef struct
{
	int fd_;
	uint32_t cnt_;
	char *ptr_;
	char buffer_[SIZE];
} Readn_t;



void Init(Readn_t *, int);
int32_t Read(Readn_t *, char *, uint32_t );

#endif
