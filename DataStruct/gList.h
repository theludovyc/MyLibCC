#ifndef _GList
#define _GList

#include "../tool.h"

class GListFrame{
	public:
		GListFrame *preFrame;
		GListFrame *postFrame;

		GListFrame();

		virtual ~GListFrame();
};

class GList{
private:
	void add_l1(GListFrame *frame);

	void deleteFrame(bool b);
	
protected:
	unsigned int length;
	GListFrame *myFrame;
		
public:
	GList();

	unsigned int getLength();
	
	GListFrame* getFrame();

	void addAfter(GListFrame *frame);
	
	void addBefore(GListFrame *frame);

	void deleteFrame_goAfter();

	void deleteFrame_goBefore();

	void clear();

	~GList();

	void rollAfter();

	void rollBefore();

	void rollAfter(uint i);

	void rollBefore(uint i);
};

#endif
