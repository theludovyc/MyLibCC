#ifndef _DynAry
#define _DynAry

#include "ary.h"

class DynAry: public Ary{
public:
	DynAry(size_t s, uint i);

	void resize(uint i);

	void resize_add(uint i);

	void resize_mul(uint i);
};

#endif
