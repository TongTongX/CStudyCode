// strlen1.c -- calculate the length of a C string

/*
compile with:
cc -g -Wall -o strlen1 strlen1.c
*/

#include <stdio.h>	// for printf()

int main (int argc, char *argv[])
{
	char *myString = "this is a sequence of chars";
	int length = 0;
	while (*myString != '\0')
	{
		length++;
		myString++;
	}
	printf ("the length of the string is %d\n", length);
	
	return (0);
}