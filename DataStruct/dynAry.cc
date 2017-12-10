#include "dynAry.h"

DynAry::DynAry(size_t s, uint i)
	:Ary(s, i){
}

void DynAry::resize(uint i){
	void *tmp=realloc(ad, sizeEl*i);
	if(tmp==NULL){
		Tool_error1MemoryReallocation("DynAry::Resize(...)");
	}
	length=i;
	ad=tmp;
}

void DynAry::resize_add(uint i){
	resize(length+i);
}

void DynAry::resize_mul(uint i){
	resize(length*i);
}
