#include <stdio.h>

int main() {
  printf("Some text\n");

  int a = 10;
  printf("Value of a = %d\n", a);

  int b = 15;
  printf("%d + %d = %d    %s\n", a, b, a+b, "CORRECT");

  printf("Enter two values: ");

  int num_read;

  //must supply the address where the input data should be stored
  //returns the number of arguments that are succesfully read
  num_read = scanf("%d%d", &a, &b);
  
  printf("%d + %d = %d\n", a, b, a+b);

  printf("Number read %d\n", num_read);

  return 0;
}
