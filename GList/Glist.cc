#include<iostream>
using namespace std;
typedef enum {ATOM, LIST}ElemTag;

typedef struct GLNode
{
	int tag;
	union 
	{
		char atom;
		struct GLNode * hp;
	};
	struct GLNode *next;
}GList;

int main()
{
	
}
