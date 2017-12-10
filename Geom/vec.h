#define _Vec

#ifndef _Tool
#include "tool.h"
#endif

class Vec{
public:
	uint x;
	uint y;

	Vec();

	Vec(uint posX, uint posY);

	void setXY(uint posX, uint posY);

	void setXY(Vec v);
	
	void operator= (Vec v);

	void addXY(uint posX, uint posY);

	void addXY(Vec v);

	void operator+= (Vec v);

	Vec operator+ (Vec v);

	bool operator== (Vec v);
};
