#include "StringPiece.h"
using namespace std;
int main()
{
	StringPiece obj("hello");
	StringPiece obj2("he");
	/** compare **/
	int r = obj.compare(obj2);	
	//std::cout << "r: " << r << std::endl;

	/** operator [] **/
	char ch = obj[3];
	//std::cout << "char return " << ch << std::endl;

	/** remove prefix **/
	//cout << "length before :" << obj.length() << " " << obj[1] << endl;
	obj.remove_prefix(2);
	//cout << "length after:" << obj.length() << " " << obj[1] << endl;
	/** toString() **/
	string temp = obj.toString();
	//cout << temp;


	
}
