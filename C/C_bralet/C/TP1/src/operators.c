#include <stdio.h>

int main() {
	int a = 16;
	int b = 3;

	printf("somme = %d\n", a+b);
	printf("différence = %d\n", a-b);
	printf("produit = %d\n", a*b);
	printf("quotient = %f\n", (float) a/b);
	printf("module = %d\n", a%b);
	printf("négation = %d\n", !a);
	printf("et logique = %d\n", a&&b);
	printf("ou logique = %d\n", a||b);
}
