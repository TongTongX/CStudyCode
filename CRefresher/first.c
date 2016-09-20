// first.c -- a simple first C program

/*
compile with
cc -g -o first first.c
*/

#include <stdio.h>		// for printf()
#include <math.h>		// for cos()

// main
int main(int argc, char *argv[])
{
	printf("the cosine of 1 is %g\n", cos(1.0));
	printf("thank you, and have a nice day\n");

	return (0);
}
