#define _Rect

#ifndef _Tool
#include "../Tool.cc"
#endif

#ifndef _Vec
#include "vec.cc"
#endif

#ifndef _AreaR
#include "areaR.cc"
#endif

class Rect:public Vec, public AreaR{
public:
	Rect()
	:Vec(), AreaR(){
	}

	Rect(uint posX, uint posY, uint i, uint j)
	:Vec(posX, posY), AreaR(i, j){
	}

	uint getL(){
		return getX();
	}

	uint getR(){
		return getX()+getW();
	}

	uint getT(){
		return getY();
	}

	uint getB(){
		return getY()+getH();
	}
};

#ifndef _Main
	int main(){
		Rect *r=new Rect();

		printf("%d\n", (*r).getL());

		return 0;
	}
#endif