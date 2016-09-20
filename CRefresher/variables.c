// variables.c -- some simple variable declarations

/*
compile with:
cc -g -Wall -o variables variables.c
*/

#include <stdio.h>		// printf

int aGlobalInt;			// global
float pi = 3.14159;		// global

// some function
void someFunction()
{
	int aLocalVariable = 0;		// local, random value but initialized to zero
	unsigned short myShort;		// local, random value
	static unsigned char aByte;	// static, initialized to zero, persists

	myShort = 500 + aLocalVariable;
	aGlobalInt = 5;

	aByte++;

	printf("aByte: %d, myShort: %d, aGlobalInt: %d\n", aByte, myShort, aGlobalInt);
}

int main(int argc, char *argv[])
{
	printf("aGlobalInt before someFunction: %d\n", aGlobalInt);
	someFunction();

	printf("aGlobalInt after someFunction: %d\n", aGlobalInt);
	someFunction();

	aGlobalInt = 23;
	someFunction();

	return 0;
}