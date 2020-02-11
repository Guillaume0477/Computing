#include <stdio.h>
#include <math.h>

int main() {
	//aire d'un cercle
	float rayon = 3;
	printf("L'aire d'un cercle de rayon %f est %f\n", rayon, M_PI*pow(rayon,2.0));

	//perimetre d'un cercle
	printf("Le périmétre d'un cercle de rayon %f est %f\n", rayon, 2*M_PI*rayon);
}
