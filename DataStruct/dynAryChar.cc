#define _DynAryChar

#ifndef _DynAry
#define _DynAryMain
#include "dynAry.cc"
#undef _DynAryMain
#endif

class DynAryChar : public DynAry{
public:
	DynAryChar(uint i)
		:DynAry(sizeof(char), i){
	}

	char* operator[] (uint i){
		return (char*)Ary::operator[](i);
	}

	char* getAd(){
		return (char*)Ary::getAd();
	}
};
