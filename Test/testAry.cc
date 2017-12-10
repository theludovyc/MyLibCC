#include "ary.h"

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

	printf("%p : i address\n", (*a)[2]);

	(*(*a)[2])=12;

	printf("%d : i value\n", (*(*a)[2]));
}
