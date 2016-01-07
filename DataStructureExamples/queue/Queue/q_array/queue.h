#ifndef _queue_h_
#define _queue_h_

/*
  struct for implementing a queue using
  a wrap-around array
*/
typedef struct {
  int* buf;    // the buffer
  int length;  // # of items currently in queue
  int start;   // start index of the front
  int buf_len; // # of items that can be stored
} q_array_t;


//Our implementaiton will be "modular", we can change
//the internal representation and implementations with
//impact on how the user uses the code
typedef q_array_t* queue;

/*
  Constructor: create an instance of the
  queue and return a pointer to that instance.
*/
queue q_create(int max_size);

/*
  Destructor: free up the space used by
  the queue.
*/
void q_destroy(queue q);

/*
  return the length of the queue
*/
int q_length(queue q);

/*
  add val to the end of the queue
*/
void q_add(queue q, int val);

/*
  return the item at the front of the queue
*/
int q_front(queue q);

/*
  remove the item at the front of the queue
*/
void q_remove(queue q);



#endif
