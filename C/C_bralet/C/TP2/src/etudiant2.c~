#include <stdio.h>
#include <string.h>

int main() {

	struct etudiant {
		char prenom[30];
		char nom[30];
		char adresse[100];
		struct note {
			int PC;
			int SE;
		} note;
	};
	
	struct etudiant CPE[5];

	strcpy(CPE[0].prenom, "Pierre");
	strcpy(CPE[0].nom, "Dupont");
	strcpy(CPE[0].adresse, "6 Avenue Paul Bert");
	CPE[0].note.PC = 1;
	CPE[0].note.SE = 18;
	
	strcpy(CPE[1].prenom, "Paul");
	strcpy(CPE[1].nom, "Martin");
	strcpy(CPE[1].adresse, "23 Rue du pont de l'art");
	CPE[1].note.PC = 4;
	CPE[1].note.SE = 13;

	strcpy(CPE[2].prenom, "Jacques");
	strcpy(CPE[2].nom, "Ricoud");
	strcpy(CPE[2].adresse, "89 Boulevard Thiers");
	CPE[2].note.PC = 8;
	CPE[2].note.SE = 4;
	
	strcpy(CPE[3].prenom, "Pierrette");
	strcpy(CPE[3].nom, "Brelan");
	strcpy(CPE[3].adresse, "74 Ruelle des Charmettes");
	CPE[3].note.PC = 2;
	CPE[3].note.SE = 17;

	strcpy(CPE[4].prenom, "Paulette");
	strcpy(CPE[4].nom, "Quinte");
	strcpy(CPE[4].adresse, "11 Route de Vienne");
	CPE[4].note.PC = 9;
	CPE[4].note.SE = 12;

	int i;

	for(i=0; i < 5;i++){
		printf("%s %s adresse : %s, note PC : %i, note SE : %i\n", CPE[i].prenom, CPE[i].nom, CPE[i].adresse, CPE[i].note.PC, CPE[i].note.SE);
	}
return(0);
}
