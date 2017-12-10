#include "dynAryChar.h"

DynAryChar::DynAryChar(uint i)
	:DynAry(sizeof(char), i){
}

char* DynAryChar::operator[] (uint i){
	return (char*)Ary::operator[](i);
}

char* DynAryChar::getAd(){
	return (char*)Ary::getAd();
}
