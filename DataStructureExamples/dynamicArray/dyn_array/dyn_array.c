#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
  struct to hold information for the dynamice array
*/
typedef struct dyn_array {

  int* buf;

  //# of ints in the buffer
  int length;

  //# of ints the allocated buffer can hold
  int buf_length;
  
} dyn_array;


/*
  Initialize the array to one containing no items.
*/
void init_array(dyn_array* array) {
  //(*array).buf is the same as array->buf
  array->buf = NULL;
  array->length = 0;
  array->buf_length = 0;
}

/*
  Clear up the memory allocated to the array.
*/
void destroy_array(dyn_array* array) {
  free(array->buf);

  // Conveniently resets the struct information
  init_array(array);
}

/*
  Add a number to the end of the array.
  Resizes the buffer if needed.
*/
void add_number(dyn_array* array, int num) {
  //if the buffer is full, allocate more space
  if (array->length == array->buf_length) {
    //double the buffer length
    int new_length = 2*array->buf_length;

    //in case the buffer was empty
    if (new_length == 0) new_length = 1;

    int* new_buf = realloc(array->buf, new_length * sizeof(int));

    if (new_buf == NULL) {
      fprintf(stderr, "Error when trying to grow the buffer.\n");

      //The operating system will free this memory when we exit, even
      //if we don't do it here. This is just to remind you that the
      //original buffer is still allocated if realloc() fails.
      free(array->buf);
      exit(EXIT_FAILURE);
    }

    array->buf = new_buf;
    array->buf_length = new_length;
  }

  //whether the above if condition was true or now, we now have
  //enough memory to accommodate the new value
  array->buf[array->length] = num;
  array->length += 1;
}

int main() {
  dyn_array array;

  init_array(&array);

  int i;
  for (i = 0; i < 20; ++i) {
    add_number(&array, 2*i);
    if (array.buf[i] != 2*i) {
      printf("failed to add %d to position %d\n", 2*i, i);
    }
  }
  
  //should be 20
  if (array.length != 20) {
    printf("array size should be 20\n");
  }

  destroy_array(&array);

  return 0;
}

