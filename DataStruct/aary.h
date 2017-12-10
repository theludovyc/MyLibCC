#ifndef _AAry
#define _AAry

#include "ary.h"

class AAry:public Ary{
protected:
	unsigned short lengthX;
	unsigned short lengthY;

public:
	AAry(size_t s, unsigned short i, unsigned short j);

	void* operator() (unsigned short i, unsigned short j);
};
	
#endif
