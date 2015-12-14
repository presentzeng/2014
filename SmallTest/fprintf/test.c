#include <stdio.h>

int main()
{
	FILE * fp = fopen("you", "w+");	
	int a = 99;
	char * str = "never say never";
	fprintf(fp, "the one is %d and you \n is %s", a, str);
}
