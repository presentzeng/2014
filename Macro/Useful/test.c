/** show the common method **/
//fill in struct
enum IDD{OPEN, CLOSE};
typedef struct MSG
{
	IDD id;
	const char * msg;
}MSG;
#define FILL(a) {a, #a}

int main()
{
	MSG msg[] = 
	{FILL(OPEN), FILL(CLOSE)};
}

