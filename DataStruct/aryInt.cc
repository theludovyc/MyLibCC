#include "aryInt.h"

AryInt::AryInt(unsigned int i)
	:Ary(sizeof(int), i){
}

int* AryInt::operator[] (unsigned int i){
	return (int*)Ary::operator[](i);
}
