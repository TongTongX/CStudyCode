// array-parameter.c

/*
compile with:
cc -g -Wall -o array-parameter array-parameter.c
*/

#include <stdio.h>	// for printf()

// printArray
void printArray (int *array, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf ("%d: %d\n", i, array[i]);
	}
}

int main (int argc, char *argv[])
{
	int array1[5];
	int array2[] = { 23, 42, 55 };
	int i;
	for (i = 0; i < 5; i++)
	{
		array1[i] = i;
	}
	printf ("array 1:\n");
	printArray (array1, 5);
	printf ("array 2:\n");
	printArray (array2, sizeof(array2) / sizeof(int));

	return (0);
}