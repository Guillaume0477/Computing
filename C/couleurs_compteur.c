#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fichiers.h"

struct couleurs{ // Déclaration de la structure couleur
	char rouge[10]; // On utilise char car chaque valeur est un octet
	char vert[10];
	char bleu[10];
	char alpha[10];
	int compteur;
};

void remplit_couleurs(struct couleurs* RGBA, char* ligne){ //void = fonction qui ne renvoi pas de résultats
	char* valeur; //Création d'un pointeur sur un caracètre : Je pointe l'adresse sur ce caracètre
	char* copieligne = malloc(strlen(ligne)); //Crée un espace mémoire pour la chaine de caractères copieligne (!= char copieligne[] qui est stocké dans la pile)
	
	strcpy(copieligne,ligne); //On copie la ligne
	valeur = strtok(copieligne," "); //Selectionne les caractères entre chaque " "
	if (valeur != NULL){
		strcpy(RGBA->rouge,valeur); //Permet l'accès aux attributs d'un pointeur sur une structure ( <=> *RGBA.rouge = valeur)
	}
	
	valeur = strtok(NULL," ");
	if (valeur != NULL){
		strcpy(RGBA->vert,valeur);
	}
	
	valeur = strtok(NULL," ");
	if (valeur != NULL){
		strcpy(RGBA->bleu,valeur);
	}
	
	valeur = strtok(NULL," ");
	if (valeur != NULL){
		strcpy(RGBA->alpha,valeur);
	}
	free(copieligne); //On détruit copieligne
	RGBA->compteur = 1; //Initialisation du compteur
}

int contain(struct couleurs* RGBA,int taille, char* ligne){//fonction qui renvoi un entier
	char* rouge; 
	char* vert;
	char* bleu;
	char* alpha; 
	char* copieligne = malloc(strlen(ligne));
	
	strcpy(copieligne,ligne); //On copie la ligne
	rouge = strtok(copieligne," "); //Selectionne les caractères entre chaque " "
	vert = strtok(NULL," "); //NULL car garde le dernier paramètre lors du dernier appel de la fonction
	bleu = strtok(NULL," ");
	alpha = strtok(NULL," ");
	
	if (rouge == NULL || vert == NULL || bleu == NULL || alpha == NULL){ //Test si une des 4 valeurs est NULL
		free(copieligne); //On détruit copieligne
		return(-1);
	}
	
	int z = 0;
	int sucess;
	
	sucess = strcmp(RGBA->rouge,rouge) == 0
		&& strcmp(RGBA->vert,vert) == 0
		&& strcmp(RGBA->bleu,bleu)== 0
		&& strcmp(RGBA->alpha,alpha) == 0; //On compare si les valeurs renseignées sont contenus dans la structure RGBA ou non.
	
	while(!sucess && z < taille){
		z++;
		sucess = strcmp(RGBA->rouge,rouge) == 0
			&& strcmp(RGBA->vert,vert) == 0
			&& strcmp(RGBA->bleu,bleu)== 0
			&& strcmp(RGBA->alpha,alpha) == 0;
	}
	
	free(copieligne); //On détruit copieligne
	if(sucess){ // On check si la ligne est déjà dans la tableau
		return z;
	}else{ // On check si la ligne n'est pas déjà dans la tableau
		return -1; 
	}
}

int main() {
	FILE* fichier = fopen("couleurs.txt","w"); //Ouverture du fichier en mode écriture
	
	int compteur = 0;
	char *ligne = malloc(20); //Lecture de la ligne.
	size_t taille = 20;
	
	fgets(ligne,taille,stdin);
	
	while(strcmp(ligne,"FIN\n") != 0 ){ // On test si l'utilisateur rentre FIN
		fprintf(fichier,ligne);
		fgets(ligne,taille,stdin); //On récupère la ligne de couleur renseigné par l'utilisateur
		compteur++;
	}
	fclose(fichier);
	
	fichier = fopen("couleurs.txt","r"); //Ouverture du fichier en mode lecture
	struct couleurs cRGBA[compteur];
	
	int i = 0;

	while(getline(&ligne,&taille,fichier) != -1 ){  // On remplit la structure
		ligne[strlen(ligne)-1] = '\0'; //Suppression de '\n' que l'on récupère dans chaque ligne
		int contient = contain(cRGBA,compteur,ligne);
		if(contient == -1){ // On check si la ligne n'est pas déjà dans la tableau
			remplit_couleurs(&cRGBA[i],ligne);
			i++;		
		}else{
			cRGBA[contient].compteur++; //On accède à l'attribut compteur de la structure RGBA
		}
	}	

	int j = 0;
	while(j < i){ //On affiche la structure
		printf("%s %s %s %s %d\n",cRGBA[j].rouge,cRGBA[j].vert,cRGBA[j].bleu,cRGBA[j].alpha,cRGBA[j].compteur);
		j++;
	}
	
return(0);
}