#include <stdio.h>

int main() {
	char prenom[5][30] = {"Pierre", "Paul", "Jacques", "Pierrette","Paulette"};
	char nom[5][30] = {"Dupont","Martin","Ricoud","Brelan","Quinte"};
	char adresse[5][100] = {"6 Avenue Paul Bert", "23 Rue du pont de l'art", "89 Boulevard Thiers", "74 Ruelle des Charmettes", "11 Route de Vienne"};
	int note1[5] = {1,4,8,2,9};
	int note2[5] = {18,13,4,17,12};

	int i;

	for(i=0; i < 5;i++){
		printf("%s %s adresse : %s, note PC : %i, note SE : %i\n", prenom[i], nom[i], adresse[i], note1[i], note2[i]);
	}
return(0);
}
