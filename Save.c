//Gearwheel List
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
