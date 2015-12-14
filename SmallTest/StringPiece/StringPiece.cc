#include "StringPiece.h"


int StringPiece::compare(const StringPiece & obj) const
{
	int r = memcmp(ptr_, obj.ptr_, std::min(obj.length_, length_));
	if(r == 0)	
	{
		if(length_ > obj.length_)
			return 1;
		else if(length_ < obj.length_)
			return 1;
	}
	return r;
}
