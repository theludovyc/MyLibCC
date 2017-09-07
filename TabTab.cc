#define _TabTab

#ifndef _Tab
	#define _TabMain
	#include "Tab.cc"
	#undef _TabMain
#endif

class TabTab:public Tab{
	public:
		TabTab(){
		}

		~TabTab(){
		}

		void init(unsigned int i){
			Tab::init(i,sizeof(Tab));
		}

		TabTab(unsigned int i)
			:Tab(i,sizeof(Tab)){
		}

		void init(unsigned int i, unsigned int i1, size_t s){
			Tab::init(i,sizeof(Tab));
			Tab *t;
			for(i=0;i<length;i++){
				t=getElX(i);
				(*t).init(i1,s);
			}
		}

		TabTab(unsigned int i, unsigned int i1, size_t s)
			:Tab(i,sizeof(Tab)){
			Tab *t;
			for(i=0;i<length;i++){
				t=getElX(i);
				(*t).init(i1,s);
			}
		}

		Tab *getElX(unsigned int i){
			if(i<length){
				return (Tab*)(ad+sizeEl*i);
			}
			Tool_error0("TabTab::Tab*:getEl(unsigned int): Out of Length!\n");
			return NULL;
		}

		void *getElY(unsigned int i, unsigned int i1){
			return (*getElX(i)).getEl(i1);
		}
};

#ifndef _TabTabMain
	int main(){
		TabTab t;
		t.init(1024,768,sizeof(char));
		printf("length: %d\n",t.getLength());
	}
#endif