CC ?= gcc

COBJS ?= client.o bmp.o couleur.o
SOBJS ?= serveur.o 

.SUFFIXES: .c .o

SERVER = serveur
CLIENT = client

all: $(SERVER) $(CLIENT) pile file

$(SERVER): $(SOBJS)
	$(CC) -o $(SERVER) $(SOBJS)

$(CLIENT): $(COBJS)
	$(CC) -o $(CLIENT) $(COBJS)

.c.o: 
	$(CC) -c $*.c

pile: pile.c pile.h
	gcc -o pile pile.c pile.h

file: file.c file.h
	gcc -o file file.c file.h
