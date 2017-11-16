#define _Vec

#ifndef _Tool
#include "../Tool.cc"
#endif

class Vec{
protected:
	uint x;
	uint y;

public:
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

	uint getX(){
		return x;
	}

	uint getY(){
		return y;
	}

	void setX(uint posX){
		x=posX;
	}

	void setY(uint posY){
		y=posY;
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

	void addX(uint posX){
		x+=posX;
	}

	void addY(uint posY){
		y+=posY;
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
