#ifndef _queue_h_
#define _queue_h_

/*
  struct for holding an item in the queue
  and pointing to the next item in the queue
*/
typedef struct q_item_t {
  int val;
  struct q_item_t* next;
} q_item_t;

/*
  struct for implementing a queue using
  a wrap-around array
*/
typedef struct {
  q_item_t* start;
  q_item_t* end;
  int length;
} q_list_t;

typedef q_list_t* queue;

/*
  Constructor: create an instance of the
  queue and return a pointer to that instance.

  NOTE: in this new linked list implementation
  there is no max size, either just ignore the parameter
  or remove it and document things clearly so the user
  knows about the change.
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
