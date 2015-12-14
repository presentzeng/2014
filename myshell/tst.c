#include<stdio.h>
#include<string.h>
int main()
{
	char line[1024];
	int pos=0;
	char temp[32];
	memset(temp,0,32);
	memset(line,0,1024);
	fgets(line,1024,stdin);
	while(1)	
	{
		int judge=sscanf(line+pos,"%s",temp);
		pos=pos+strlen(temp)+1;
		printf("temp:%s\n",temp);	
		if(judge!=1)
			break;
		printf("judge:%d\n",judge);
	}
	printf("out \n");
}
