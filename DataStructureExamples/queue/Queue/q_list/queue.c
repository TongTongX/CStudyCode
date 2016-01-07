#include <stdlib.h>
#include <assert.h>
#include "queue.h"
 
/*
  Constructor: create an instance of the
  queue and return a pointer to that instance.
*/
queue q_create(int max_size) {
  queue q = (queue) malloc(sizeof(q_list_t));
  assert(q != NULL);

  //an empty queue has start and end pointing to NULL
  q->start = NULL;
  q->end = NULL;
  q->length = 0;

  return q;
}

/*
  Destructor: free up the space used by
  the queue.
*/
void q_destroy(queue q) {
  //the q_remove function will free space allcoated for the
  //front item, so just iteratively called to clear the queue
  while (q_length(q) > 0) {
    q_remove(q);
  }

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
  q_item_t* new_item;

  //get space for the new item
  new_item = (q_item_t*) malloc(sizeof(q_item_t));
  assert(new_item != NULL);

  //the new item will be at the end of the queue,
  //so the next item after it is NULL
  new_item->val = val;
  new_item->next = NULL;

  if (q->end != NULL) {
    //the queue was not empty, so the previous end
    //should point to this item
    q->end->next = new_item;
  }
  else {
    //the queue was empty, so this item is
    //also the start of the queue
    q->start = new_item;
  }

  //finally point to the new end of the queue
  q->end = new_item;

  q->length += 1;
}

/*
  return the item at the front of the queue
*/
int q_front(queue q) {
  assert(q_length(q) > 0);

  return q->start->val;
}

/*
  remove the item at the front of the queue
*/
void q_remove(queue q) {
  assert(q->length > 0);


  //get the item after the start
  //if the queue only has 1 item, this will be NULL
  q_item_t* new_start = q->start->next;

  //erase the front of the queue
  free(q->start);

  //update the front of the queue
  q->start = new_start;

  q->length -= 1;
}

