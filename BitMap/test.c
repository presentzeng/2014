<<<<<<< HEAD
#include <stdio.h>
#include <inttypes.h>

int clear ()//reset 
{
}

int main()
{
	uint8_t unit = 0xf0;
	//int8_t unit = 0xf0;
	int a = unit;
	printf("without symbol:%u\n",unit);	
	printf("with symbol:%d\n",unit);	
	printf("hexadecimal:%x\n",unit);
	printf("int:%d\n",a);	
}
=======
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>



typedef uint32_t uint32;
using namespace std;

void BinarySearch(uint32 * arr, uint32 len, uint32 pattern)
{
        uint32 top, end;
        top = 0;
        end = len;
        uint32 middle;
        while(top < end)
        {
                middle = (top + end )/2;
                if(arr[middle] >pattern)
                {
                        cout << "middle > pattern" << endl;
                        cout << "middle" << middle << endl;
                        cout << "arr" << arr[middle] << endl;
                        end = middle -1 ;
                }
                else if(arr[middle] <pattern )
                {
                        cout << "middle < pattern" << endl;
                        cout << "middle" << middle << endl;
                        cout << "arr" << arr[middle] << endl;
                        top = middle +1 ;
                }
                else
                {
                        cout << "match " << endl;
                        cout << middle << endl;
                        return ;
                }
                sleep(2);
        }
        cout << "no match " << endl;
        cout << "middle < pattern" << endl;
        cout << "middle" << middle << endl;
}
void Clear(uint32 * bitmap, uint32 num)//32 bit
{
        uint32 offset = num & 0x1f;
        uint32 arr = num >> 5;
        uint32 bitpos = ~(1 << offset);
        bitmap[arr]  = bitpos & bitmap[arr];
}
int IsRecord (uint32 *bitmap, uint32 num)//is num recorded
{
        uint32 offset = num & 0x1f;
        uint32 arr = num >> 5;
        uint32 find= 1 << offset;

        if((find & bitmap[arr]) != 0)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}
void Record (uint32 *bitmap, uint32 num)
{
        uint32 offset = num & 0x1f;
        uint32 arr = num >> 5;
        uint32 find= 1 << offset;

        bitmap[arr] = find | bitmap[arr];
}
void Init(FILE * fp, uint32 * bitmap)
{
        fp = fopen("Pattern.txt","r");
        if(fp == NULL)
        {
                cout << "fail to open init file" << endl;
        }
        uint32 temp;
        while(fscanf(fp, "%u", &temp)!=EOF)
        {
                Clear(bitmap, temp);
                Record(bitmap, temp);
        }
}
int main()
{

        uint32 bitmap[322];
        memset(bitmap, 0, 322*(double)sizeof(uint32)/sizeof(size_t));
        FILE * FpDest, *FpPattern;
        FpDest = fopen("Dest.txt","r");
        if(FpDest == NULL)
        {
                cout << "fail to open Dest" << endl;
        }
        Init( FpPattern,  bitmap);

        uint32 temp;
        while(fscanf(FpDest, "%u", &temp)!=EOF)
        {
                if(temp > 10000)
                        continue;
                if(IsRecord(bitmap, temp))
                        cout << "temp" << temp << endl;
        }
        /** followed by a compared algorithm binary search**/
        uint32 a[10]={1,4,6,7,9,20,23,25,30,43};
        BinarySearch(a, 10, 20);
}
   
>>>>>>> fbff6cd56208166e4a681c093441e76e71f49c9a
