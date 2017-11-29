//Gearwheel List
#define _GList

#ifndef _Tool
	#include "../Tool.cc"
#endif

class GListFrame{
	public:
		GListFrame *preFrame;
		GListFrame *postFrame;

		GListFrame(){
			preFrame=NULL;
			postFrame=NULL;
		}

		~GListFrame(){
		}
};

class GList{
private:
	void add_l1(GListFrame *frame){
		(*myFrame).postFrame=frame;
		(*myFrame).preFrame=frame;
		(*frame).postFrame=myFrame;
		(*frame).preFrame=myFrame;
	}

	void deleteFrame(bool b){
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
	
protected:
	unsigned int length;
	GListFrame *myFrame;
		
public:
	GList(){
		length=0;
		myFrame=NULL;
	}

	unsigned int getLength(){
		return length;
	}
	
	GListFrame* getFrame(){
		return myFrame;
	}

	void addAfter(GListFrame *frame){
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
	
	void addBefore(GListFrame *frame){
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

	void deleteFrame_goAfter(){
		deleteFrame(true);
	}

	void deleteFrame_goBefore(){
		deleteFrame(false);
	}

	void clear(){
		while(myFrame!=NULL){
			deleteFrame_goAfter();
		}
	}

	~GList(){
		clear();
	}

	void rollAfter(){
		if(length>1){
			myFrame=(*myFrame).postFrame;
		}
	}

	void rollBefore(){
		if(length>1){
			myFrame=(*myFrame).preFrame;
		}
	}

	void rollAfter(uint i){
		if(length>1){
			uint j;
			for(j=0; j<i; j++){
				myFrame=(*myFrame).postFrame;
			}
		}
	}

	void rollBefore(uint i){
		if(length>1){
			uint j;
			for(j=0; j<i; j++){
				myFrame=(*myFrame).preFrame;
			}
		}
	}
};

#ifndef _Main
class GListFrameChar:public GListFrame{
public:
	char c;

	GListFrameChar()
		:GListFrame(){
	}

	GListFrameChar(char c1)
		:GListFrame(){
		c=c1;
	}
};

class GListChar:public GList{
public:
	GListChar()
		:GList(){
	}

	GListFrameChar* getFrame(){
		return (GListFrameChar*)myFrame;
	}

	void addAfter(char c){
		GList::addAfter(new GListFrameChar(c));
	}

	void addBefore(char c){
		GList::addBefore(new GListFrameChar(c));
	}
};

int main(){
	GListChar *l=new GListChar();

	char c;

	for(c=0; c<64; c++){
		(*l).addAfter(c);
	}

	(*l).rollAfter(128);

	(*l).rollBefore(128);

	(*l).rollAfter(32);

	printf("%d\n", (*(*l).getFrame()).c);

	(*l).clear();

	for(c=0; c<64; c++){
		(*l).addBefore(c);
	}

	(*l).rollAfter(128);

	(*l).rollBefore(128);

	(*l).rollBefore(32);

	printf("%d\n", (*(*l).getFrame()).c);

	delete(l);

	return 0;
}
#endif
