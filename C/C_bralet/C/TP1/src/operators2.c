#include <stdio.h>

int main() {
	int a = 15;
	int b = 13;
	char operator = '%';
	switch((int) operator) {
		case (int) '+' : printf("somme = %d\n", a+b);break;
		case (int) '-' : printf("différence = %d\n", a-b);break;
		case (int) '*' : printf("produit = %d\n", a*b);break;
		case (int) '/' : printf("quotient = %f\n", (float) a/b);break;
		case (int) '%' : printf("module = %d\n", a%b);break;
		case (int) '!' : printf("négation = %d\n", !a);break;
		case (int) '&' : printf("et logique = %d\n", a&&b);break;
		case (int) '|' : printf("ou logique = %d\n", a||b);break;
	}
}
