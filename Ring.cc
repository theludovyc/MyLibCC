#define _Ring

#ifndef _Tool
	#include "Tool.cc"
#endif

class RingCase{
	public:
		RingCase *rc0;
		RingCase *rc1;

		RingCase(){
			rc0=NULL;
			rc1=NULL;
		}

		RingCase(RingCase *rcA, RingCase *rcB){
			rc0=rcA;
			rc1=rcB;
		}

		void init(RingCase *rcA, RingCase *rcB){
			rc0=rcA;
			rc1=rcB;
		}

		~RingCase(){
		}
};

class Ring{
	unsigned int length;
	RingCase *r;

	protected:
		RingCase *_getCaseDown(unsigned int i){
			if(i<length){
				if(i==0){
					return r;
				}else{
					RingCase *rc;
					rc=(*r).rc0;
					int i1;
					for(i1=length-1;i1!=i;i1--){
						rc=(*r).rc0;
					}
					return rc;
				}
			}
			return NULL;
		}

		RingCase *_getCaseUp(unsigned int i){
			if(i<length){
				if(i==0){
					return r;
				}else{
					RingCase *rc;
					rc=(*r).rc1;
					int i1;
					for(i1=1;i1!=i;i1++){
						rc=(*r).rc1;
					}
					return rc;
				}
			}
			return NULL;
		}

		RingCase *_getCase(unsigned int i){
			if(i<length){
				if(i==1){
					return (*r).rc0;
				}else if(i>length/2){
					return _getCaseDown(i);
				}
				return _getCaseUp(i);
			}
			return NULL;
		}

		void addCase(RingCase *rc){
			if(length==0){
				r=rc;
				return;
			}else if(length==1){
				(*rc).init(r,r);
				(*r).rc0=rc;
				(*r).rc1=rc;
				return;
			}else if(length==2){
				(*r).rc0=rc;
				(*rc).init((*r).rc1,r);
				(*(*r).rc1).rc1=rc;
				return;
			}
			(*rc).init((*r).rc0,r);
			(*(*r).rc0).rc1=rc;
			(*r).rc0=rc;
			return;
		}
	public:
		void init(){
			length=0;
			r=NULL;
		}

		Ring(){
			length=0;
			r=NULL;
		}

		~Ring(){
		}

		unsigned int getLength(){
			return length;
		}

		RingCase *getFirstCase(){
			if(r!=NULL){
				return r;
			}
			warning("Ring::getFirstCase(): Case is Null!");
			return NULL;
		}

		RingCase *getLastCase(){
			if((*r).rc0!=NULL){
				return (*r).rc0;
			}
			warning("Ring::getLastCase(): Case is Null!");
			return NULL;
		}

		RingCase *getCase(unsigned int i){
			return _getCase(i);
		}
};

#ifndef _RingMain
	class RingCaseChar:public RingCase{
		public:
			char val;

			RingCaseChar()
			:RingCase(){
			}

			RingCaseChar(char c)
			:RingCase(){
				val=c;
			}

			~RingCaseChar(){
			}
	};

	class RingChar:public Ring{
		public:
			RingChar()
			:Ring(){
			}

			char getFirstValue(){
				return (*(RingCaseChar*)getFirstCase()).val;
			}

			void addCase(){
				RingCaseChar *rc=new RingCaseChar();
				Ring::addCase(rc);
			}

			void addCase(char c){
				RingCaseChar *rc=new RingCaseChar(c);
				Ring::addCase(rc);
			}
	};

	int main(){
		RingChar *r=new RingChar();
		(*r).addCase(0);
		printf("%d\n",(*r).getFirstValue());
		(*r).addCase(1);
		printf("%d\n",(*r).getFirstValue());
		(*r).addCase(2);
		printf("%d\n",(*r).getFirstValue());
	}
#endif