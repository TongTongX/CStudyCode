// conditional.c -- look at conditional compilation

/*
compile with:
cc -g -Wall -o conditional conditional.c
*/

#include <stdio.h>		// for printf()

// main
int main(int argc, char *argv[])
{
	#define THING1

	#ifdef THING1
		printf("thing1 defined\n");
	#else
		printf("thing1 is not defined\n");
	#endif

	#ifdef THING2
		printf("thing2 defined\n");
	#else
		printf("thing2 is not defined\n");
	#endif

	return 0;
}