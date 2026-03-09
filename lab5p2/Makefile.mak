CC=gcc
CFLAGS=-Wall

all: lab5p2

lab5p2: lab5p2.c
	$(CC) $(CFLAGS) lab5p2.c -o lab5p2

clean:
	rm -f lab5p2