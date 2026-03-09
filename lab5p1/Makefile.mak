CC=gcc
CFLAGS=-Wall

all: lab5p1

lab5p1: lab5p1.c
	$(CC) $(CFLAGS) lab5p1.c -o lab5p1

clean:
	rm -f lab5p1