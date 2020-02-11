#include <stdio.h>

int factorielle (int num) {
	if (num==0){
		return(1);
	}
	else {
		return(num * factorielle(num-1));
	}
}

int main (int argc, char **argv){
	int nombre = atoi(argv[1]);
	printf("la factorielle de %d est %d\n",nombre, factorielle(nombre));
	return(0);
}
