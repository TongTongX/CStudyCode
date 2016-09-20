// function-pointer.c -- play with function pointers

/*
compile with:
cc -g -Wall -o function-pointer function-pointer.c
*/

#include <stdio.h>	// for printf()

// printAsChar
void printAsChar (int value)
{
	printf ("%d as a char is '%c'\n", value, value);
}

// printAsInt
void printAsInt (int value)
{
	printf ("%d as an int is '%d'\n", value, value);
}

// printAsHex
void printAsHex (int value)
{
	printf ("%d as hex is '0x%x'\n", value, value);
}

// printIt
void printIt (int value, void (*printingFunction)(int))
{
	(printingFunction)(value);
}

int main (int argc, char *argv[])
{
	int value = 35;
	printIt (value, printAsChar);
	printIt (value, printAsInt);
	printIt (value, printAsHex);
	
	return (0);
}