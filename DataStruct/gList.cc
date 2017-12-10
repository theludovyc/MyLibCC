#include "gList.h"

GListFrame::GListFrame(){
	preFrame=NULL;
	postFrame=NULL;
}

GListFrame::~GListFrame(){
}


void GList::add_l1(GListFrame *frame){
	(*myFrame).postFrame=frame;
	(*myFrame).preFrame=frame;
	(*frame).postFrame=myFrame;
	(*frame).preFrame=myFrame;
}

void GList::deleteFrame(bool b){
	switch(length){
	case 1:
		delete(myFrame);
		myFrame=NULL;
		length=0;
		return;

	case 2:
		myFrame=(*myFrame).preFrame;

		delete( (*myFrame).postFrame);

		(*myFrame).postFrame=NULL;
		(*myFrame).preFrame=NULL;

		length=1;
		return;

	default:
		GListFrame *tmp;
		if(b){
			tmp=(*myFrame).postFrame;
		}else{
			tmp=(*myFrame).preFrame;
		}
			
		(*(*myFrame).preFrame).postFrame=(*myFrame).postFrame;
			
		(*(*myFrame).postFrame).preFrame=(*myFrame).preFrame;

		delete(myFrame);

		myFrame=tmp;

		length--;
		return;
	}
}

GList::GList(){
	length=0;
	myFrame=NULL;
}

uint GList::getLength(){
	return length;
}
	
GListFrame* GList::getFrame(){
	return myFrame;
}

void GList::addAfter(GListFrame *frame){
	if(length==1){
		add_l1(frame);
	}else if(length>1){
		(*(*myFrame).postFrame).preFrame=frame;
		(*frame).postFrame=(*myFrame).postFrame;
				
		(*frame).preFrame=myFrame;
		(*myFrame).postFrame=frame;
	}
		
	myFrame=frame;
	length++;
}
	
void GList::addBefore(GListFrame *frame){
	if(length==1){
		add_l1(frame);
	}else if(length>1){
		(*(*myFrame).preFrame).postFrame=frame;
		(*frame).preFrame=(*myFrame).preFrame;

		(*myFrame).preFrame=frame;
		(*frame).postFrame=myFrame;
	}

	myFrame=frame;
	length++;
}

void GList::deleteFrame_goAfter(){
	deleteFrame(true);
}

void GList::deleteFrame_goBefore(){
	deleteFrame(false);
}

void GList::clear(){
	while(myFrame!=NULL){
		deleteFrame_goAfter();
	}
}

GList::~GList(){
	clear();
}

void GList::rollAfter(){
	if(length>1){
		myFrame=(*myFrame).postFrame;
	}
}

void GList::rollBefore(){
	if(length>1){
		myFrame=(*myFrame).preFrame;
	}
}

void GList::rollAfter(uint i){
	if(length>1){
		uint j;
		for(j=0; j<i; j++){
			myFrame=(*myFrame).postFrame;
		}
	}
}

void GList::rollBefore(uint i){
	if(length>1){
		uint j;
		for(j=0; j<i; j++){
			myFrame=(*myFrame).preFrame;
		}
	}
}
