#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	int nbrcar = 1000;
	char contenu[nbrcar];
	int fd,size;
	char *phrase = argv[1];
	char *pt = contenu;
	char *ptp = phrase;
	char *k = pt;
	int l = 1;
	int count[nbrcar];
	int nbr = 0;

	fd = open(argv[2], O_RDONLY);
	size = read(fd, contenu, nbrcar);

	while (k - pt < nbrcar) {
		if (*k == '\n') {
			l++;
			ptp = phrase;
		} else if (*k == *ptp) {
			ptp++;
			if (*ptp == 0) {
				count[nbr] = l;
				nbr++;
				ptp = phrase;
			}
		} else {
			ptp = phrase;
		}
		k++;
	}
	
	int i;
	int j = 1;
	for (i = 0; i < nbr-1; i++) {
		if (count[i] == count[i + 1]) {
			j++;
		} else {
			printf("Ligne %d : %d\n", count[i], j);
			j = 1;
		}
	}
	close(fd);
	return(0);
}
