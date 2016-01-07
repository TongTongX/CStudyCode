CC = gcc
CFLAGS = -c
LFLAGS =
OBJECTS = queue.o q_test.o
PROJECT = q_test

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROJECT) $(LFLAGS)

queue.o: queue.c queue.h
	$(CC) queue.c -o queue.o $(CFLAGS)

q_test.o: q_test.c queue.h
	$(CC) q_test.c -o q_test.o $(CFLAGS)

clean:
	rm -f $(PROJECT) $(OBJECTS) *~
