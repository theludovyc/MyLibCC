#define _Tab

#ifndef _Tool
	#include "Tool.cc"
#endif

class Tab{
	protected:
		unsigned int length;
		unsigned int sizeEl;
		char *ad;

	public:
		Tab(){
		}

		Tab(unsigned int i,size_t s){
			length=i;
			sizeEl=s;
			ad=(char*)malloc(sizeof(char)*s*i);
			if(ad==NULL){
				Tool_errorMemoryAllocation0("Tab::Tab(unsigned int i,size_t)");
			}
		}

		void init(unsigned int i,size_t s){
			length=i;
			sizeEl=s;
			ad=(char*)malloc(sizeof(char)*s*i);
			if(ad==NULL){
				Tool_errorMemoryAllocation0("Tab::Tab(unsigned int i,size_t)");
			}
		}

		~Tab(){
			free(ad);
		}

		void *getEl(unsigned int i){
			if(i<length){
				return ad+sizeEl*i;
			}else{
				Tool_error0("Tab::void*:getEl(unsigned int): Out of Length!\n");
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

#ifndef _TabMain
	int main(){
		Tab t;
		t.init(1024,sizeof(char));
		printf("length: %d\n",t.getLength());
	}
#endif