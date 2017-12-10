#ifndef _DynAryChar
#define _DynAryChar

#include "dynAry.h"

class DynAryChar : public DynAry{
public:
	DynAryChar(uint i);

	char* operator[] (uint i);

	char* getAd();
};

#endif
