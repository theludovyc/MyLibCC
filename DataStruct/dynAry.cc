#define _DynAry

#ifndef _Ary
#define _AryMain
#include "Ary.cc"
#undef _AryMain
#endif

class DynAry: public Ary{
public:
	DynAry(size_t s, uint i)
		:Ary(s, i){
	}

	void resize(uint i){
		void *tmp=realloc(ad, sizeEl*i);
		if(tmp==NULL){
			Tool_error1MemoryReallocation("DynAry::Resize(...)");
		}
		length=i;
		ad=tmp;
	}

	void resize_add(uint i){
		resize(length+i);
	}

	void resize_mul(uint i){
		resize(length*i);
	}
};

#ifndef _DynAryMain
int main(){
	DynAry *tab=new DynAry(sizeof(char), 4);

	printf("%d : length\n", (*tab).getLength());

	(*tab).resize_mul(2);

	printf("%d : length\n", (*tab).getLength());
}
#endif
