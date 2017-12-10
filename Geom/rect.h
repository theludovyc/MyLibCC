#ifndef _Rect
#define _Rect

#include "tool.h"
#include "vec.h"
#include "areaR.h"

class Rect:public Vec, public AreaR{
public:
	Rect();

	Rect(uint posX, uint posY, uint i, uint j);

	//get Left
	uint getL();

	//get Right
	uint getR();

	//get Top
	uint getT();

	//get Bottom
	uint getB();
};

#endif
