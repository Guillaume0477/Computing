#include <stdio.h>

int main() {
	char caract = 'f';
	short a = -1;
	int b = -2;
	long int c = -34L;
	long long int d = -68LL;
	float e = 36.25;
	double f = 5.4E-12;
	long double g = 1.53E-22;
	unsigned char h = 234;
	unsigned short i = 65;
	unsigned int j = 4687;
	unsigned long int k = 87UL ;
	unsigned long long int l = 51ULL ;

	printf("char = %c\n", caract);
	printf("short = %hd\n", a);
	printf("int = %d\n", b);
	printf("long int = %ld\n", c);
	printf("long long int = %lld\n", d);
	printf("float = %f\n", e);
	printf("double = %g\n", f);
	printf("long double = %Lg\n", g);
	printf("unsigned char = %hhu\n", h);
	printf("unsigned short = %hu\n", i);
	printf("unsigned int = %u\n", j);
	printf("unsigned long int = %lu\n", k);
	printf("unsigned long long int = %llu\n", l);
}
