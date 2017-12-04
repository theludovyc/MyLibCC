#define _Vec

#ifndef _Tool
#include "../tool.cc"
#endif

class Vec{
public:
	uint x;
	uint y;

	Vec(){
		x=0;
		y=0;
	}

	Vec(uint posX, uint posY){
		x=posX;
		y=posY;
	}

	~Vec(){
	}

	void setXY(uint posX, uint posY){
		x=posX;
		y=posY;
	}

	void setXY(Vec v){
		x=v.x;
		y=v.y;
	}

	void operator= (Vec v){
		x=v.x;
		y=v.y;
	}

	void addXY(uint posX, uint posY){
		x+=posX;
		y+=posY;
	}

	void addXY(Vec v){
		x+=v.x;
		y+=v.y;
	}

	void operator+= (Vec v){
		x+=v.x;
		y+=v.y;
	}

	Vec operator+ (Vec v){
		return Vec(x+v.x, y+v.y);
	}

	uchar operator== (Vec v){
		if(x==v.x && y==v.y){
			return 1;
		}
		return 0;
	}
};
