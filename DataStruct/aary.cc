#include "aary.h"

AAry::AAry(size_t s, unsigned short i, unsigned short j)
	:Ary(s, i*j){
	lengthX=i;
	lengthY=j;
}

void* AAry::operator() (unsigned short i, unsigned short j){
	if(i<lengthX && j<lengthY){
		return ad+sizeEl*(j*lengthX+i);
	}
	Tool_error1OutOfLength("AAry::operator()(unsigned int, unsigned int)");
	return NULL;
}
