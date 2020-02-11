#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichiers.h"


	void LECTURE_FICHIER(char *monfichier){
		FILE* fichier = NULL;
		char caractere;
		fichier = fopen(monfichier,"r"); //On ouvre le fichier en mode lecture
		do
		{	caractere = fgetc(fichier); //On lit le caractère
			printf("%c",caractere); //On affiche le  caractère
		} while (caractere != EOF); //On continue tant que l'on n'est pas à la fin du fichier
		fclose(fichier); //Fermeture du fichier
	}

	void ECRITURE_FICHIER(char *monfichier, char *message){
		FILE* fichier = NULL;
		fichier = fopen(monfichier,"a+"); //On ouvre le fichier en mode écriture
		fprintf(fichier,message); //On écrit dans le fichier sans écraser le texte existant
		fclose(fichier); //Fermeture du fichier
	}
	
struct adresse {
	char numero[5];
	char type_voie[50];
	char nom_voie[50];
	char ville[50];
};
				
struct etudiant{ // Déclaration de la structure etudiant
	char nom[12],prenom[12];
	struct adresse adr;
	int notes1,notes2;
};

int main(){
	int i,notes10,notes20;
	char nom1[12],prenom1[12],numero[5],type_voie[50],nom_voie[50],ville[50]; //Déclaration des variables.
     	
struct etudiant etudiant1;
	for(i=0; i<5;i++){
		printf("Saisir le nom : \n");
		scanf("%s",nom1); //On récupere le nom
		strcpy(etudiant1.nom,nom1);

		printf("Saisir le prénom : \n");
		scanf("%s",prenom1); //On récupere le prénom
		strcpy(etudiant1.prenom,prenom1);

		printf("Saisir le numéro de rue : \n"); // On utilise cette méthode pour renseigner l'addresse car SCANF ne prend pas en compte les espaces.
		scanf("%s",numero); //On récupere l'adresse
		strcpy(etudiant1.adr.numero,numero);
		printf("Saisir le type de voie : \n"); 
		scanf("%s",type_voie); //On récupere l'adresse
		strcpy(etudiant1.adr.type_voie,type_voie);
		printf("Saisir le nom de la voie : \n"); 
		scanf("%s",nom_voie); //On récupere l'adresse
		strcpy(etudiant1.adr.nom_voie,nom_voie);
		printf("Saisir la ville : \n"); 
		scanf("%s",ville); //On récupere l'adresse
		strcpy(etudiant1.adr.ville,ville);
		
		printf("Saisir la note 1 : \n");
		scanf("%d",&notes10); //On récupere la note 1
		etudiant1.notes1 = notes10;

		printf("Saisir la note 2 : \n");
		scanf("%d",&notes20); //On récupere la note 2
		etudiant1.notes2 = notes20;
		
		char str[512]; //On crée une chaine de 512 caractères
		sprintf(str,"%s, %s, %s %s %s %s, %d, %d.\n", etudiant1.nom, etudiant1.prenom, etudiant1.adr.numero, etudiant1.adr.type_voie, etudiant1.adr.nom_voie, etudiant1.adr.ville, etudiant1.notes1, etudiant1.notes2); //On concatène les caratères dans str
		printf("%sajouté au fichier etudiant.txt\n",str);
		ECRITURE_FICHIER("etudiant.txt",str); //On écrit la nouvelle ligne dans le document souhaité.
}
	LECTURE_FICHIER("etudiant.txt"); //On affiche le résultat
	
return(0);
}
