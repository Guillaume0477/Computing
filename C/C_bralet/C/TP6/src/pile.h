struct pile{
	int nombre;
	struct pile* next;
};

void empiler(int nombre, struct pile *ptr);
int depiler(struct pile *ptr);
