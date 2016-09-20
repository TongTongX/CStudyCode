// limits.c -- show some info about various built-in data types

/*
compile with:
cc -g -Wall -o limits limits.c
*/

#include <limits.h>		// limit constants
#include <stdio.h>		// printf()
#include <stdlib.h>		// EXIT_SUCCESS

int main(int argc, char *argv[])
{
	printf("	type:		bytes	%14s	%14s		%14s\n", "min value", "max value", "max unsigned");
	printf("	char:		%5d	%14d	%14d		%14u\n", sizeof(char), CHAR_MIN, CHAR_MAX, UCHAR_MAX);
	printf("	short:		%5d	%14d	%14d		%14u\n", sizeof(short), SHRT_MIN, SHRT_MAX, USHRT_MAX);
	printf("	int:		%5d	%14d	%14d		%14u\n", sizeof(int), INT_MIN, INT_MAX, UINT_MAX);
	printf("	long:		%5d	%14ld	%14ld		%14lu\n", sizeof(long), LONG_MIN, LONG_MAX, ULONG_MAX);

	// not available on all platforms
	#ifdef LLONG_MIN
		printf("	long long:	%5d %20lld %20lld %20llu\n", sizeof(long long), LLONG_MIN, LLONG_MAX, (long long)ULLONG_MAX);
	#endif
	printf("	float:		%5d\n", sizeof(float));
	printf("	double:		%5d\n", sizeof(double));

	return (EXIT_SUCCESS);
}