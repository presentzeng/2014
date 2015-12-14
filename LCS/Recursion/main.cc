#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <string>

using namespace std;
//long common subsequence question


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

int LSC(const string &a, const string &b,
	int i, int j)
{
	if(i == 0 || j == 0)
		return 0;

	if(a[i-1] == b[j-1])
	{
		return LSC(a, b, i-1, j-1) + 1;
	}
	else
	{
		int t1 = LSC(a, b, i-1, j);
		int t2 = LSC(a, b, i, j-1);
		
		return  t1 > t2 ? t1 : t2;
	}
}

int main()
{
	int64_t start = GetTime();
	string s1 = "abcdefghijklmn";	
	string s2 = "acdehln";	
	cout << LSC(s1, s2, s1.size(), s2.size()) << endl;
	int64_t end= GetTime();
	cout <<  end - start << endl;
}

