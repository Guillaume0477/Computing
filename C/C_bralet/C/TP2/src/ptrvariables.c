#include <stdio.h>

int main() {
	char caract;
	short a;
	int b;
	long int c;
	long long int d;
	float e;
	double f;
	long double g;
	unsigned char h;
	unsigned short i;
	unsigned int j;
	unsigned long int k;
	unsigned long long int l;

	char *pt1 = &caract;
	short *pt2 = &a;
	int *pt3 = &b;
	long int *pt4 = &c;
	long long int *pt5 = &d;
	float *pt6 = &e;
	double *pt7 = &f;
	long double *pt8 = &g;
	unsigned char *pt9 = &h;
	unsigned short *pt10 = &i;
	unsigned int *pt11 = &j;
	unsigned long int *pt12 = &k;
	unsigned long long int *pt13 = &l;

	*pt1 = 'f';
	*pt2 = -1;
	*pt3 = -2;
	*pt4 = -34L;
	*pt5 = -64LL;
	*pt6 = 36.25;
	*pt7 = 3.1E-12;
	*pt8 = 2.6E-22;
	*pt9 = 235;
	*pt10 = 12;
	*pt11 = 4000;
	*pt12 = 23UL;
	*pt13 = 65ULL;

	printf("char = %c adresse = %p\n", caract, pt1);
	printf("short = %hd adresse = %p\n", a, pt2);
	printf("int = %d adresse = %p\n", b, pt3);
	printf("long int = %ld adresse = %p\n", c, pt4);
	printf("long long int = %lld adresse = %p\n", d, pt5);
	printf("float = %f adresse = %p\n", e, pt6);
	printf("double = %g adresse = %p\n", f, pt7);
	printf("long double = %Lg adresse = %p\n", g, pt8);
	printf("unsigned char = %hhu adresse = %p\n", h, pt9);
	printf("unsigned short = %hu adresse = %p\n", i, pt10);
	printf("unsigned int = %u adresse = %p\n", j, pt11);
	printf("unsigned long int = %lu adresse = %p\n", k, pt12);
	printf("unsigned long long int = %llu adresse = %p\n", l, pt13);

	return(0);
}
