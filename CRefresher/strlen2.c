// strlen2.c -- calculate the length of a C string, idiomatically

/*
compile with:
cc -g -Wall -o strlen2 strlen2.c
*/

#include <stdio.h>	// for printf()

int main (int argc, char *argv[])
{
	char *myString = "this is a sequence of chars";
	int length = 0;
	while (*myString++)
	{
		length++;
	}
	printf ("the length of the string is %d\n", length);
	
	return (0);
}