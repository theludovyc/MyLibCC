#include "aary.h"

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
