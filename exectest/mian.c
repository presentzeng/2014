#include<unistd.h>
int main(int argc,char * argv[])
{	char * args[10] ;
	args[0] = "my_arg" ;
	args[1] = "hello" ;
	args[2] = "world" ;
	args[3] = "how" ;
	printf("argv:%s",args);
	execv ("add",args+1);	
}
