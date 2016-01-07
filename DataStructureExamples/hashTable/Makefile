CC = gcc
LFLAGS =
CFLAGS = -c
OBJECTS = hash_table.o hash_test.o
PROJECT = hash_test

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROJECT) $(LFLAGS)

hash_table.o: hash_table.h hash_table.c
	$(CC) hash_table.c -o hash_table.o $(CFLAGS)

hash_test.o: hash_table.h hash_test.c
	$(CC) hash_test.c -o hash_test.o $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(PROJECT) *~
