#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list.h"

/*
  Create an empty linked list and return a pointer to it.
*/
linked_list l_create() {
  //Allocate space to hold an empty list. So both the front and back
  //pointers should be NULL and the length 0. calloc will do this
  //because it zeros out all initialized memory.
  linked_list list = (linked_list) calloc(1, sizeof(l_list_t));

  assert(list != NULL);
  
  return list;
}

/*
  Destroy all links in the list and the list itself,
  freeing up all memory used by the list.
*/
void l_destroy(linked_list list) {
  

  /*
    Handy shortcut: If you implement, say, l_remove_front()
    then just call it a bunch of times until the list is empty.
    
    Remember to also free the memory used by "list" itself 
    when this is done.
  */
  while (l_length(list) > 0) {
    l_remove_front(list);
  }

  free(list);
}

/*
  Add the item to the front of the linked list.
*/
void l_add_front(linked_list list, int item) {
  link new_link = (link) malloc(sizeof(link_t));
  
  assert(new_link != NULL);

  //Store the item at this new node.
  new_link->item = item;

  //Since the new link will be the front of the list,
  //it points back to NULL.
  new_link->prev = NULL;

  if (l_length(list) == 0) {
    //If the list was empty, this link is both the front
    //and the back link.
    new_link->next = NULL;
    list->back = new_link;
  }
  else {
    //Otherwise, have the former front point back to this new
    //link and this new link point forward to the former front
    new_link->next = list->front;
    list->front->prev = new_link;
  }

  //In either case, the new link is the new front of the list.
  list->front = new_link;
  
  list->length += 1;
}

/*
  Add the item to the back of the linked list.
*/
void l_add_back(linked_list list, int item) {
  //Similar to l_add_front.
  link new_link = (link) malloc(sizeof(link_t));

  assert(new_link != NULL);

  // Store the item at this new node
  new_link->item = item;

  //Since the new link will be the back of the list,
  //it points next to NULL.
  new_link->next = NULL;

  if (l_length(list) == 0) {
    //If the list was empty, this link is both the back
    //and the front link.
    new_link->prev = NULL;
    list->front = new_link;
  }
  else {
    //Otherwise, have the former front point back to this new
    //link and this new link point forward to the former front
    new_link->prev = list->back;
    list->back->next = new_link;
  }

  //In either case, the new link is the new front of the list.
  list->back = new_link;
  
  list->length += 1;
}

/*
  Print off all items held in the list from first to last.
*/
void l_print(linked_list list) {
  //start at the front of the list
  link current = list->front;

  //Iterate through the list
  while (current != NULL) {

    //Prints a space between consecutive items in the list.
    if (current != list->front) printf(" ");

    printf("%d", current->item);

    //Move on to the next link.
    current = current->next;
  }
}

/*
  Return the first item in the list.
*/
int l_front(linked_list list) {
  assert(l_length(list) > 0);
  return list->front->item;
}

/*
  Return the last item in the list.
*/
int l_back(linked_list list) {
  assert(l_length(list) > 0);
  return list->back->item;
}

/*
  Removes the first item held by the list.
*/
void l_remove_front(linked_list list) {
  
  
  assert(l_length(list) > 0);

  //If l_remove() is implemented propertly below, just call
  //it with the pointer to the front link.
  l_remove(list, list->front);
}

/*
  Removes the last item held by the list.
*/
void l_remove_back(linked_list list) {
  assert(l_length(list) > 0);
  l_remove(list, list->back);
}

/*
  Returns the number of items in the list.
*/
int l_length(linked_list list) {
  return list->length;
}

/*
  Return a pointer to the first link containing the item,
  NULL if the item is not in the list.
*/
link l_find(linked_list list, int item) {
  /*
    Idea: iterate through the list much like with
    l_print(list). Return the pointer if the item is found.
  */

  //start at the front of the list
  link current = list->front;

  //Iterate through the list
  while (current != NULL) {

    if ( current->item == item ){
      return current;
    }

    //Move on to the next link.
    current = current->next;
  }  
  
  return NULL;

}

/*
  Removes the given link from the list.
  Assumes it is in fact a link from the list!
*/
void l_remove(linked_list list, link l) {
  /*
    Idea: make the item before link l point to the item after
    link l and vice-versa. Be careful if l is the start link or end link
    (or both).
    Once this is done, free up the memory used by l.
  */
  assert(list->length > 0);  
  
  if ( l->prev == NULL && l->next == NULL ){
    list->front = NULL;
    list->back = NULL;
  }
  else if ( l->prev == NULL ){
    list->front = list->front->next;
    list->front->prev = NULL; 
  }
  else if ( l->next == NULL ){
    list->back = list->back->prev;
    list->back->next = NULL;
  }
  else{
    l->prev->next = l->next;
    l->next->prev = l->prev;
  }
  list->length -= 1;
  free(l);

}
