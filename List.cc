#ifndef _Tool
	#include "Tool.cc"
#endif

struct ListCase{
	void *v;
	ListCase *l;
};

class List{
	unsigned int nbEl;
	ListCase *l;

	ListCase *_getLastCase(){
		if(l!=NULL){
			if(nbEl==1){
				return l;
			}else{
				ListCase *lc=(*l).l;
				while((*lc).l!=NULL){
					lc=(*lc).l;
				}
				return lc;
			}
		}
		return NULL;
	}

	ListCase *_getCase(unsigned int i){
		if(i<nbEl){
			if(i==0){
				return l;
			}else{
				ListCase *lc;
				lc=(*l).l;
				int i1;
				for(i1=1;i1!=i;i1++){
					lc=(*lc).l;
				}
				return lc;
			}
		}
		return NULL;
	}

	unsigned char _freeValue(unsigned int i){
		ListCase *lc;
		lc=_getCase(i);
		if(lc!=NULL){
			if((*lc).v!=NULL){
				free((*lc).v);
				(*lc).v=NULL;
				return 0;
			}
			return 1;
		}
		return 2;
	}

	bool _freeCase(unsigned int i){
		if(i<nbEl){
			if(nbEl==1){
				free(l);
				l=NULL;
				nbEl--;
				return true;
			}else{
				ListCase *lc;

				if(i==0){
					lc=l;
					l=(*l).l;
					free(lc);
					nbEl--;
					return true;
				}else if(i==nbEl-1){
					lc=_getCase(nbEl-2);
					free((*lc).l);
					(*lc).l=NULL;
					nbEl--;
					return true;
				}else{
					ListCase *tmp;
					lc=_getCase(i-1);
					tmp=(*lc).l;
					(*lc).l=(*(*lc).l).l;
					free(tmp);
					nbEl--;
					return true;
				}
			}
		}
		return false;
	}

	bool _freeCaseAndValue(unsigned int i){
		if(i<nbEl){
			if(nbEl==1){
				if((*l).v!=NULL){
					free((*l).v);
				}
				free(l);
				l=NULL;
				nbEl--;
				return true;
			}else{
				ListCase *lc;

				if(i==0){
					lc=l;
					l=(*l).l;
					if((*lc).v!=NULL){
						free((*lc).v);
					}
					free(lc);
					nbEl--;
					return true;
				}else if(i==nbEl-1){
					lc=_getCase(nbEl-2);
					if((*(*lc).l).v!=NULL){
						free((*(*lc).l).v);
					}
					free((*lc).l);
					(*lc).l=NULL;
					nbEl--;
					return true;
				}else{
					ListCase *tmp;
					lc=_getCase(i-1);
					tmp=(*lc).l;
					(*lc).l=(*(*lc).l).l;
					if((*tmp).v!=NULL){
						free((*tmp).v);
					}
					free(tmp);
					nbEl--;
					return true;
				}
			}
		}
		return false;
	}

	void _initCase(ListCase* lc){
		(*lc).v=NULL;
		(*lc).l=NULL;
	}

	public:
		List(){
			nbEl=0;
			l=NULL;
		}

		~List(){
		}

		unsigned int getNbEl(){
			return nbEl;
		}

		void *getValueWithCase(ListCase *lc){
			if((*lc).v!=NULL){
				return (*lc).v;
			}
			return nullWarning("List::getValue(ListCase*) : Value");
		}

		ListCase *getCase(unsigned int i){
			if(nbEl!=0){
				ListCase *lc=_getCase(i);
				if(lc==NULL){
					error0("List::getCase(unsigned int): Out of Length!");
				}
			}
			warning("List::getCase(unsigned int): List is Empty!");
			return NULL;
		}

		void *getValue(unsigned int i){
			if(nbEl!=0){
				ListCase *lc=_getCase(i);
				if(lc==NULL){
					error0("List::getValue(unsigned int): Out of Length!");
				}

				if((*lc).v!=NULL){
					return (*lc).v;
				}
				return nullWarning("List::getValue(unsigned int): Value");
			}
			warning("List::getValue(unsigned int): List is Empty!");
		}

		void *setValue(ListCase *lc, size_t s){
			(*lc).v=malloc(s);
			if((*lc).v==NULL){
				errorMemoryAllocation0("List::setValue()");
			}
			return (*lc).v;
		}

		bool freeBetween(unsigned int i, unsigned int i1){
			ListCase *lc;
			ListCase *lcTmp;
			ListCase *lcLink;

			if(nbEl!=0){
				if(i<nbEl){
					if(i1<nbEl){
						if(i<i1){
							if(i==i1){	
							}else{
								if(i==0){
									lc=l;
								}else{
									lc=_getCase(i);
								}
								lcTmp=lc;

								if(i1==nbEl-1){
									while((*lc).l!=NULL){

									}
								}else{
									int i2;
									for(i2=i;i2<i1;i2++){

									}
								}
							}
						}
						error0("List::freeBetween(unsigned int, unsigned int): First int > Second int! (you should have <)");
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

		bool freeAll(){
			if(nbEl==1){
				if((*l).v!=NULL){
					free((*l).v);
				}
				free(l);
				l=NULL;
				return true;
			}else{
				ListCase *lc=l;
				do{

				}while(nbEl!=0);
			}
			warning("List::freeAll(): List is Empty!");
			return false;
		}

		ListCase *getFirstCase(){
			if(l!=NULL){
				return l;
			}
			return (ListCase*)warning("List::getFirstCase(): List is Empty!");
		}

		void *getFirstValue(){
			if(l!=NULL){
				if((*l).v!=NULL){
					return (*l).v;
				}
				return nullWarning("List::getFirstValue(): Value");
			}
			warning("List::getFirstValue(): List is Empty!");
			return NULL;
		}

		ListCase *addCaseFirst(){
			ListCase *lc;
			lc=(ListCase*)malloc(sizeof(ListCase));
			if(lc==NULL){
				errorMemoryAllocation0("List::addCaseFirst()");
			}
			_initCase(lc);

			if(l!=NULL){
				(*lc).l=l;
			}
			l=lc;
			return l;
		}

		void *addCaseFirstAndSetValue(size_t s){
			return setValue(addCaseFirst(),s);
		}

		bool freeFirstValue(){
			if((*l).v!=NULL){
				free((*l).v);
				(*l).v=NULL;
				return true;
			}
			warning("List::freeFirstValue(): Value is Null!");
			return false;
		}

		bool freeFirstCase(){
			if(l!=NULL){
				if((*l).l!=NULL){
					ListCase *lc=(*l).l;
					free(l);
					l=lc;
					nbEl--;
					return true;
				}
				free(l);
				l=NULL;
				nbEl--;
				return true;
			}
			warning("List::freeFirstCase(): List is Empty!");
			return false;
		}

		bool freeFirstCaseAndValue(){
			return false;
		}

		ListCase *getLastCase(){
			ListCase *lc=_getLastCase();
			if(lc!=NULL){
				return lc;
			}
			warning("List::getLastCase(): List is Empty!");
			return NULL;
		}

		void *getLastValue(){
			ListCase *lc=_getLastCase();
			if(lc!=NULL){
				if((*lc).v!=NULL){
					return (*lc).v;
				}
				return nullWarning("List::getLastValue(): Value");
			}
			warning("List::getLastValue(): List is Empty!");
			return NULL;
		}

		ListCase *addCaseLast(){
			ListCase *lc=_getLastCase();
			if(lc!=NULL){
				(*lc).l=(ListCase*)malloc(sizeof(ListCase));
				if((*lc).l==NULL){
					errorMemoryAllocation0("List::addCaseLast()");
				}
				lc=(*lc).l;
				_initCase(lc);
				nbEl++;
				return lc;
			}

			l=(ListCase*)malloc(sizeof(ListCase));
			if(l==NULL){
				errorMemoryAllocation0("List::addCaseLast()");
			}
			_initCase(l);
			nbEl++;
			return l;
		}

		void *addCaseLastAndSetValue(size_t s){
			return setValue(addCaseLast(),s);
		}

		bool freeLastValue(){
			ListCase *lc=_getLastCase();
			if(lc!=NULL){
				if((*lc).v!=NULL){
					free((*lc).v);
					(*lc).v=NULL;
					return true;
				}
				warning("List::freeLastValue(): Value is Null!");
				return false;
			}
			warning("List::freeLastValue(): List is Empty!");
			return false;
		}

		bool freeLastCase(){
			if(nbEl==1){
				free(l);
				l=NULL;
				nbEl--;
				return true;
			}else{
				ListCase *lc=_getCase(nbEl-2);
				free((*lc).l);
				(*lc).l=NULL;
				nbEl--;
				return true;
			}
			warning("List::freeLastCase(): List is Empty!");
			return false;
		}

		bool freeLastCaseAndValue(){
			if(nbEl==1){
				if((*l).v!=NULL){
					free((*l).v);
					(*l).v=NULL;
				}else{
					warning("List::freeLastCaseAndValue(): Value is NULL");
				}

				free(l);
				l=NULL;
				nbEl--;
				return true;
			}else{
				ListCase *lc=_getCase(nbEl-2);
				if((*(*lc).l).v!=NULL){
					free((*(*lc).l).v);
				}else{
					warning("List::freeLastCaseAndValue(): Value is NULL");
				}

				free((*lc).l);
				(*lc).l=NULL;
				nbEl--;
				return true;
			}
			warning("List::freeLastCaseAndValue(): List is Empty!");
			return false;
		}
};

#ifndef _main
	int main(){
		List *l;
		l=new List();
		ListCase *lc=(*l).getFirstCase();
		int *i=(int*)(*l).addCaseLastAndSetValue(sizeof(int));
		(*i)=0;
		i=(int*)(*l).addCaseLastAndSetValue(sizeof(int));
		(*i)=1;
		i=(int*)(*l).addCaseLastAndSetValue(sizeof(int));
		(*i)=2;
		printf("nbEl: %d\n",(*l).getNbEl());

		i=(int*)(*l).getValue(0);
		printf("getValue 0: %d\n",(*i));
		i=(int*)(*l).getValue(1);
		printf("getValue 1: %d\n",(*i));
		i=(int*)(*l).getValue(2);
		printf("getValue 2: %d\n",(*i));

		i=(int*)(*l).getFirstValue();
		printf("getFirstValue: %d\n",(*i));

		i=(int*)(*l).getLastValue();
		printf("getLastValue: %d\n",(*i));

		bool b=(*l).freeLastCaseAndValue();
		printf("freeLastCaseAndValue: %d\n",b);

		i=(int*)(*l).getLastValue();
		printf("getLastValue: %d\n",(*i));
		return 0;
	}
#endif