#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include<pwd.h>
int main(int argc , char * argv[])
{
	int pos=0;
	int cnt=0;
	char line[1024];
	char * args[32];
	char temp[32];	
	memset(line,0,1024);
	while(printf("[%s@",getpwuid(getuid())->pw_name),fgets(line,1024,stdin)!=1)
	{
		if(fork()==0)	
		{
			if(line[0]=='\n')//when to exit
			{
				return 0;
			}

			while(1)
			{
				memset(temp,0,32);	
				int judge=sscanf(line+pos,"%s",temp);
				//	printf("judge:%d\n",judge);	
				//	printf("temp:%s\n",temp);
				pos=pos+strlen(temp)+1;	
				if(judge!=1)
				{
					break;
				}
				args[cnt]=(char*)calloc(strlen(temp)+1,1);
				strcpy(args[cnt++],temp);
			}
			args[cnt]=NULL;
			execvp(args[0],args);
			exit(23);
		}
		else
		{

			int ret; 
			wait(&ret);
		}

	}//while
	return 0;
}
