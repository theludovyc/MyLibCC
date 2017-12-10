#include "gListChars.h"

GListFrameChars::GListFrameChars(uint i)
	:GListFrame(), DynAryChar(i){
}
	
GListChars::GListChars()
	:GList(){
}

void GListChars::addAfter(uint i){
	GList::addAfter(new GListFrameChars(i));
}

void GListChars::addBefore(uint i){
	GList::addBefore(new GListFrameChars(i));
}

GListFrameChars* GListChars::getFrame(){
	return (GListFrameChars*)GList::getFrame();
}
