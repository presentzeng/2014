#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdint.h>
#include <map>
#include <set>

typedef int32_t i32;
typedef int32_t Status;
using namespace std;
int64_t GetTime();

Status main()
{
	int64_t start, end;
	start = GetTime();
	string word;

	map<string, int> words;
	set<pair<int, string> > Set;

	ifstream file("../cat");		
	while(file >> word)	
	{
		words[word]++;
	}
	string tempword;
	int tempint;
	for(map<string, int>::iterator it = words.begin();
	it != words.end();
	it ++)
	{
		Set.insert(make_pair(it->second, it->first) );	
	}	
	int index = 0;
	for(set<pair<int, string> >::reverse_iterator it =Set.rbegin();
	it !=Set.rend()& index < 10;
	it ++, index++)
	{
		cout << it->first << endl;
		cout << it->second <<endl;
	}
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
