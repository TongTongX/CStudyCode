/*
  Doubly linked list library.
  
  A linked list stores items in a sequence of links. Each link holds the item and a pointer to
  the next link. This is a doubly-linked list meaning each link also holds a pointer
  to the previous link in the sequence.

  All functions declared below are implemented to run in O(1) time except for:
    - destroy_list(list): O(# items in the list)
    - find(list, item):   O(# items in the list)

  Note, this linked list can be used to simulate a queue: add new items to the back and remove from the front.
  Can also simulate a stack: only add and remove items from the back.
*/

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/*
  A link in the linked list.
*/

typedef struct link_t {
  int item;     // the item being held here
  struct link_t* prev; // point to previous item in the list
  struct link_t* next; // point to next item in the list
} link_t;

typedef link_t* link;

/*
  Linked list struct.
*/

typedef struct l_list_t {
  link front; // point to first item in the list
  link back;  // point to last item in the list
  int length;    // number of links in the list
} l_list_t;

typedef l_list_t* linked_list;

/*
  Create an empty linked list and return a pointer to it.
*/
linked_list l_create();

/*
  Destroy all links in the list and the list itself,
  freeing up all memory used by the list.
*/
  
void l_destroy(linked_list list);

/*
  Add the item to the front of the linked list.
*/
void l_add_front(linked_list list, int item);

/*
  Add the item to the back of the linked list.
*/
void l_add_back(linked_list list, int item);

/*
  Print off all items held in the list from first to last.
*/
void l_print(linked_list list);

/*
  Return the first item in the list.
*/
int l_front(linked_list list);

/*
  Return the last item in the list.
*/
int l_back(linked_list list);

/*
  Removes the first item held by the list.
*/
void l_remove_front(linked_list list);

/*
  Removes the last item held by the list.
*/
void l_remove_back(linked_list list);

/*
  Returns the number of items in the list.
*/
int l_length(linked_list list);

/*
  Return a pointer to the first link containing the item,
  NULL if the item is not in the list.
*/
link l_find(linked_list list, int item);

/*
  Removes the given link from the list.
  Assumes it is in fact a link from the list!
*/
void l_remove(linked_list list, link l);

/*
  Other possibly useful functions to consider implementing.
   - insert a new item before or after the first link containing a given item
   - remove all links containing a given item
   - concatenate two lists into one longer list
   - return the i'th item in the list
   - create a new list out of an array
   - copy the contents of a list into an array
*/

#endif
