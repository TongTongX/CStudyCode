// pass-reference.c -- show pass by reference using pointers

/*
compile with:
cc -g -Wall -o pass-reference pass-reference.c
*/

#include <stdio.h>	// for printf()

// addemUp
void addemUp (int a, int b, int *result)
{
	*result = a + b;
}

int main (int argc, char *argv[])
{
	int answer;
	addemUp (1, 2, &answer);
	printf ("1 + 2 = %d\n", answer);
	
	return (0);
}