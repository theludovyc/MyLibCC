#ifndef _GListChars
#define _GListChars

#include "gList.h"

#include "dynAryChar.h"

class GListFrameChars : public GListFrame, public DynAryChar{
public:
	GListFrameChars(uint i);
};

class GListChars : public GList{
public:
	GListChars();

	void addAfter(uint i);

	void addBefore(uint i);

	GListFrameChars* getFrame();
};

#endif
