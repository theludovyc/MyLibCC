#ifndef _AryInt
#define _AryInt

#include "ary.h"

class AryInt:public Ary{
public:
	AryInt(unsigned int i);

	int* operator[] (unsigned int i);
};

#endif
