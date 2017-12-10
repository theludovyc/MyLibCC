#ifndef _AreaR
#define _AreaR

#include "tool.h"

class AreaR{	
public:
	uint w;
	uint h;

	AreaR();
	
	AreaR(uint i, uint j);

	void setWH(uint i, uint j);
};

#endif
