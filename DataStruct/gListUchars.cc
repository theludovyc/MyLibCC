#define _GListUchars

#ifndef _GList
#define _GListMain
#include "gList.cc"
#undef _GListMain
#endif

#ifndef _DynAryUchar
#include "dynAryUchar.cc"
#endif



class GListFrameUchars : public GListFrame, public DynAryUchar{
public:
	GListFrameUchars(uint i)
		:GListFrame(), DynAryUchar(i){
	}

	~GListFrameUchars(){
	}
};

class GListUchars : public GList{
public:
	GListUchars()
		:GList(){
	}

	void addAfter(uint i){
		GList::addAfter(new GListFrameUchars(i));
	}

	void addBefore(uint i){
		GList::addBefore(new GListFrameUchars(i));
	}

	GListFrameUchars* getFrame(){
		return (GListFrameUchars*)GList::getFrame();
	}
};

#ifndef _GListUcharsMain
int main(){
	GListUchars (*l)=new GListUchars();

	(*l).addAfter(1);

	printf("%d : length\n", (* (*l).getFrame() ).getLength() );

	delete(l);
	
	return 0;
}
#endif
