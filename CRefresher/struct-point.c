// struct-point.c -- some structure, pointer stuff

/*
compile with:
cc -g -Wall -o struct-point struct-point.c
*/

#include <stdio.h>	// for printf()

struct Person
{
	char *name;
	int age;
	char gender; // use 'm', 'f'
	double shoeSize;
};

// populatePerson
void populatePerson(struct Person *person)
{
	person->name = "Bork";
	person->age = 34;
	person->gender = 'm';
	person->shoeSize = 10.5;
}

// printPerson
void printPerson (struct Person *person)
{
	printf ("name: %s\n", person->name);
	printf ("age: %d\n", person->age);
	printf ("gender: %s\n", (person->gender == 'm') ? "male" : "female");
	printf ("shoe size: %f\n", person->shoeSize);
}

int main (int argc, char *argv[])
{
	struct Person me;
	populatePerson (&me);
	printPerson (&me);
	
	return (0);
}