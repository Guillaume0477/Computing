#include <stdio.h>

int main() {
	int count = 15;
	int i;
	int k;
//Avec des for
	for (i = 1; i < count; i++) { //parcours des lignes
		for(k = 0; k < i; k++) { //parcours des colonnes
			if (k == 0) {
				printf("*");
			} else if (k == i - 1) {
				printf("*");
			} else {
				printf("#");
			}
		}
	printf("\n");
	}
	for (i = 1; i <= count; i++) {
		printf("*");
	}
	printf("\n");

//Avec des while
	i = 1;
	while (i < count) {//parcours des lignes
		k = 0;
		while (k < i) {//parcours des colonnes
			if (k == 0) {
				printf("*");
			} else if (k == i - 1) {
				printf("*");
			} else {
				printf("#");
			}
		k++;
		}
	printf("\n");
	i++;
	}
	i = 1;
	while (i <= count) {
		printf("*");
	i++;
	}
	printf("\n");

//Avec des Do...while
	i = 1;
	do {
		k = 0;
		do {
			if (k == 0) {
				printf("*");
			} else if (k == i - 1) {
				printf("*");
			} else {
				printf("#");
			}
		k++;
		} while (k < i); //parcours des colonnes
	printf("\n");
	i++;
	} while (i < count); //parcours des lignes
	i = 1;
	do {
		printf("*");
	i++;
	} while (i <= count);
	printf("\n");

}
