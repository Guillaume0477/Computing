#include <stdio.h>
#include <stdlib.h>


typedef struct Element Element;	
	struct Element { 
  		int nombre;
		Element *suivant;
		Eleme,t *precedent;
	};

typedef struct Liste Liste;
	struct Liste {
		size_t length
		Element *dernier;
		Element *premier;
	};


