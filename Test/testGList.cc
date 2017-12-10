#include "gList.h"

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
