# Variables
CC=gcc
CFLAGS=-Wall -g3
LDFLAGS=-lm -lpq
MKDIR=mkdir -p
DEL=rm -fr

carpetas:
	$(MKDIR) build dist

clean:
	$(DEL) build dist *.o

db.o: carpetas db.c
	$(CC) $(CFLAGS) -c db.c -o build/db.o

main.o: carpetas main.c
	$(CC) $(CFLAGS) -c main.c -o build/main.o

all: carpetas db.o main.o
	$(CC) $(CFLAGS) -o dist/app build/db.o build/main.o $(LDFLAGS)
	$(DEL) build

.PHONY: all
.DEFAULT_GOAL := all
