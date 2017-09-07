//Gearwheel
#define _Gw

#ifndef _Tool
	#include "Tool.cc"
#endif

class GwCase{
	public:
		GwCase *gw0;
		GwCase *gw1;

		GwCase(){
			gw0=NULL;
			gw1=NULL;
		}

		GwCase(GwCase *gwA, GwCase *gwB){
			gw0=gwA;
			gw1=gwB;
		}

		void init(GwCase *gwA, GwCase *gwB){
			gw0=gwA;
			gw1=gwB;
		}

		~GwCase(){
		}
};

class Gw{
	protected:
		unsigned int length;
		unsigned int pos;
		GwCase *g;

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

		void addUp(GwCase *gc){
			if(gc!=NULL){
				if(length==0){
					g=gc;
					length++;
					return;
				}else if(length==1){
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
			}
		}

		void addDown(GwCase *gc){
			if(gc!=NULL){
				if(length==0){
					g=gc;
					length++;
					return;
				}else if(length==1){
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
			}
		}
	public:
		Gw(){
			length=0;
			pos=0;
			g=NULL;
		}

		~Gw(){
		}

		unsigned int getLength(){
			return length;
		}

		unsigned int getPos(){
			return pos;
		}

		GwCase *getCase(){
			return g;
		}

		bool deleteCaseUp(){
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

		bool rollUp(){
			if((*g).gw1!=NULL){
				g=(*g).gw1;
				if(pos==length-1){
					pos=0;
				}else{
					pos++;
				}
				return true;
			}
			return false;
		}

		bool rollUpTo(unsigned int i){
			return _rollUpTo(i);
		}

		bool rollDown(){
			if((*g).gw0!=NULL){
				g=(*g).gw0;
				if(pos==0){
					pos=length-1;
				}else{
					pos--;
				}
				return true;
			}
			return false;
		}

		bool rollDownTo(unsigned int i){
			return _rollDownTo(i);
		}

		bool rollTo(unsigned int i){
			return _rollTo(i);
		}
};

#ifndef _GwMain
	class GwCaseChar:public GwCase{
		public:
			char c;

			GwCaseChar()
			:GwCase(){
			}

			GwCaseChar(char c1)
			:GwCase(){
				c=c1;
			}

			~GwCaseChar(){
			}
	};

	class GwChar:public Gw{
		public:
			GwChar()
			:Gw(){
			}

			char getValue(){
				return (*(GwCaseChar*)g).c;
			}

			void addUp(){
				GwCaseChar *gc=new GwCaseChar();
				Gw::addUp(gc);
			}

			void addUp(char c){
				GwCaseChar *gc=new GwCaseChar(c);
				Gw::addUp(gc);
			}
	};

	int main(){
		GwChar *g=new GwChar();
		(*g).addUp(0);
		printf("%d\n",(*g).getValue());
		(*g).addUp(1);
		printf("%d\n",(*g).getValue());
		(*g).addUp(2);
		printf("%d\n",(*g).getValue());
		(*g).deleteCaseUp();
		printf("%d\n",(*g).getValue());
	}
#endif