#include "gListChars.h"

int main(){
	GListChars (*l)=new GListChars();

	(*l).addAfter(1);

	printf("%d : length\n", (* (*l).getFrame() ).getLength() );

	delete(l);
	
	return 0;
}
