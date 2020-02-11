#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

int main() {
	//Initialisation de la pile
	struct pile mpile;
	mpile.nombre = 0;
	mpile.next = NULL;	
	int nombre;
	int choix;
	
	//Commandes utilisateur
	while (1){
		printf("Que voulez vous faire ? 1 pour empiler, 2 pour dépiler, 0 pour terminer\n");
		scanf("%d",&choix);
		if (choix == 1) {
			printf("Quel est le nombre à empiler ?\n");
			scanf("%d",&nombre);
			empiler(nombre,&mpile);
		} else if (choix == 2 && mpile.next != NULL) {
			nombre = depiler(&mpile);
			printf("%d\n", nombre);
		} else if (choix == 0) {
			break;
		}
	}
	return(0);
}

void empiler(int nombre, struct pile *ptr){
	//Création d'une nouvelle structure et stockage du nombre dans celle ci
	//On met la nouvelle structure au dessus de la pile (remplacement du next du dernier par l'adresse du nouveau)
	struct pile *nouveau = malloc(sizeof(struct pile));
	struct pile *ptrfin = ptr;
	while ((*ptrfin).next != NULL) {
		ptrfin = (*ptrfin).next;
	} 	
	
	(*nouveau).nombre = nombre;
	(*nouveau).next = NULL;
	(*ptrfin).next = nouveau;
	

}


int depiler(struct pile *ptr){
	//Accès à la dernière structure, isolation du nombre puis libération de la mémoire allouée
	//On passe à NULL le next du nouveau dernier élément.
	struct pile *ptrfin = ptr;
	struct pile *ptravant = ptr;
	int nombre;

	while ((*ptrfin).next != NULL) {
		ptravant = ptrfin;
		ptrfin = (*ptravant).next;
	}
	
	(*ptravant).next = NULL;
	nombre = (*ptrfin).nombre;
	free(ptrfin);
	return(nombre);
}
