//Gearwheel List
#define _GList

#ifndef _Tool
	#include "Tool.cc"
#endif

class GListFrame{
	public:
		GListFrame *preFrame;
		GListFrame *postFrame;

		GListFrame(){
			preFrame=NULL;
			postFrame=NULL;
		}

		GListFrame(GListFrame *preF, GListFrame *postF){
			preFrame=preF;
			postFrame=postF;
		}

		~GListFrame(){
		}
};

/*
	bool _rollUpTo(unsigned int i){
	if(i<length){
	if(i==pos){
	return true;
	}else{
	do{
	g=(*g).gw1;
	if(pos==length-1){
	pos=0;
	}else{
	pos++;
	}
	}while(i!=pos);
	return true;
	}
	}
	return false;
	}

	bool _rollDownTo(unsigned int i){
	if(i<length){
	if(i==pos){
	return true;
	}else{
	do{
	g=(*g).gw0;
	if(pos==0){
	pos=length-1;
	}else{
	pos--;
	}
	}while(i!=pos);
	return true;
	}
	}
	return false;
	}

	unsigned char _iPos(unsigned int i){
	if(i!=length/2){
	if(i<length/2){
	if(i!=length/4){
	if(i<length/4){
	return 2;
	}
	return 3;
	}
	return 1;
	}else{
	if(i!=length*3/4){
	if(i<length*3/4){
	return 5;
	}else{
	return 6;
	}
	}
	return 4;
	}
	}else{
	return 0;
	}
	}


		bool _rollTo(unsigned int i){
			if(i<length){
				if(i==pos){
					return true;
				}else if(length>3){
					if(pos!=length/2){
						if(pos<length/2){
							if(pos!=length/4){
								if(pos<length/4){
									unsigned char cTmp=_iPos(i);
									if(cTmp==2){
										if(pos<i){
											return _rollUpTo(i);
										}
										return _rollDownTo(i);
									}else if(cTmp<4){
										return _rollUpTo(i);
									}
									return _rollDownTo(i);
								}
								switch(_iPos(i)){
									case 0:
										return _rollUpTo(i);

									case 1:
										return _rollDownTo(i);

									case 2:
										return _rollDownTo(i);

									case 3:
										if(pos<i){
											return _rollUpTo(i);
										}
										return _rollDownTo(i);

									case 4:
										return _rollUpTo(i);

									case 5:
										return _rollUpTo(i);

									case 6:
										return _rollDownTo(i);
								}
							}
							switch(_iPos(i)){
								case 0:
									return _rollUpTo(i);

								case 2:
									return _rollDownTo(i);

								case 3:
									return _rollUpTo(i);

								case 4:
									return _rollDownTo(i);

								case 5:
									return _rollUpTo(i);

								case 6:
									return _rollDownTo(i);
							}
						}else{
							if(pos!=length*3/4){
								if(pos<length*3/4){
									switch(_iPos(i)){
										case 0:
											return _rollDownTo(i);

										case 1:
											return _rollDownTo(i);

										case 2:
											return _rollUpTo(i);

										case 3:
											return _rollDownTo(i);

										case 4:
											return _rollUpTo(i);

										case 5:
											if(pos<i){
												return _rollUpTo(i);
											}
											return _rollDownTo(i);

										case 6:
											return _rollUpTo(i);
									}
								}
								unsigned char cTmp=_iPos(i);
								if(cTmp==6){
									if(pos<i){
										return _rollUpTo(i);
									}
									return _rollDownTo(i);
								}else if(cTmp==0||cTmp>3){
									return _rollDownTo(i);
								}
								return _rollUpTo(i);
							}
							switch(_iPos(i)){
								case 0:
									return _rollDownTo(i);

								case 1:
									return _rollUpTo(i);

								case 2:
									return _rollUpTo(i);

								case 3:
									return _rollDownTo(i);

								case 5:
									return _rollDownTo(i);

								case 6:
									return _rollUpTo(i);
							}
						}
					}
					if(_iPos(i)<4){
						return _rollDownTo(i);
					}
					return _rollUpTo(i);
				}else{
					if(pos==length-1&&i<length/2){
						return _rollUpTo(i);
					}else if(pos==0&&i>length/2){
						return _rollDownTo(i);
					}else if(pos>i){
						return _rollDownTo(i);
					}else{
						return _rollUpTo(i);
					}
				}
			}
			return false;
		}

void deleteCaseUp(){
		if(g!=NULL){
			if(length==1){
				delete(g);
			}else if(length==2){
				GwCase *tmp=(*g).gw1;
				delete(g);
				g=tmp;
				(*g).gw0=NULL;
				(*g).gw1=NULL;
			}else{
				GwCase *tmp=(*g).gw0;
				g=(*g).gw1;
				delete((*g).gw0);
				(*g).gw0=tmp;
			}
			length--;
			return true;
		}
		return false;
	}

bool deleteCaseDown(){
		if(g!=NULL){
			if(length==1){
				delete(g);
			}else if(length==2){
				GwCase *tmp=(*g).gw0;
				delete(g);
				g=tmp;
				(*g).gw0=NULL;
				(*g).gw1=NULL;
			}else{
				GwCase *tmp=(*g).gw1;
				g=(*g).gw0;
				delete((*g).gw1);
				(*g).gw1=tmp;
			}
			length--;
			return true;
		}
		return false;
	}
*/

class GList{
protected:
	unsigned int length;
	GListFrame *myFrame;
		
public:
	GList(){
		length=0;
		myFrame=NULL;
	}

	unsigned int getLength(){
		return length;
	}
	
	GListFrame* getFrame(){
		return myFrame;
	}

	void addAfter(GListFrame *frame){
		if(length!=0){
			if(length==1){
				(*myFrame).postFrame=frame;
				(*myFrame).preFrame=frame;
				(*frame).postFrame=myFrame;
				(*frame).preFrame=myFrame;
			}else{
				(*(*myFrame).postFrame).preFrame=frame;
				(*frame).postFrame=(*myFrame).postFrame;
				
				(*frame).preFrame=myFrame;
				(*myFrame).postFrame=frame;
			}
		}
		
		myFrame=frame;
		length++;
		
		/*
			else if(length==1){
			(*gc).init(g,g);
			(*g).gw0=gc;
			(*g).gw1=gc;
			g=gc;
			pos=1;
			length++;
			return;
			}else{
			GwCase *tmp=(*g).gw0;
			(*g).gw0=gc;
			(*gc).init(tmp,g);
			g=gc;
			if(pos!=0){
			pos--;
			}
			length++;
			return;
			}
		*/
	}
	
	void addBefore(GListFrame *frame){
		if(length==0){
			myFrame=frame;
			length++;
			return;
		}

		/*else if(length==1){
			(*gc).init(g,g);
			(*g).gw1=gc;
			(*g).gw0=gc;
			g=gc;
			pos=1;
			length++;
			return;
			}else{
			GwCase *tmp=(*g).gw1;
			(*g).gw1=gc;
			(*gc).init(g,tmp);
			g=gc;
			length++;
			if(pos!=length-1){
			pos++;
			}
			return;
			}
		*/
	}

	void deleteFrame(){
		switch(length){
		case 1:
			delete(myFrame);
			myFrame=NULL;
			length=0;
			return;

		case 2:
			myFrame=(*myFrame).preFrame;

			delete( (*myFrame).postFrame);

			(*myFrame).postFrame=NULL;
			(*myFrame).preFrame=NULL;

			length=1;
			return;

		default:
			GListFrame *tmp=(*myFrame).preFrame;
			
			(*(*myFrame).preFrame).postFrame=(*myFrame).postFrame;
			
			(*(*myFrame).postFrame).preFrame=(*myFrame).preFrame;

			delete(myFrame);

			myFrame=tmp;

			length--;
			return;
		}
	}

	void clear(){
		while(myFrame!=NULL){
			deleteFrame();
		}
	}

	~GList(){
		clear();
	}

	void rollAfter(){
		if(length>1){
			myFrame=(*myFrame).postFrame;
		}
	}

	void rollBefore(){
		if(length>1){
			myFrame=(*myFrame).preFrame;
		}
	}

	void rollAfter(uint i){
		if(length>1){
			uint j;
			for(j=0; j<i; j++){
				myFrame=(*myFrame).postFrame;
			}
		}
	}

	void rollBefore(uint i){
		if(length>1){
			uint j;
			for(j=0; j<i; j++){
				myFrame=(*myFrame).preFrame;
			}
		}
	}
};

#ifndef _Main
class GListFrameChar:public GListFrame{
public:
	char c;

	GListFrameChar()
		:GListFrame(){
	}

	GListFrameChar(char c1)
		:GListFrame(){
		c=c1;
	}
};

class GListChar:public GList{
public:
	GListChar()
		:GList(){
	}

	GListFrameChar* getFrame(){
		return (GListFrameChar*)myFrame;
	}

	void addAfter(){
		GList::addAfter(new GListFrameChar() );
	}

	void addAfter(char c){
		GList::addAfter(new GListFrameChar(c));
	}
};

int main(){
	GListChar *l=new GListChar();

	char c;

	for(c=0; c<64; c++){
		(*l).addAfter(c);
	}

	(*l).rollAfter(128);

	(*l).rollBefore(128);

	delete(l);

	return 0;
}
#endif
