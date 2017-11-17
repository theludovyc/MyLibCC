#define _AreaR

#ifndef _Tool
#include "../Tool.cc"
#endif

class AreaR{	
public:
	uint w;
	uint h;

	AreaR(){
		w=0;
		h=0;
	}
	
	AreaR(uint i, uint j){
		w=i;
		h=j;
	}

	void setWH(uint i, uint j){
		w=i;
		h=i;
	}
};