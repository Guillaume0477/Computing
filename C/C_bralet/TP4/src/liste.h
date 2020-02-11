struct liste_couleurs{ 
	unsigned char rouge;
	unsigned char vert;
	unsigned char bleu;
	struct liste_couleurs *next;
	struct liste_couleurs *prev;
};

struct couleur{ 
	unsigned char rouge;
	unsigned char vert;
	unsigned char bleu;
};

void insertion (struct couleur *, struct liste_couleurs *); 
void parcours (struct liste_couleurs *); 
