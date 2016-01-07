/*
  To test with teams.txt, run the command
    
    ./file_io teams.txt output.txt
*/

#include <stdio.h>
#include <stdlib.h>

//argc == # of parameters passed
//argv == array of parameters stored as strings
int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Expected 2 parameters, got %d\n", argc-1);
    exit(EXIT_FAILURE);
  }

  FILE* input_file;
  FILE* output_file;

  //r - read only
  input_file = fopen(argv[1], "r");

  if (input_file == NULL) {
    fprintf(stderr, "Could not open %s for input\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  //w - write, will delete the file if it already exists
  output_file = fopen(argv[2], "w");
  
  if (output_file == NULL) {
    fprintf(stderr, "Could not open %s for output\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  int length = 100;
  char team[length];
  int rank = 1;
  
  //read each line of the input file
  while (fgets(team, length, input_file) != NULL) {
    //and print it along with its rank
    fprintf(output_file, "%2d) %s", rank, team);
    ++rank;
  }

  fclose(input_file);
  fclose(output_file);

  return 0;
}
