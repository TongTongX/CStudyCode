#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
  Test the length function.
*/
void length_test(linked_list list, int len) {
  int val = l_length(list);
  if (val != len) {
    printf("Length test failed: expected %d got %d.\n", len, val);
  }
}

/*
  Test the front function.
*/
void front_test(linked_list list, int item) {
  int val = l_front(list);
  if (val != item) {
    printf("Front test failed: expected %d got %d.\n", item, val);
  }
}

/*
  Test the back function.
*/
void back_test(linked_list list, int item) {
  int val = l_back(list);
  if (val != item) {
    printf("Back test failed: expected %d got %d.\n", item, val);
  }
}

/*
  Test the print function. Just print the expected output
  and actual output to the screen. The array vals
  contains the items expected in the list, in order of appearance
  in the list.
*/
void print_test(linked_list list, int* vals, int n) {
  printf("Expecting:");
  int i;
  for (i = 0; i < n; i++) {
    printf(" %d", vals[i]);
  }
  printf("\n");
  printf("Got      : ");
  l_print(list);
  printf("\n\n");
}

/*
  Test the find function.
*/
void find_test(linked_list list, int item, int result) {
  link l = l_find(list, item);

  if (l == NULL && result != 0) {
    printf("Find test failed: expected to find %d, got NULL.\n", item);
  }
  else if (l != NULL && result == 0) {
    printf("Find test failed: expected NULL when finding %d.\n", item);
  }
  else if (l != NULL && l->item != item) {
    printf("Find test failed: expected %d, found %d.\n", item, l->item);
  }
}

void big_test() {
    linked_list list = l_create();

  l_add_front(list, 3);

  length_test(list, 1);
  front_test(list, 3);
  back_test(list, 3);
  //list = 3


  l_add_back(list, 4);
  length_test(list, 2);
  front_test(list, 3);
  back_test(list, 4);
  //list = 3, 4

  
  l_add_front(list, 2);
  length_test(list, 3);
  front_test(list, 2);
  back_test(list, 4);
  //list = 2, 3, 4

  
  int array1[] = {2, 3, 4};
  print_test(list, array1, 3);


  l_add_front(list, 1);
  l_add_back(list, 5);
  length_test(list, 5);
  front_test(list, 1);
  back_test(list, 5);
  //list = 1, 2, 3, 4, 5

  
  find_test(list, 3, 1);
  link l = l_find(list, 3);
  l_remove(list, l);
  find_test(list, 3, 0);
  length_test(list, 4);
  front_test(list, 1);
  back_test(list, 5);
  //list = 1, 2, 4, 5

  
  int array2[] = {1, 2, 4, 5};
  print_test(list, array2, 4);

  
  l_remove_back(list);
  length_test(list, 3);
  back_test(list, 4);
  //list = 1, 2, 4
  
  l_remove_front(list);
  length_test(list, 2);
  front_test(list, 2);
  //list = 2, 4

  l_destroy(list);
}

int main() {
  big_test();
  
  return 0;
}
