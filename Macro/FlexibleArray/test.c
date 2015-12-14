#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct person
{
	char name_[20];
	char info_[0];
}person;

int Alloc_Info(person **p, int length, char const * name)
{
	*p = (person*)malloc(sizeof(struct person) + length);
	if(NULL == *p)//incase you write p = NULL
	{
		return -1;
	}
	if(strlen(name) < 20)
	{
		strcpy((*p)->name_, name);
		(*p) -> name_[strlen((*p)->name_) + 1] = '\0';	
	}
	
	//memset((*p)->info_, 0, length);			
	strncpy((*p)->info_, "hello", 5);
	return 0;
}

int main()
{
	person *pTom;	
	Alloc_Info(&pTom, 9, "nothing");
	printf("name: %s\n", pTom->name_);	
	printf("info: %s\n", pTom->info_);	
}

