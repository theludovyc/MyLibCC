#include "dynAry.h"

int main(){
	DynAry *tab=new DynAry(sizeof(char), 4);

	printf("%d : length\n", (*tab).getLength());

	(*tab).resize_mul(2);

	printf("%d : length\n", (*tab).getLength());
}
