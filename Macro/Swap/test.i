# 1 "test.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "test.c"



int x = 10;
int y = 5;
int z = 4;


if(x < 0)
    { x ^= y; y ^= x; x ^= y; }
else
    { x ^= z; z ^= x; x ^= z; }

int main()
{
}
