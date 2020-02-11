#include <stdio.h>
#include <math.h>

int main() {
	int num = 1024; //valeur a mettre en binaire
	long long int bin = 0; //valeur de sortie en binaire

	int puissance = 0;
	int i;
	for (i = num ; i >0 ;) {
		if (i%2 == 0) { //test si le bit de poid faible de i est nul
			i /= 2;
		} else { //sinon on ajoute la puissance de 10 correspondante dans bin
			bin += pow(10, puissance);
			i -=1;
			i /=2;
		}
		puissance++;
	}
	
	printf("%d est codé en binaire par %lld\n", num, bin);
}
