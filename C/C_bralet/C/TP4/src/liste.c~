#include <stdio.h>
#include <string.h>
#include "liste.h"

int main(int argc, char **argv){
	struct liste_couleurs couleur1,couleur2,couleur3,couleur4,couleur5,couleur6,couleur7,couleur8,couleur9,couleur10;
	struct liste_couleurs *cptr = &couleur1;

	couleur1.next = &couleur2;
	couleur1.prev = NULL;
	couleur2.next = &couleur3;
	couleur2.prev = &couleur1;
	couleur3.next = &couleur4;
	couleur3.prev = &couleur2;
	couleur4.next = &couleur5;
	couleur4.prev = &couleur3;
	couleur5.next = &couleur6;
	couleur5.prev = &couleur4;
	couleur6.next = &couleur7;
	couleur6.prev = &couleur5;
	couleur7.next = &couleur8;
	couleur7.prev = &couleur6;
	couleur8.next = &couleur9;
	couleur8.prev = &couleur7;
	couleur9.next = &couleur10;
	couleur9.prev = &couleur8;
	couleur10.next = NULL;
	couleur10.prev = &couleur9;

	couleur1.rouge, couleur1.vert, couleur1.bleu = 0x45,0x56,0x67;
	couleur2.rouge, couleur2.vert, couleur2.bleu = 0x46,0x56,0x67;
	couleur3.rouge, couleur3.vert, couleur3.bleu = 0x23,0x56,0x67;
	couleur4.rouge, couleur4.vert, couleur4.bleu = 0x89,0x56,0x67;
	couleur5.rouge, couleur5.vert, couleur5.bleu = 0x32,0x56,0x67;
	couleur6.rouge, couleur6.vert, couleur6.bleu = 0x74,0x56,0x67;
	couleur7.rouge, couleur7.vert, couleur7.bleu = 0x25,0x56,0x67;
	couleur8.rouge, couleur8.vert, couleur8.bleu = 0x95,0x56,0x67;
	couleur9.rouge, couleur9.vert, couleur9.bleu = 0x13,0x56,0x67;
	couleur10.rouge, couleur10.vert, couleur10.bleu = 0x42,0x56,0x67;

	int choix;
	unsigned char rouge;
	unsigned char vert;
	unsigned char bleu;
	printf("Pour lire taper 1. Pour inserer tapez 2.");
	scanf("%d", &choix);
	
	if (choix == 1){
		parcours(cptr);
	} else if (choix == 2) {
		printf("Rouge");
		scanf("%hhu", &rouge);
		printf("Vert");
		scanf("%hhu", &vert);
		printf("Bleu");
		scanf("%hhu", &bleu);
		struct couleur insert;
		strcpy(*insert.rouge, rouge);
		strcpy(*insert.vert, vert);
		strcpy(*insert.bleu, bleu);
		insertion(insert, cptr);
	} else { 
		printf("Choix incorrect");
		return(1);
	}
	return(0);
}
/*
void insertion (struct couleur *couleur, struct liste_couleurs *liste) {
	
}

void parcours (struct liste_couleurs *liste){

}*/
