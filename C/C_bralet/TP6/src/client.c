#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "client.h"

/* envoi et reception de message
 */
int envoie_recois_message(int socketfd) {
  char data[1024];
  memset(data, 0, sizeof(data));
  char message[1000];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, 1024, stdin);
  strcpy(data, "message: ");
  strcat(data, message);
  
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  memset(data, 0, sizeof(data));
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);
 
  return 0;
}

/* envoi et reception de calcul
 */
int envoie_operateur_numeros(int socketfd) {
  char data[1024];
  memset(data, 0, sizeof(data));
  
  char liste_dossier[100][256];
  int nombre_dossier = 0;
  int i,j,fd,size;
  char intermediaire[1024] = "";
  char liste_fichier[100][256];
  int nombre_fichiers = 0;
  char note[3];
  char liste_note[100][100][3];
  size_t taille = 1024;
  char *arborescence = malloc(taille);
  char ans[4] = "0";
  char total[2] ="00";

  printf("Arborescence du dossier contenant les fichiers\n");
  size = getline(&arborescence,&taille,stdin);
  arborescence[size-1] = '\0';
  
  //Recensement des dossiers
  DIR *dirp = opendir(arborescence);
  struct dirent *dir = readdir(dirp);
  while (dir != NULL) {
	if (strcmp(dir->d_name, ".") && strcmp(dir->d_name,"..")){
		strcpy(liste_dossier[nombre_dossier],dir->d_name);
		nombre_dossier++;
	}
	dir = readdir(dirp);
  }
  
  //Recensement des fichiers contenant les notes et stockage des notes dans un tableau
  for ( i = 0; i < nombre_dossier; i++){
	  nombre_fichiers = 0; 
	  strcpy(intermediaire,arborescence);
	  strcat(intermediaire,"/");
	  strcat(intermediaire,liste_dossier[i]);
	  dirp = opendir(intermediaire);
	  dir = readdir(dirp);
	  while (dir != NULL) {
		if (strcmp(dir->d_name, ".") && strcmp(dir->d_name,"..")){
			strcpy(liste_fichier[nombre_fichiers],dir->d_name);
			nombre_fichiers++;
		}
		dir = readdir(dirp);
	  }
	  printf("dossier: %s\n", liste_dossier[i]);
	  for (j = 0; j < nombre_fichiers; j++){
		  strcpy(intermediaire,arborescence);
		  strcat(intermediaire,"/");
		  strcat(intermediaire,liste_dossier[i]);
	  	  strcat(intermediaire,"/");
		  strcat(intermediaire, liste_fichier[j]);
	     	  fd = open(intermediaire,O_RDONLY);
		  read(fd, note, 2);
		  close(fd);
		  strcpy(liste_note[i][j],note);
		  printf("%s\n", liste_note[i][j]);
    	  }
	 
  }

  //Moyenne de chaque DS (à l'aide de l'appel au serveur pour le calcul)
  for ( i = 0; i < nombre_dossier; i++){
  	strcpy(ans, "0");
	for (j = 0; j < nombre_fichiers+1; j++){
		  strcpy(data, "calcul: ");
		  if (j == nombre_fichiers){
			strcat(data,"/ ");
			strcat(data, ans);
			strcat(data," ");
			sprintf(total, "%d", nombre_fichiers);
			strcat(data, total);
		  } else {
		  	strcat(data,"+ ");
			strcat(data, ans);
			strcat(data," ");
			strcat(data, liste_note[i][j]);
		  }
		  
		  int write_status = write(socketfd, data, strlen(data));
		  if ( write_status < 0 ) {
		    perror("erreur ecriture");
		    exit(EXIT_FAILURE);
		  }

		  memset(data, 0, sizeof(data));
		  int read_status = read(socketfd, data, sizeof(data));
		  if ( read_status < 0 ) {
		    perror("erreur lecture");
		    return -1;
		  }
		  strcpy(ans, data);
  	}
	printf("controle n°%s: %s\n", liste_dossier[i], ans);
  
  }

  //Somme des notes pour chaque élève (à l'aide de l'appel au serveur pour le calcul)
  for ( i = 0; i < nombre_fichiers; i++){
	strcpy(ans, "0");
	for (j = 0; j < nombre_dossier; j++){
		  strcpy(data, "calcul: + ");
		  strcat(data, ans);
		  strcat(data," ");
		  strcat(data, liste_note[j][i]);
		  
		  int write_status = write(socketfd, data, strlen(data));
		  if ( write_status < 0 ) {
		    perror("erreur ecriture");
		    exit(EXIT_FAILURE);
		  }

		  memset(data, 0, sizeof(data));
		  int read_status = read(socketfd, data, sizeof(data));
		  if ( read_status < 0 ) {
		    perror("erreur lecture");
		    return -1;
		  }
		  strcpy(ans, data);
  	}
	printf("notes de %s: %s\n", liste_fichier[i], ans);
  
  }
  
  return 0;
}

int main() {
  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'un socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  //demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if ( connect_status < 0 ) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }


  //envoie_recois_message(socketfd);
  envoie_operateur_numeros(socketfd);
  close(socketfd);

  
}
