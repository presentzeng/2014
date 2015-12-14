#include <iostream>

using namespace std;
class father
{
private:
	int id_;
public:
	father(){ cout << "fa con\n";}
	~father(){ cout << "~fa\n"; }
};
class leg
{
public:
	leg() {cout << "leg\n";}
	~leg() {cout << "~leg\n";}
};
class son :public father
{
public:
	son(){ cout << "son\n";}
	~son() {cout << "~son\n";}
private:
	leg lge_;
};

int main()
{
	son onj;
}
