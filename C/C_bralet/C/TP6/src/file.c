#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main() {
	//Initialisation de la file
	struct file mfile;
	mfile.nombre = 0;
	mfile.next = NULL;
	mfile.prev = NULL;
	int nombre;
	int choix;

	//Commandes utilisateur	
	while (1){
		printf("Que voulez vous faire ? 1 pour enfiler, 2 pour défiler, 0 pour terminer\n");
		scanf("%d",&choix);
		if (choix == 1) {
			printf("Quel est le nombre à enfiler ?\n");
			scanf("%d",&nombre);
			enfiler(nombre,&mfile);
		} else if (choix == 2 && mfile.next != NULL) {
			nombre = defiler(&mfile);
			printf("%d\n", nombre);
		} else if (choix == 0) {
			break;
		}
	}
	return(0);
}

void enfiler(int nombre, struct file *ptr){
	//Création d'une nouvelle structure et stockage du nombre dans celle ci
	//On met la nouvelle structure au dessus de la file (remplacement du next du dernier par l'adresse du nouveau)
	struct file *nouveau = malloc(sizeof(struct file));
	struct file *ptrfin = ptr;
	while ((*ptrfin).next != NULL) {
		ptrfin = (*ptrfin).next;
	} 	
	
	(*nouveau).nombre = nombre;
	(*nouveau).next = NULL;
	(*nouveau).prev = ptrfin;
	(*ptrfin).next = nouveau;
	

}


int defiler(struct file *ptr){
	//Accès à la première structure, isolation du nombre puis libération de la mémoire allouée
	//On raccorde ensuite le next et le previous du nouveau premier de file
	int nombre;
	nombre = (*(*ptr).next).nombre;
	if ((*(*ptr).next).next != NULL) {
		(*ptr).next = (*(*ptr).next).next;
		free((*(*ptr).next).prev);
		(*(*ptr).next).prev = ptr;
	} else {
		free((*ptr).next);
		(*ptr).next = NULL;
	}
	return(nombre);
}
