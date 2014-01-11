CC = gcc
CCFLAGS = -Wall -g
ARKEYS = rv
TARGET = index

all: index
index: main.o tokenizer.o hash-table.o traverse_dir.o
	$(CC) $(CCFLAGS) -o index main.o tokenizer.o hash-table.o traverse_dir.o
main.o: main.c
	$(CC) $(CCFLAGS) -c main.c
tokenizer.o: tokenizer.c
	$(CC) $(CCFLAGS) -c tokenizer.c
hash-table.o: hash-table.c
	$(CC) $(CCFLAGS) -c hash-table.c
traverse_dir.o: traverse_dir.c
	$(CC) $(CCFLAGS) -c traverse_dir.c	
clean:
	rm -f sl *.o index
