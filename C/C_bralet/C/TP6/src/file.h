struct file{
	int nombre;
	struct file* next;
	struct file* prev;
};

void enfiler(int nombre, struct file *ptr);
int defiler(struct file *ptr);
