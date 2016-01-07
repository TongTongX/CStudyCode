CC = g++
CFLAGS = -c -Wall
LFLAGS = -Wall
OBJECTS = simple.o getnumber.o printnumber.o
PROJECT = readwrite

$(PROJECT): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(PROJECT)

simple.o: simple.cpp getnumber.h printnumber.h
	$(CC) $(CFLAGS) simple.cpp -o simple.o

printnumber.o: printnumber.cpp printnumber.h
	$(CC) $(CFLAGS) -c printnumber.cpp -o printnumber.o

getnumber.o: getnumber.cpp getnumber.h
	$(CC) $(CFLAGS) -c getnumber.cpp -o getnumber.o

clean:
	@rm -f $(OBJECTS) *~ $(PROJECT)
