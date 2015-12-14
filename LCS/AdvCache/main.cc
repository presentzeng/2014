#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <string>

using namespace std;
//long common subsequence question

int cache[100][100];
int64_t GetTime()
{
	struct timeval tm;
	memset(&tm, 0, sizeof tm);
	if(gettimeofday(&tm, NULL) == -1)	
	{
		printf("error\n");
		exit(1);
	}
	int64_t t = 0;
	t += tm.tv_sec * 1000 * 1000;	
	t += tm.tv_usec;	
	return t;
}

int LSC(const string &a, const string &b, int memo[100][100])
{
	for(int i = 0; i <= a.size(); i++)
	{ memo[i][0] = 0;}

	for(int j = 0; j <= b.size(); j++)
	{ memo[0][j] = 0;}
	
	for(int i = 1; i <= a.size(); ++i)
	{
		for(int j = 1; j <= b.size(); ++j)	
		{
			if(a[i-1] == b[j-1])
				memo[i][j] = memo[i-1][j-1] + 1;
			else
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
		}
	}
	return memo[a.size()][b.size()];
}

int main()
{
	int64_t start = GetTime();
	string s1 = "abcdefghijklmn";	
	string s2 = "acdehln";	
	cout << LSC(s1, s2, cache) << endl;
	int64_t end= GetTime();
	cout <<  end - start << endl;
}

