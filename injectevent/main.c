
#define  LOG_TAG    "inject_event_main"
#include "uinput.h"
#include <semaphore.h>

#define CHECK_INTERVAL_US  300000
#define SEM_NAME       "IndectEvent_sem"

static sem_t s_sem;
static pthread_t s_thread_id = -1;
static int s_cur_state = S_IDLE;
static int fd;
pthread_mutex_t * mutex;

void deInit();
int Init(char * );
int CheckFlag();

int main(int argc, char * argv[])
{
	if(argc != 2)	
	{
		Note("add parameter 1 or 2\n");
		exit(1);
	}
	signal(SIGHUP, deInit);
	//check if already has one process
	int ret = CheckFlag();
	if(-1 == ret)
	{
		Note("already has injectevent process on, i commit suicide you can try :echo 0 > /data/injectevent/flag \n");
		exit(1);
	}
	//init
	ret = Init(argv[1]);
	if(-1 == ret)	
	{	
		Note("1 for record, 2 for replay, 0 can stop the process\n");
		deInit();
		exit(1);
	}
	
	int fk = fork();	
	if(-1 == fk)
		LOGE("injectevent fork failed");
	else if(0 == fk)	
	{
		while(1)
		{
			switch(ret)
			{
				case 1:	//record
					start_record();	
					//Note("record\n");
					break;
				case 2: //replay
					//;Note("replay\n");
					start_replay();
					break;
				case 3:
					start_record2();
					break;
				case 4:
					start_replay2();
					break;
			}
		}
	}
	else  	//wait for stdin 0 for kill
	{
		while(1)
		{
			Note("input 0 can stop the process\n");
			char buf[256] = {0};
			read(STDIN, buf, 3);
			if(0 == strncmp(buf, "0", 1))
			{
				kill(fk, 9);	
				deInit();		
			}
		}
	}
	return 1;
	
}//main



/* check if already has injectevent process running
by check flag file if file not exists, it will create one 
return 0 is ok other is fail*/
int CheckFlag()
{
	
	LOGI("Check if already has injectevent process");		
	fd = open(BASE_DIR"/flag", O_RDWR);	
	if(fd < 0)
	{	//file not exists yet
		if(2 == errno)
		{
			Note("you see this information cuz it is the first time you run injectevent \n");
			//mkdir doc and flag
			system("mkdir "BASE_DIR" > /dev/null");
			system("touch "BASE_DIR"/flag");
			system("echo 1 > "BASE_DIR"/flag");
			return 0;
		}
		else
		{
			LOGE("open "BASE_DIR"/flag fail errno:%d", errno);
			exit(1);
		}
	}
	/*lock file before writing*/
	//if(lockf(fd, F_TEST, 0) < 0);
	//{
	//	if(11 == errno)	
	//		return -1;
	//}
	char flag[4] = {0};		
	int ret = read(fd, flag, 4);	
	if(0 == strncmp(flag, "0", 1))	//no process running yet
	{
		if(lseek(fd, 0, SEEK_SET) == -1)
		{ LOGE("injectevent lseek error\n"); }
		if(write(fd, "1", 2) > 0)//mark flat as 1
		{	//unlock file
			//if(lockf(fd, F_ULOCK, 0) < 0)
			//{	
			//	LOGE("unsuccessful to unlock flag file\n");	
			//}
			close(fd);
			return 0;
		}
		else
		{
			Note("process is running but flag remains 0 errno is %d\n", errno);
			system("echo 0 > /data/injectevent/flag");
			return 0;
		}
	}
	else
		return -1;
}



/*deal with argv[], if it is 1 then record, if it is 2
then replay*/
int Init(char * para)
{
	if(strlen(para) != 1)
		return -1;
	if(0 == strncmp(para, "1", 1))
	{
		
		return 1;
	}
	else if(0 == strncmp(para, "2", 1))
	{
		return 2;
	}
	else if(0 == strncmp(para, "3", 1))
	{
		return 3;
	}
	else if(0 == strncmp(para, "4", 1))
	{
		return 4;
	}
	else 
		return -1;
}

/*change flag to zero*/
void deInit()
{
	Note("injectevent ends\n");
	fd = open(BASE_DIR"/flag", O_RDWR);	
	if(-1 == fd)	
	{
		LOGE("in deInit() open fail errno:%d\n", errno);
		close(fd);	
	}
	if(lseek(fd, 0, SEEK_SET) == -1)
	{ LOGE("injectevent lseek error\n"); }
	int ret = write(fd, "0", 1);
	if(-1 == ret)	
	{
		Note("write 0 to flag failed\n");
		close(fd);	
	}
	close(fd);	
	exit(1);
}


int empty_key(struct input_event *event)
{
    //return (event->type == 0 && event->code == 0 && event->value == 0);
    return (event->type == 0);
}
