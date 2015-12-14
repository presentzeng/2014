#define likely(x) __builtin_expect(!!x, 1)

int main()
{
	int a = 1;
	if(likely(a == 1))
	{
		//equals if(a == 1) 
	}
}
