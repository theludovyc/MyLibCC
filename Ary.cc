#define _Ary

#ifndef _Tool
	#include "Tool.cc"
#endif

class Ary{
	protected:
		unsigned int length;
		unsigned int sizeEl;
		char *ad;

	public:
		Ary(){
		}

		Ary(unsigned int i,size_t s){
			length=i;
			sizeEl=s;
			ad=(char*)malloc(sizeof(char)*s*i);
			if(ad==NULL){
				Tool_errorMemoryAllocation0("Ary::Ary(unsigned int i,size_t)");
			}
		}

		void init(unsigned int i,size_t s){
			length=i;
			sizeEl=s;
			ad=(char*)malloc(sizeof(char)*s*i);
			if(ad==NULL){
				Tool_errorMemoryAllocation0("Ary::Ary(unsigned int i,size_t)");
			}
		}

		~Ary(){
			free(ad);
		}

		void *getEl(unsigned int i){
			if(i<length){
				return ad+sizeEl*i;
			}else{
				Tool_error0("Ary::void*:getEl(unsigned int): Out of Length!\n");
			}
			return NULL;
		}

		void *getAd(){
			return ad;
		}

		int getLength(){
			return length;
		}

		int getElSize(){
			return sizeEl;
		}
};

#ifndef _Main
	int main(){
		Ary a;
		a.init(1024,sizeof(char));
		printf("length: %d\n", a.getLength());
	}
#endif