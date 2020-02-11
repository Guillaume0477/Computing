#include <stdio.h>
#include "operator.h"

int main() {
	int num1 = 15;
	int num2 = 13;
	char operator = '/';
	switch((int) operator) {
		case (int) '+' : printf("somme = %d\n", somme(num1,num2));break;
		case (int) '-' : printf("différence = %d\n", difference(num1,num2));break;
		case (int) '*' : printf("produit = %d\n", produit(num1,num2));break;
		case (int) '/' : printf("quotient = %f\n", quotient(num1,num2));break;
		case (int) '%' : printf("module = %d\n", modulus(num1,num2));break;
		case (int) '!' : printf("négation = %d\n", negation(num1));break;
		case (int) '&' : printf("et logique = %d\n", etlogique(num1,num2));break;
		case (int) '|' : printf("ou logique = %d\n", oulogique(num1,num2));break;
	}
	return(0);
}

int somme(int a,int b){
	return a+b;
}

int difference(int a,int b){
	return a-b;
}

int produit(int a,int b){
	return a*b;
}

float quotient(int a,int b){
	return (float) a/b;
}

int modulus(int a,int b){
	return a%b;
}

int etlogique(int a,int b){
	return a&&b;
}

int oulogique(int a,int b){
	return a||b;
}

int negation(int a){
	return !a;
}


