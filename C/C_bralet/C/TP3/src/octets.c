#include <stdio.h>

int main() {
	short a = 12;
	int b = 50;
	long int c = 1024;
	float d = 20.3;
	double e = 5603.31;
	long double f = 208.12;

	char *pt1 = (char*)&a;
	char *pt2 = (char*)&b;
	char *pt3 = (char*)&c;
	char *pt4 = (char*)&d;
	char *pt5 = (char*)&e;
	char *pt6 = (char*)&f;

	int i;
	printf("short\n");
	for(i = 0; i < sizeof(short); i++) {
		printf("octet n°%d = 0x%hhx\n", i+1, *pt1);
		pt1++;
	}

	printf("int\n");
	for(i = 0; i < sizeof(int); i++) {
		printf("octet n°%d = 0x%hhx\n", i+1, *pt2);
		pt2++;
	}

	printf("long int\n");
	for(i = 0; i < sizeof(long int); i++) {
		printf("octet n°%d = 0x%hhx\n", i+1, *pt3);
		pt3++;
	}

	printf("float\n");
	for(i = 0; i < sizeof(float); i++) {
		printf("octet n°%d = 0x%hhx\n", i+1, *pt4);
		pt4++;
	}

	printf("double\n");
	for(i = 0; i < sizeof(double); i++) {
		printf("octet n°%d = 0x%hhx\n", i+1, *pt5);
		pt5++;
	}

	printf("long double\n");
	for(i = 0; i < sizeof(long double); i++) {
		printf("octet n°%d = 0x%hhx\n", i+1, *pt6);
		pt6++;
	}

	return(0);
}