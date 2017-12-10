#include "ary.h"

Ary::Ary(size_t s, unsigned int i){
	sizeEl=s;
	length=i;
	ad=calloc(i, s);
	if(ad==NULL){
		Tool_error1MemoryAllocation("Ary::Ary(unsigned int, size_t)");
	}
}

Ary::~Ary(){
	free(ad);
}

void* Ary::operator[] (unsigned int i){
	if(i<length){
		return ad+sizeEl*i;
	}
	Tool_error1OutOfLength("Ary::operator[](unsigned int)");
	return NULL;
}

void* Ary::getAd(){
	return ad;
}

unsigned int Ary::getLength(){
	return length;
}

size_t Ary::getElSize(){
	return sizeEl;
}
