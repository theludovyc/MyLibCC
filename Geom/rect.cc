#include "rect.h"

Rect::Rect()
	:Vec(), AreaR(){
}

Rect::Rect(uint posX, uint posY, uint i, uint j)
	:Vec(posX, posY), AreaR(i, j){
}

uint Rect::getL(){
	return x;
}

uint Rect::getR(){
	return x+w;
}

uint Rect::getT(){
	return y;
}

uint Rect::getB(){
	return y+h;
}
