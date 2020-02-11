#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "repertoire.h"


int main(int argc, char **argv) {
	//lire_dossier(argv[1]);		// A décommenter pour faire fonctionner la question 2
	//lire_dossier_recursif(argv[1]); //A décommenter pour faire fonctionner la question 3
	lire_dossier_iteratif(argv[1]);  //A décommenter pour faire fonctionner la question 5
	return(0);
}

void lire_dossier(char *nom){
	DIR *dirp = opendir(nom);
	struct dirent *dir = readdir(dirp);
	while (dir != NULL) {
		printf("%s\n", dir->d_name);
		dir = readdir(dirp);
	}
}

void lire_dossier_recursif(char *nom) {
	DIR *dirp = opendir(nom);
	struct dirent *dir = readdir(dirp);
	while (dir != NULL) {
		if ((dir->d_type == DT_DIR) && strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")){
			printf("Ceci est un dossier : %s (Fin de dossier au prochain '..')\n", dir->d_name);
			strcat(nom, "/");
			lire_dossier_recursif(strcat(nom, dir->d_name));
			dir = readdir(dirp);
		} else {
			printf("%s\n", dir->d_name);
			dir = readdir(dirp);
		}
	}
}

void lire_dossier_iteratif(char *nom){
	int i = 0;
	int j = 1; //hauteur de l'arborescence
	char tableau[100][256];
	char *nom1 = nom;
	DIR *dirp;
	struct dirent *dir;

	strcpy(tableau[0], nom);
	
	while (i != j) {
		dirp = opendir(tableau[i]);
		dir = readdir(dirp);
		while (dir != NULL) {
			if ((dir->d_type == DT_DIR) && strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..")){
				nom1 = tableau[i];
				printf("Ceci est un dossier : %s\n", dir->d_name);
				strcat(nom1, "/");
				strcpy(tableau[j], strcat(nom1,dir->d_name));
				j++;
				dir = readdir(dirp);
			} else {
				printf("%s\n", dir->d_name);
				dir = readdir(dirp);
			}
		}
		i++;
	}
	
}
