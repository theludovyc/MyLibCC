#define _DynAryUchar

#ifndef _DynAry
#define _DynAryMain
#include "dynAry.cc"
#undef _DynAryMain
#endif

class DynAryUchar : public DynAry{
public:
	DynAryUchar(uint i)
		:DynAry(sizeof(char), i){
	}

	uchar* operator[] (uint i){
		return (uchar*)Ary::operator[](i);
	}

	uchar* getAd(){
		return (uchar*)Ary::getAd();
	}
};
