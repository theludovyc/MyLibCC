#ifndef _AreaS
#define _AreaS

#include "tool.h"

class AreaS{
protected:
	uint w;

public:
	AreaS();

	AreaS(uint i);

	uint getW();

	uint getH();

	void setW(uint i);

	void setH(uint i);
};

#endif
