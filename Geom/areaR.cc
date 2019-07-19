#include "areaR.h"

AreaR::AreaR(){
	w=0;
	h=0;
}
	
AreaR::AreaR(uint i, uint j){
	w=i;
	h=j;
}

void AreaR::setWH(uint i, uint j){
	w=i;
	h=i;
}
