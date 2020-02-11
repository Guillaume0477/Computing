#include <stdio.h>
#include <stdlib.h>

int main() {

	int tableau1[5];
	float tableau2[5];
	int *ptr1 = &tableau1[0];
	float *ptr2 = &tableau2[0];
	
	int i;	
	int cpt = 0;
	

	//Creation des tableaux
	for(i=0;i<sizeof tableau1 / sizeof(int) ; i++) {
		tableau1[i] =  rand()/1000;
		tableau2[i] = rand()/1000;
	}
	
	//Manipulation ds tableaux
	while (cpt != sizeof tableau1/sizeof(int)){
		if (cpt%2 == 0) { //teste si l'indice est divisible par 2 ou non
			printf("%i: int avant = %i\n", cpt, tableau1[cpt]);
			*(ptr1 + cpt) *= 3;
			printf("%i: int apres = %i\n", cpt, tableau1[cpt]);
			printf("%i: float avant = %f\n", cpt, tableau2[cpt]);
			*(ptr2 + cpt) *= 3;
			printf("%i: float apres = %f\n", cpt, tableau2[cpt]);
		}
		cpt++;	//Actualisation du compteur
	}

	return(0);
}
