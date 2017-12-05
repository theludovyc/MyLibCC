#define _AAry

#ifndef _Ary
	#define _Main
	#include "ary.cc"
	#undef _Main
#endif

class AAry:public Ary{
	protected:
		unsigned short lengthX;
		unsigned short lengthY;

	public:
		AAry(size_t s, unsigned short i, unsigned short j)
			:Ary(s, i*j){
			lengthX=i;
			lengthY=j;
		}

		void* operator() (unsigned short i, unsigned short j){
			if(i<lengthX && j<lengthY){
				return ad+sizeEl*(j*lengthX+i);
			}
			Tool_error1OutOfLength("AAry::operator()(unsigned int, unsigned int)");
			return NULL;
		}
};

#ifndef _Main
	class AAryChar:public AAry{
		public:
			AAryChar(unsigned short i, unsigned short j)
			:AAry(sizeof(char),i,j){
			}

			char* operator() (unsigned short i, unsigned short j){
				return (char*)AAry::operator()(i,j);
			}
	};

	int main(){
		AAryChar *a=new AAryChar(2, 2);

		char *c=(*a)(1, 1);

		printf("%p : ad address\n", (*a).getAd());
		printf("%p : c address\n", c);

		delete(a);
	}
#endif
