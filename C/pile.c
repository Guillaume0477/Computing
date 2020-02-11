#include <stdio.h>
#include <stdlib.h>


typedef struct Element Element;	
	struct Element { 
  		int nombre;
		Element *suivant;
	};

typedef struct Liste Liste;
	struct Liste {
		Element *premier;
	};

void Empiler(int nvNombre, struct Liste *liste){
		Element *nouveau = malloc(sizeof(*nouveau));
		if ((liste == NULL) || (nouveau == NULL)){
			exit(EXIT_FAILURE);
		};
		nouveau -> nombre =nvNombre;
		(nouveau ->suivant) = (liste->premier);
		liste -> premier = nouveau;
	};


struct Liste* Liste_initialisation (){
	Liste *liste = malloc(sizeof(*liste));
	Element *element = malloc(sizeof(*element));
	if ((liste == NULL) || (element == NULL)){
		exit(EXIT_FAILURE);
	}
	//element -> nombre =0;
	element -> suivant = NULL;
	liste -> premier = element;
return liste;
};

int depiler(struct Liste *liste){
	if (liste ==NULL){
		exit(EXIT_FAILURE);
	}
	Element *actuel = liste -> premier;
	while (actuel != NULL){
		printf("%d -> ", actuel -> nombre);
		actuel = actuel -> suivant;
	}
	printf ("NULL\n");
}


int main (){
	struct Liste* liste;
	liste=Liste_initialisation();

	
	int nvNombre;
	printf ("Nombre a empiler \n");
	scanf("%d", &nvNombre);
	
	Empiler(nvNombre, liste);

	int nvNombre2;
	printf ("Nombre a empiler \n");
	scanf("%d", &nvNombre2);
	
	Empiler(nvNombre2, liste);

	depiler(liste);
		
return 0;
};
