#include <stdio.h>
#include <string.h>
#include "liste.h"
#include <stdlib.h>

int main(int argc, char **argv){
	struct liste_couleurs couleur1,couleur2,couleur3,couleur4,couleur5,couleur6,couleur7,couleur8,couleur9,couleur10;
	struct liste_couleurs *cptrprem = &couleur1;
	struct liste_couleurs *cptrder = &couleur10;


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

	couleur1.rouge = 0x45;
	couleur1.vert = 0x56;
	couleur1.bleu = 0x67;
	couleur2.rouge = 0x23;
	couleur2.vert = 0x34;
	couleur2.bleu = 0x54;
	couleur3.rouge = 0x63;
	couleur3.vert = 0x43 ; 
	couleur3.bleu = 0x23;
	couleur4.rouge = 0x53 ;
	couleur4.vert = 0x98;
	couleur4.bleu = 0x89;
	couleur5.rouge = 0xab; 
	couleur5.vert = 0xff; 
	couleur5.bleu = 0x32;
	couleur6.rouge = 0x4e;
	couleur6.vert = 0xc4; 
	couleur6.bleu = 0x74;
	couleur7.rouge = 0xcd; 
	couleur7.vert = 0x8e; 
	couleur7.bleu = 0x25;
	couleur8.rouge = 0xaa;
	couleur8.vert = 0xba; 
	couleur8.bleu = 0x95;
	couleur9.rouge = 0xbd; 
	couleur9.vert = 0x42 ;
	couleur9.bleu = 0x13;
	couleur10.rouge = 0xff;
	couleur10.vert = 0xfa; 
	couleur10.bleu = 0x42;

	int choix;
	int r;
	int v;
	int b;
	unsigned char rouge;
	unsigned char vert;
	unsigned char bleu;

	while (1){

		printf("\nPour lire taper 1. Pour inserer tapez 2. Pour finir tapez 0\n");

		scanf("%d", &choix);
		printf("\n");

		if (choix == 1){
			parcours(cptrprem);
		} else if (choix == 2) {
			printf("Rouge\n");
			scanf("%x", &r);
			printf("Vert\n");
			scanf("%x", &v);
			printf("Bleu\n");
			scanf("%x", &b);
			struct couleur insert;
			insert.rouge = r;
			insert.vert = v;
			insert.bleu = b;
			insertion(&insert, cptrder);
			cptrder = (*cptrder).next;
		} else if (choix == 0) {
			break;
		} else { 
			printf("Choix incorrect");
		}

	}
	
	while (cptrder != &couleur10) {
		cptrder = (*cptrder).prev;
		free((*cptrder).next);			
	}	
	return(0);
}

void insertion (struct couleur *couleur, struct liste_couleurs *liste) {

	struct liste_couleurs *nouveau = malloc(sizeof(struct liste_couleurs));
	
	(*nouveau).rouge = (*couleur).rouge;
	(*nouveau).vert = (*couleur).vert;
	(*nouveau).bleu = (*couleur).bleu;
	
	(*liste).next = nouveau;
	(*nouveau).prev = liste;
	(*nouveau).next = NULL;
}

void parcours (struct liste_couleurs *liste){
	while (liste != NULL) {
		printf("0x%x 0x%x 0x%x \n",(*liste).rouge,(*liste).vert,(*liste).bleu);
		liste = (*liste).next;
	}
}
