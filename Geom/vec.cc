#include "vec.h"

Vec::Vec(){
	x=0;
	y=0;
}

Vec::Vec(uint posX, uint posY){
	x=posX;
	y=posY;
}

void Vec::setXY(uint posX, uint posY){
	x=posX;
	y=posY;
}

void Vec::setXY(Vec v){
	x=v.x;
	y=v.y;
}

void Vec::operator= (Vec v){
	x=v.x;
	y=v.y;
}

void Vec::addXY(uint posX, uint posY){
	x+=posX;
	y+=posY;
}

void Vec::addXY(Vec v){
	x+=v.x;
	y+=v.y;
}

void Vec::operator+= (Vec v){
	x+=v.x;
	y+=v.y;
}

Vec Vec::operator+ (Vec v){
	return Vec(x+v.x, y+v.y);
}

bool Vec::operator== (Vec v){
	if(x==v.x && y==v.y){
		return true;
	}
	return false;
}
