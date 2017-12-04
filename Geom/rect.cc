#define _Rect

#ifndef _Tool
#include "../tool.cc"
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

	//get Left
	uint getL(){
		return x;
	}

	//get Right
	uint getR(){
		return x+w;
	}

	//get Top
	uint getT(){
		return y;
	}

	//get Bottom
	uint getB(){
		return y+h;
	}
};

#ifndef _RectMain
	int main(){
		Rect *r=new Rect();

		printf("%d\n", (*r).getL());

		return 0;
	}
#endif
