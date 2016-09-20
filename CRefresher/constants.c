// constants.c -- show various constants

/*
compile with:
cc -g -o constants constants.c
*/

#include <stdio.h>		// printf()

int main(int argc, char *argv[])
{
	printf("Some integer constants: %d %d %d %d\n", 1, 3, 32767, -521);
	printf("Some floating-point constants: %f %f %f %f\n", 3.14159, 1.414213, 1.5, 2.0);
	printf("Single character constants: %c%c%c%c%c\n", 'W', 'P', '\114', '\125', '\107');
	printf("A character stirng constant: \"%s\"\n", "this is a string");

	return 0;
}