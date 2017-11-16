#define _AreaR

#ifndef _Tool
#include "../Tool.cc"
#endif

class AreaR{
protected:
	uint w;
	uint h;

public:
	AreaR(){
		w=0;
		h=0;
	}
	
	AreaR(uint i, uint j){
		w=i;
		h=j;
	}

	uint getW(){
		return w;
	}

	uint getH(){
		return h;
	}

	void setW(uint i){
		w=i;
	}

	void setH(uint i){
		h=i;
	}

	void setWH(uint i, uint j){
		w=i;
		h=i;
	}
};