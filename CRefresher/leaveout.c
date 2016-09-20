// leaveout.c -- use the preprocessor to comment out a chunk of code

/*
compile with:
cc -g -Wall -o leaveout leaveout.c
*/

#include <stdio.h>		// for printf()

int main(int argc, char *argv[])
{
	#if 0
		printf("oh happy day\n");
		printf("bork bork bork\n");
		we_can even have syntax errors here
		since the compiler will never see tis part
	#endif

	#if 1
		printf("This is included.\n");
	#endif

	return 0;

}