#ifndef _Ary
#define _Ary

#include "../tool.h"

class Ary{
	protected:
		unsigned int length;
		size_t sizeEl;
		void *ad;

	public:
		Ary(size_t s, unsigned int i);

		~Ary();

		void* operator[] (unsigned int i);
		
		void* getAd();

		unsigned int getLength();
		
		size_t getElSize();
};

#endif
