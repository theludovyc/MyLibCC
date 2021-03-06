#define _List

#ifndef _Tool
	#include "../Tool.cc"
#endif

struct ListFrame{
	struct ListFrame *postFrame;
};
typedef struct ListFrame ListFrame;

class List{
	unsigned int nbEl;
	ListFrame *myPostFrame;

	/*ListFrame* _getFrame(unsigned int i){
		if(i<nbEl){
			if(i==0){
				return l;
			}else{
				ListFrame *lf;
				lf=(*l).l;
				int i1;
				for(i1=1;i1!=i;i1++){
					lf=(*lf).l;
				}
				return lf;
			}
		}
		return NULL;
	}

	ListFrame* _getLastFrame(){
		if(l!=NULL){
			if(nbEl==1){
				return l;
			}else{
				ListFrame *lf=(*l).l;
				while((*lf).l!=NULL){
					lf=(*lf).l;
				}
				return lf;
			}
		}
		return NULL;
	}*/

	/*
	bool _freeFrame(unsigned int i){
		if(i<nbEl){
			if(nbEl==1){
				free(l);
				l=NULL;
				nbEl--;
				return true;
			}else{
				ListFrame *lf;

				if(i==0){
					lf=l;
					l=(*l).l;
					free(lf);
					nbEl--;
					return true;
				}else if(i==nbEl-1){
					lf=_getFrame(nbEl-2);
					free((*lf).l);
					(*lf).l=NULL;
					nbEl--;
					return true;
				}else{
					ListFrame *tmp;
					lf=_getFrame(i-1);
					tmp=(*lf).l;
					(*lf).l=(*(*lf).l).l;
					free(tmp);
					nbEl--;
					return true;
				}
			}
		}
		return false;
	}
	*/

	public:
		List(){
			nbEl=0;
			myPostFrame=NULL;
		}

		~List(){
		}

		unsigned int getNbEl(){
			return nbEl;
		}

		void addFrameFirst(size_t size){
			if(nbEl==0){
				myPostFrame=(ListFrame*)malloc(sizeof(ListFrame)+size);
				if(myPostFrame==NULL){
					Tool_error1MemoryAllocation("List::addFrameFirst()");
				}
			}
			nbEl++;
		}

		void freeFirstFrame(){
			if(nbEl==1){
				free(myPostFrame);
				myPostFrame=NULL;
			}
			nbEl--;
		}

		ListFrame* getFirstFrame(){
			if(myPostFrame!=NULL){
				return myPostFrame;
			}
			return (ListFrame*)Tool_warning("List::getFirstFrame() : List is Empty!");
		}

		void* getFirstValue(){
			if(myPostFrame!=NULL){
				return myPostFrame+1;
			}
			return (ListFrame*)Tool_warning("List::getFirstValue() : List is Empty!");
		}

		/*
		void *addFrameFirstAndSetValue(ListFrame *lf){
		}
		*/

		/*ListFrame* getFrame(unsigned int i){
			if(nbEl!=0){
				ListFrame *lf=_getFrame(i);
				if(lf==NULL){
					return (ListFrame*)Tool_warning("List::getFrame(unsigned int) : Out of Length!");
				}
				return lf;
			}
			return (ListFrame*)Tool_warning("List::getFrame(unsigned int) : List is Empty!");
		}

		void addFrameLast(ListFrame *lf){
			ListFrame *lastF=_getLastFrame();
			if(lastF!=NULL){
				(*lastF).l=lf;
			}
			l=lf;
			nbEl++;
		}*/

		/*
		bool freeLastFrame(){
			if(nbEl==1){
				free(l);
				l=NULL;
				nbEl--;
				return true;
			}else{
				ListFrame *lf=_getFrame(nbEl-2);
				free((*lf).l);
				(*lf).l=NULL;
				nbEl--;
				return true;
			}
			warning("List::freeLastFrame(): List is Empty!");
			return false;
		}
		*/

		/*ListFrame* getLastFrame(){
			ListFrame *lf=_getLastFrame();
			if(lf!=NULL){
				return lf;
			}
			return (ListFrame*)Tool_warning("List::getLastFrame() : List is Empty!");
		}*/

		/*
		void *getValue(unsigned int i){
		}
		*/

		/*bool freeBetween(unsigned int i, unsigned int i1){
			ListFrame *lf;
			ListFrame *lfTmp;
			ListFrame *lfLink;

			if(nbEl!=0){
				if(i<nbEl){
					if(i1<nbEl){
						if(i<i1){
							if(i==i1){	
							}else{
								if(i==0){
									lf=l;
								}else{
									lf=_getFrame(i);
								}
								lfTmp=lf;

								if(i1==nbEl-1){
									while((*lf).l!=NULL){

									}
								}else{
									int i2;
									for(i2=i;i2<i1;i2++){

									}
								}
							}
						}
						Tool_error0("List::freeBetween(unsigned int, unsigned int): First int > Second int! (you should have <)");
						return false;
					}
					warning("List::freeBetween(unsigned int, unsigned int): Second int Out of Length!");
					return false;
				}
				warning("List::freeBetween(unsigned int, unsigned int): First int Out of Length!");
				return false;
			}
			warning("List::freeBetween(unsigned int, unsigned int): List is Empty!");
			return false;
		}
		*/

		/*
		bool freeAll(){
			if(nbEl==1){
				if((*l).v!=NULL){
					free((*l).v);
				}
				free(l);
				l=NULL;
				return true;
			}else{
				ListFrame *lf=l;
				do{

				}while(nbEl!=0);
			}
			warning("List::freeAll(): List is Empty!");
			return false;
		}
		*/
};

#ifndef _Main
	class ListChar:public List{
		public:
			ListChar()
			:List(){
			}

			void addFrameFirst(){
				List::addFrameFirst(sizeof(char));
			}

			char* getFirstValue(){
				return (char*)List::getFirstValue();
			}

			void addFrameFirst(char c){
				List::addFrameFirst(sizeof(char));
				(*getFirstValue())=c;
			}
	};

	int main(){
		ListChar *l=new ListChar();

		printf("%ld : size of listframe\n", sizeof(ListFrame));

		(*l).addFrameFirst(1);

		ListFrame *lf=(*l).getFirstFrame();

		printf("%p : lf address\n", lf);

		char *c=(*l).getFirstValue();

		printf("%p : c address\n", c);

		printf("%d : c value\n", *c );

		(*l).freeFirstFrame();

		delete(l);

		/*
		ListFrameChar *lf=(ListFrameChar*)(*l).getFirstFrame();

		(*l).addFrameFirst(0);

		printf("getFirstValue : %d\n", (*l).getFirstValue());

		(*l).addFrameFirst(1);

		printf("getFirstValue : %d\n", (*l).getFirstValue());

		(*l).addFrameFirst(2);

		printf("getFirstValue : %d\n", (*l).getFirstValue());

		printf("getNbEl : %d\n", (*l).getNbEl());

		lf=(ListFrameChar*)(*l).getFrame(1);

		printf("frame 1 value : %d\n", (*lf).val);

		*/

		printf("Appuyez sur entree pour continuer...");
    	getchar();

		return 0;
	}
#endif
