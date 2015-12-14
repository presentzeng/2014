#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdint.h>

typedef int32_t i32;
typedef int32_t Status;
using namespace std;
typedef struct Node
{
	int32_t WordNum;
	string Word;
} *pNode;
typedef struct vertex
{
	i32 WordNum;
	i32 PreNum;
	i32 flag;//0 for no 1 for yes
	string Word;
	struct vertex * son[26];
} *pVertex;

int64_t GetTime();
void Initial(pVertex &Tree);
Status AddWord(pVertex &Tree, string & word);//AddWord into tries
Status AddWord1(pVertex &Tree, string & word);//AddWord into tries
Status PrintWords(pVertex &Tree);
Status Top(pNode  List, pVertex &Tree, int32_t len);
void InsertTop(pNode List, int32_t wordnum, string word, int32_t len);
void Init(pNode List, int len);// set zero
void ShowList(pNode List);//show list

Status main()
{
	int64_t start, end;
	start = GetTime();
	pVertex Tree;
	Initial(Tree);
	string s = "                          ";
	ifstream file("../cat");
	while(file >> s)
		AddWord(Tree, s);

	Node List[10];
	Init(List, 10);// set zero
	Top(List, Tree, 10);
	ShowList(List);
	end = GetTime();
	cout << "cost " << end - start << endl;
}

int64_t GetTime()
{
	struct timeval tm;	
	memset(&tm, 0, sizeof tm);
	if(gettimeofday(&tm, NULL) == -1)
	{
		perror("gettimeofday");
		exit(-1);
	}
	int64_t t = 0;	
	t += tm.tv_sec * 1000 * 1000;
	t += tm.tv_usec;
	return t;
}
void ShowList(pNode List)
{
	cout << "show List" << endl;
	int index;
	for(index = 0;index < 10; index++)
	{
		if(List[index].WordNum == 0)
			break;

		cout <<"List WordNum : " << List[index].WordNum <<  endl;
		cout << "List Word :" <<List[index].Word <<  endl;
	}
}
void Init(pNode List, int len)// set zero
{
	int index;
	for(index = 0; index < len; index++)
	{
		List[index].WordNum = 0;
		List[index].Word = "";
	}
}
void InsertTop(pNode List, int32_t wordnum, string word, int32_t len)
{
	//cout << "In word num "<< wordnum << endl; 
	//cout << "In word "<< word << endl; 
	//cout << "ListWordNum "<< List[len-1].WordNum << endl;

	if(wordnum <= List[len-1].WordNum)//if smaller than the smallest
		return ;

	int index = len - 1;
	while(index >= 0)
	{
		if(wordnum > List[index].WordNum)
			index --;
		else
			break;
	}

	List[index+1].WordNum = wordnum;
	List[index+1].Word = word;

}
Status Top(pNode  List, pVertex &Tree, int32_t len)
{
        int index;
        for(index =0; index < 26; index ++)
        {
                if(Tree->son[index] != NULL)
                {
                        if(Tree->son[index]->flag == 1)
                        {
                        //cout << "Tree->son->word :" << Tree->son[index]->Word << endl;
                        //cout << "Tree->son[index]:" << index << endl;
                                InsertTop(List,
                                Tree->son[index]->WordNum,
                                Tree->son[index]->Word,
                                len);
                        }
                                Top(List, Tree->son[index], len);
                }
        }
}
Status AddWord(pVertex &Tree, string & word)
{
        static string temp = word;
        static int flag = 1;
        if(flag == 1)
        {
                temp = word;
                flag = 0;
        }
        //cout << "word in add word" << temp <<endl;
        if(word.size() == 0)
        {
                //cout << "about to cout static word" << temp<< endl;   
                //cout << "static word" << temp<< endl; 
                Tree->flag = 1;
                Tree->Word = temp;
                Tree->WordNum++;
                flag = 1;
                return 1;
        }
        i32 k = word[0] - 'a';//calculate k
        //cout << "the ch is " << word[0] << endl;      
        //cout << "it is record is:"<< k  << endl; 
        if(Tree->son[k] == NULL)//son[k] not exists             
        {
                Initial(Tree->son[k]);
                Tree->son[k]->Word = word[0];//record each character
                Tree->PreNum ++;
                //cout << "Print ch in Initial son:"<< word[0] << endl; 
                //cout << "before cut the word is" << word << endl;
                word.erase(0,1);//cut leftmost  
                //cout << "after cut the word is" << word << endl;
                AddWord(Tree->son[k], word);
        }
        else
        {
                Tree->son[k]->PreNum ++;
                word.erase(0,1);//cut leftmost  
                AddWord(Tree->son[k], word);
        }
}

void Initial(pVertex &Tree)
{
        //Tree->Word = "";      
        Tree = new vertex;
        Tree->flag = 0;//pre
        Tree->WordNum = 0;
        Tree->PreNum = 0;
        int index;
        for(index = 0; index < 26; index++)
        {
                Tree->son[index]=NULL;
        }
}


Status PrintWords(pVertex &Tree)
{

        int index;
        for(index =0; index < 26; index ++)
        {
                if(Tree->son[index] != NULL)
                {
                        //cout << "index :" << index << endl; 
                        //cout << "mark"  << endl;
                        //cout << "Tree->son->word :" << Tree->son[index]->Word << endl;
                        //cout << "Tree->son[index]:" << index << endl;
                        if(Tree->son[index]->flag == 1)
                        {
                                cout << "Word:" << Tree->son[index]->Word << endl;
                                cout << "Word Num" << Tree -> son[index]->WordNum << endl;
                                //return 1;// bug here
                        }
                        PrintWords(Tree->son[index]);
                }
        }
}

