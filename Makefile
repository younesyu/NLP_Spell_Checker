CC = gcc

CCFLAGS = -Wall -std=c99

OBJ = file_reader.o demerau-levenshtein.o

all: file_reader demerau-levenshtein

file_reader: file_reader.c $(OBJ) 
	$(CC) $(CCFLAGS) file_reader.c -o file_reader

demerau-levenshtein: demerau-levenshtein.c $(OBJ) 
	$(CC) $(CCFLAGS) demerau-levenshtein.c -o demerau-levenshtein


%.o: %.c
	$(CC) $(CCFLAGS) -c $<

.PHONY : clean

clean:
	- rm -f *.o
	- rm -f file_reader
	- rm -f demerau-levenshtein
