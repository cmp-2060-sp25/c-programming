CC=gcc

CFLAGS=-c

all: file_handler

file_handler: main.o file_handler.o
	$(CC) main.o file_handler.o -o file_handler

main.o: main.c
	$(CC) $(CFLAGS) main.c

file_handler.o: file_handler.c
	$(CC) $(CFLAGS) file_handler.c

clean:
	rm -rf *o file_handler