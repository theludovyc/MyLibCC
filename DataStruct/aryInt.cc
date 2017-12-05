#define _AryInt

#ifndef _Ary
#define _Main
#include "ary.cc"
#undef _Main
#endif

class AryInt:public Ary{
public:
	AryInt(unsigned int i)
		:Ary(sizeof(int), i){
	}

	int* operator[] (unsigned int i){
		return (int*)Ary::operator[](i);
	}
};
