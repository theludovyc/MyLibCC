#define _GListChars

#ifndef _GList
#define _GListMain
#include "gList.cc"
#undef _GListMain
#endif

#ifndef _DynAryChar
#include "dynAryChar.cc"
#endif



class GListFrameChars : public GListFrame, public DynAryChar{
public:
	GListFrameChars(uint i)
		:GListFrame(), DynAryChar(i){
	}

	~GListFrameChars(){
	}
};

class GListChars : public GList{
public:
	GListChars()
		:GList(){
	}

	void addAfter(uint i){
		GList::addAfter(new GListFrameChars(i));
	}

	void addBefore(uint i){
		GList::addBefore(new GListFrameChars(i));
	}

	GListFrameChars* getFrame(){
		return (GListFrameChars*)GList::getFrame();
	}
};

#ifndef _GListCharsMain
int main(){
	GListChars (*l)=new GListChars();

	(*l).addAfter(1);

	printf("%d : length\n", (* (*l).getFrame() ).getLength() );

	delete(l);
	
	return 0;
}
#endif
