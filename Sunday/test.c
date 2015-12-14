#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool Init(const char * Pattern, int len, int *SearchArry)
{
	int index;
	for(index=0;index<256;index++)
	{
		SearchArry[index]=-1;//	
	}
	for(index=0;index<len;index++)
	{
		SearchArry[Pattern[index]]=index;	
	}
}
int SundaySearch(const char *Pattern, int Plen, const char *Dest, int Dlen, int *SearchArry)
{
	if(Dlen==0 || Plen==0)	
	{
		return -1;
	}
	int nBegin;
	for(nBegin=0;nBegin<=Dlen-Plen;)
	{
		static int record;
		int i=nBegin,j=0;//i for dest
		for(;j<Plen && i<Dlen && Dest[i]==Pattern[j];i++,j++);
		if(j==Plen)
		{
			record += nBegin;
			printf("here\n");
			printf("pos:%d\t string:%s\n", record, &Dest[nBegin]);
			record++;
			SundaySearch(Pattern, Plen , &Dest[nBegin+1], Dlen -nBegin, SearchArry);
			return 0;
		}
		if(nBegin+Plen>Dlen)
			return -1;
		else
			nBegin+=Plen-SearchArry[Dest[nBegin+Plen]];
	}
	return -1;
}
int main()
{
	char Pattern[]="well";
	char Dest[]="hellowellwellyouknowgoodwell";
	int SearchArry[256]; 
	memset(SearchArry, 0, sizeof(int)*256);

	int Plen=strlen(Pattern);
	int Dlen=strlen(Dest);

	Init(Pattern, Plen, SearchArry);	// 	
	printf("Patter:%s\n",Pattern);	
	printf("Dest:%s\n",Dest);
	SundaySearch(Pattern, Plen, Dest, Dlen, SearchArry);
}
