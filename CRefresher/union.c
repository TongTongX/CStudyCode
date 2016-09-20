// union.c -- play with unions

/*
compile with:
cc -g -Wall -o union union.c
*/

#include <stdio.h>

typedef struct Person
{
	char	*name;
	int		age;
	char	gender;		// use 'm', 'f'
	double	shoeSize;
} Person;


typedef struct Alien
{
	char	*designation;
	char	bloodType;	// use 'Q', 'X', or "@"
	int		hearts;
	short	psiPower;
	short	ducks;		// can be negative
} Alien;

enum { Human, NonHuman };

typedef struct Individual
{
	int type;
	union
	{
		Person	person;
		Alien	alien;
	} indData;
} Individual;

// fillAlien
void fillAlien (Individual *individual)
{
	individual->type = NonHuman;
	individual->indData.alien.designation = "qwzzk";
	individual->indData.alien.bloodType = 'X';
	individual->indData.alien.hearts = 7;
	individual->indData.alien.psiPower = 2870;
	individual->indData.alien.ducks = 3;
}

// fillPerson
void fillPerson (Individual *individual)
{
	individual->type = Human;
	individual->indData.person.name = "Bork";
	individual->indData.person.age = 34;
	individual->indData.person.gender = 'm';
	individual->indData.person.shoeSize = 10.5;
}

// printIndividual
void printIndividual (Individual *individual)
{
	if (individual->type == Human)
	{
		printf ("Human:\n");
		printf ("	name: %s\n",	individual->indData.person.name);
		printf ("	age: %d\n",		individual->indData.person.age);
		printf ("	gender: %c\n",	individual->indData.person.gender);
		printf ("	shoeSize: %f\n",individual->indData.person.shoeSize);
	}
	else if (individual->type == NonHuman)
	{
		printf ("NonHuman:\n");
		printf ("	designation: %s\n",	individual->indData.alien.designation);
		printf ("	bloodType: %c\n",	individual->indData.alien.bloodType);
		printf ("	hearts: %d\n",		individual->indData.alien.hearts);
		printf ("	psiPower: %d\n",	individual->indData.alien.psiPower);
		printf ("	ducks: %d\n",		individual->indData.alien.ducks);
	}
	else
	{
		printf ("oops, bad union qualifier\n");
	}
}

int main (int argc, char *argv[])
{
	Individual being;
	
	fillAlien (&being);
	printIndividual (&being);
	fillPerson (&being);
	printIndividual (&being);
	
	return (0);
}