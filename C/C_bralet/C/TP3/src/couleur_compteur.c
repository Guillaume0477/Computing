#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Définition de la structure des couleurs
typedef struct trieur {
	char couleur[30];
	int cpt;
} trieur;

int compte_couleur(char *couleur, trieur *colors, int *def) {
	/*Fonction permettant de comparer la couleur entrée en argument et la structure colors
	Si la couleur est déjà présente, le compteur s'incrémente.
	Si la couleur n'est pas présente, on ajoute la couleur à la structure et on incrémente le compteur.
	Paramètres entrée
		- couleur : chaine de caractère représentant une couleur
	 	- colors : structure comprenant l'ensemble des couleurs déjà enregistrées
	 	- def : nombre de couleurs déjà enregistrées
	*/

	int i;	//Parcours les éléments de la structure
	
	//Recherche si la couleur a déjà été enregistrée
	for (i = 0; i <= *def; i++) {
		//Cas où i est égal à def : la couleur n'est pas encore enregitrée dans la structure
		if (i == *def) {
			//Ajout de la couleur dans la structure
			strcpy(colors[*def].couleur, couleur);
			//Incrémentation du compteur
			colors[*def].cpt = 1;
			//Incrémentation du nombre de couleur total
			(*def)++;
			break;
		}
		//Cas où on toruve la couleur dans la structure
		if (strcmp(couleur, colors[i].couleur) == 0) {
			//Incrémentation du compteur correspondant
			colors[i].cpt++;
			break;
		}
	}
	return(0);
}

int main(){
	int i = 0;	//Parcours les éléments de la structure
	int def = 0;	//Nombre total de couleurs dans le tableau
	int size;	//taille de l'élément capturé
	size_t capt_size = 30;	//taille maximale acceptable
	char *capture = malloc(capt_size);	//alloue une mémoire dynamique pour les chaines de caractères rentrées par l'utilisateur

	trieur colors[100];	//Création de la structure
	printf("Entrez votre couleur (Entrer pour l'enregistrer, FIN pour terminer)\n");
	//Capture de la chaine de caractère entrée par l'utiisateur tant que celui ci n'a pas écrit FIN
	while (strcmp(capture, "FIN") != 0){
		//Capture de la chaine de caractère et détermination de la taille
		size = getline(&capture, &capt_size, stdin);
		//Actualisation de la chaine de caractère (le \n est remplacé par un \0 pour finir la chaine)
		capture[size - 1] = '\0';

		//Si l'utilisateur rentre le mot FIN, on arete le processus
		if (strcmp(capture, "FIN") != 0) {
			compte_couleur(capture, colors, &def);
		}
	}
	//affichage des couleurs et de leur nombre
	for (i = 0; i < def; i++) {
		printf("%s , %d\n", colors[i].couleur, colors[i].cpt);
	}
	
	//Libération de l'espace mémoire pris par la chaine de caractère utilisateur
	free(capture);
	return(0);
}
