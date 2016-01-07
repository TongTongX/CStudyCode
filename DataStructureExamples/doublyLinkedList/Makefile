CC = gcc
LFLAGS =
CFLAGS = -c
OBJECTS = linked_list.o list_test.o
PROJECT = list_test

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROJECT) $(LFLAGS)

linked_list.o: linked_list.c linked_list.h
	$(CC) linked_list.c -o linked_list.o $(CFLAGS)

list_test.o: list_test.c linked_list.h
	$(CC) list_test.c -o list_test.o $(CFLAGS)

clean:
	rm -f $(OBJECTS) $(PROJECT) *~
