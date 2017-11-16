#define _AreaSquare

#ifndef _Tool
#include "../Tool.cc"
#endif

class AreaSquare{
protected:
	uint w;

public:
	AreaS(){
		w=0;
	}

	AreaS(uint i){
		w=i;
	}

	uint getW(){
		return w;
	}

	uint getH(){
		return w;
	}

	void setW(uint i){
		w=i;
	}

	void setH(uint i){
		w=i;
	}
};