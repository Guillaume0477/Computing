#include <stdio.h>
#include <stdlib.h>

int main() {
	char phrase[300] = {"Salut toi tu vas comment toi"};
	char tableau[10][300] = {"Coucou comment ca va","Salut toi tu vas comment toi","Hey bonjour a tous", "Que dire que dire que dire", "tout ceci est incroyable", "je me demande ce que je pourrais ecrire", "mais que dire d autre", "qu il est difficile d etre le roi de la france", "comment vous dire tout ceci", "et voila c est fini"};

//------------------------------------------------------------------------------------------------------------------------------
// utilisation des pointeurs

	char *ptr = &tableau[0][0]; //pointeur de depart du tableau

	char *pt = &phrase[0];	// Pointeur qui va parcourir les caractere de la phrase
	char *k = ptr;	//pointeur qui va parcourir l'ensemble des caracteres du tableau

	while (k - ptr < sizeof(tableau) & *pt != 0) {	//teste si il y a encore des caractères dans le tableau et dans la phrase
		if (*pt == *k) {	//Si les caractere sont les meme, alors on teste le suivant
			pt++;
		} else {		//Sinon on recommence
			pt = &phrase[0];
		}
		k++;			//Actualisation du pointeur
	}
	
	//Teste si la phrase a bien ete trouvee et affichage
	if (*pt == 0) {
		printf("dans le tableau\n");
	} else {
		printf("pas dans le tableau\n");
	}
//------------------------------------------------------------------------------------------------------------------------------
//utilisation des indices

	int i;	//Parcours des phrases du tableau
	int j;	//Parcours des caracteres des phrases

	int booleen = 0;	// Determine si la phrase est dans le tableau ou non

	for (i = 0; i < sizeof(tableau)/sizeof(tableau[0]); i++){	//Parcours des phrases du tableau
		for (j=0; j < sizeof(phrase)/sizeof(char); j++){	//Parcours des caracteres de la phrase
			if (tableau[i][j] == phrase[j]){		//Teste si les caracteres sont egaux
				booleen = 1;	//Actualisation du booleen
			} else {	
				booleen = 0;	//Desactualisation du booleen
				break;
			}
		}
		//Une fois que la phrase est trouvee, on arrete de parcourir le tableau
		if (booleen == 1) { 
			break;
		}	
	}
	
	// Affichage de la reponse
	if (booleen == 1) {
		printf("%s est dans le tableau\n", phrase);
	} else { 
		printf("%s n'est pas dans le tableau\n", phrase);
	}


	return(0);
}
