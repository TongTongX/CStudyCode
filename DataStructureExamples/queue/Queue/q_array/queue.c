#include <stdlib.h>
#include <assert.h>
#include "queue.h"
 
/*
  Constructor: create an instance of the
  queue and return a pointer to that instance.
*/
queue q_create(int max_size) {
  queue q = (queue) malloc(sizeof(q_array_t));

  //assert(boolean value)
  //will terminate the program if the boolean is false
  assert(q != NULL);

  q->buf = (int *) malloc(max_size * sizeof(int));
  assert(q->buf != NULL);

  q->length = 0;
  q->start = 0;
  q->buf_len = max_size;

  return q;
}

/*
  Destructor: free up the space used by
  the queue.
*/
void q_destroy(queue q) {
  free(q->buf);
  free(q);
}

/*
  return the length of the queue
*/
int q_length(queue q) {
  return q->length;
}

/*
  add val to the end of the queue
*/
void q_add(queue q, int val) {
  //TODO: implement a function that
  //returns the maximum capacity of the queue
  assert(q_length(q) < q->buf_len);

  q->buf[(q->start + q->length) % q->buf_len] = val;
  q->length += 1;
}

/*
  return the item at the front of the queue
*/
int q_front(queue q) {
  assert(q_length(q) > 0);

  return q->buf[q->start];
}

/*
  remove the item at the front of the queue
*/
void q_remove(queue q) {
  assert(q->length > 0);

  q->start = (q->start+1) % q->buf_len;
  q->length -= 1;
}

