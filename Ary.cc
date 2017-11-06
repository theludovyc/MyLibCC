#define _Ary

#ifndef _Tool
	#include "Tool.cc"
#endif

class Ary{
	protected:
		unsigned int length;
		size_t sizeEl;
		void *ad;

	public:
		Ary(){
			length=0;
			ad=NULL;
		}

		Ary(size_t s, unsigned int i){
			sizeEl=s;
			length=i;
			ad=malloc(s*i);
			if(ad==NULL){
				Tool_error0MemoryAllocation("Ary::Ary(unsigned int, size_t)");
			}
		}

		~Ary(){
			free(ad);
		}

		void* operator[] (unsigned int i){
			if(i<length){
				return ad+sizeEl*i;
			}
			Tool_error0OutOfLength("Ary::operator[](unsigned int)");
			return NULL;
		}

		void* getAd(){
			return ad;
		}

		unsigned int getLength(){
			return length;
		}

		size_t getElSize(){
			return sizeEl;
		}
};

#ifndef _Main
	class AryInt:public Ary{
		public:
			AryInt(unsigned int i)
			:Ary(sizeof(int), i){
			}

			int* operator[] (unsigned int i){
				return (int*)Ary::operator[](i);
			}
	};

	int main(){
		AryInt *a=new AryInt(32);
		printf("length: %d\n", (*a).getLength());
		printf("%p : ad address\n", (*a).getAd());

		printf("%d : size of 1 element\n", (*a).getElSize());

		int *i=(*a)[2];
		printf("%p : i address\n", i);
	}
#endif