struct String1{
	const char *c;
	struct String1 *s;
};

class String{
	struct String1 s;

	public:
		String(const char *c){
			s.c=c;
		}

		const char* ret_c(){
			return s.c;
		}

		String operator+(const char *c){
			String1 *s1=&s;
			while((*s1).s!=NULL){
				s1=(*s1).s;
			}
			(*s1).s=(String1*)malloc(sizeof(String1));
			s1=(*s1).s;
			(*s1).c=c;
		}

		void affiche(){
			String1 *s1=&s;
			do{
				if((*s1).c!=NULL){
					puts((*s1).c);
				}else{
					break;
				}

				if((*s1).s!=NULL){
					s1=(*s1).s;
				}else{
					break;
				}
			}while(1);
		}
};