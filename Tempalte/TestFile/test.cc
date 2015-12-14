#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <stdint.h>

using namespace std;

template<typename T, typename T2> 
T & p(T &s, T2 val)
{
	s << val;
	return s;
}


int main()
{
	double cval = 0.99;
	float fval = -12.3;
	string oval = "this is a test";
	ofstream ourfile("result.dat");


	//to cout
	p(cout, -3) <<endl;
	p(cout, cval) <<endl;
	p(cout, fval) <<endl;
	p(cout, oval) <<endl;

	//to file
	p(ourfile, -3) <<endl;
	p(ourfile, cval) <<endl;
	p(ourfile, fval) <<endl;
	p(ourfile, oval) <<endl;

	// to stringstream
	ostringstream oss(temp);
	p(temp, -3) <<endl;
	p(temp, cval) <<endl;
	p(temp, fval) <<endl;
	p(temp, oval) <<endl;
	
}




