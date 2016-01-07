#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash_table.h"

/*
  A simple hash function that maps a student id
  to the index of one of the buckets.
*/
unsigned int hash(unsigned int id, unsigned int num_buckets) {
  //if the student ids are roughly sequential, this should
  //distribute them roughly evenly across the buckets
  return id % num_buckets;
}

/*
  Return a pointer to the student info in the hash table
  for the student with the given id. If no such
  student was found, returns NULL.
*/
student_info* ht_find_record(hash_table ht, unsigned int id) {
  //hash to find the bucket this id should be in
  unsigned int bucket_index = hash(id, ht->num_buckets);

  //get the start of the collision list for this bucket
  table_node* node = ht->buckets[bucket_index];

  while (node != NULL) {
    //if this collision list node contains the given id
    //return a pointer to the actual student information
    //
    //note that "student" is an actual instance of a student_info struct
    //in the table node, not a pointer, so we access it with just .
    if (node->student.id == id) {
      return &(node->student);
    }
    //otherwise go to the next student in the list
    else {
      node = node->next;
    }
  }

  //no student in this bucket had the given id
  return NULL;
}


/*
  Create a new empty hash table with the
  specified number of buckets.
*/
hash_table ht_create(unsigned int size) {
  hash_table ht = (hash_table) malloc(sizeof(hash_table_instance));
  assert(ht != NULL);

  ht->num_buckets = size;

  //the buckets should be initialized with NULL pointers
  //indicating they hold an empty collision list
  //calloc will initialize all allocated memory to 0, a.k.a. NULL
  ht->buckets = (table_node**) calloc(size, sizeof(table_node*));
  assert(ht->buckets != NULL);

  return ht;
}

/*
  Reallocate all space used by the
  hash table and its entries.
*/
void ht_destroy(hash_table ht) {

  //first free up all memory used by the collision lists
  unsigned int i;
  for (i = 0; i < ht->num_buckets; i++) {
    //while there is something in the collision list for bucket i
    while (ht->buckets[i] != NULL) {
      //grab a pointer to the second node in the collision list
      //it will be NULL if the list only contains one entry
      table_node* next_node = ht->buckets[i]->next;

      //free the memory allocated to the first collision list node
      free(ht->buckets[i]);

      //now next_node should be the start of the list
      //if there was no next node, the bucket now points to NULL
      ht->buckets[i] = next_node;
    }
  }

  //all memory used by the collision lists is now freed up,
  //so we can free up the bucket buffer itself
  free(ht->buckets);

  //finally free up the memory allocated to hold the hash table instance
  free(ht);
}

/*
  Looks up to find the student with the given "id".
  If successful, memory pointed to by "student" will
  contain a copy of this student's record and 1 is returned.

  If unsuccessful, 0 will be returned and the memory pointed
  to by "student" will not be changed.
*/
int ht_lookup(hash_table ht, int id, student_info* student) {
  //find the student record in the hash table
  student_info* record = ht_find_record(ht, id);

  if (record == NULL) {
    //no student with that id is in the table
    return 0;
  }
  else {
    //copy the student information to the address pointed to by "student"
    //this will copy over all strings as well because they are fixed-size
    //arrays in the structs (i.e. = will copy over all memory used by the struct)
    *student = *record;
    return 1;
  }
}

/*
  Returns 1 if the student was added successfully,
  0 if there was already a student with the given
  id in the table
*/
int ht_insert(hash_table ht, student_info student) {
  //check to see if some student with that id already exists in the table
  if (ht_find_record(ht, student.id) != NULL) {
    return 0;
  }
  else {
    //grab some memory to hold a new collision list node
    table_node* new_node = (table_node*) malloc(sizeof(table_node));
    assert(new_node != NULL);
    
    //copy the student information to this new node, recall that
    //= will copy over all memory allocated to the student_info struct instance
    //including the entire contents of the fixed-length character arrays
    new_node->student = student;
    
    //now add this new node to the start of the collision list
    //for the appropriate buckets
    
    //find the bucket
    unsigned int bucket_index = hash(student.id, ht->num_buckets);
    
    //point the new node to the start of the collision list
    //(or NULL if the list was empty)
    new_node->next = ht->buckets[bucket_index];
    
    //finally make this new node the start of this list,
    //the former start of the list will now be the second entry
    ht->buckets[bucket_index] = new_node;

    return 1;
  }
}

/*
  Update the student record of the student with
  the given id. Returns 1 if successful, 0 if
  no such student is in the table.
*/
int ht_update(hash_table ht, student_info student) {
  //find the student record to update
  student_info* record = ht_find_record(ht, student.id);

  if (record == NULL) {
    //no student in the table has the given id
    return 0;
  }
  else {
    //otherwise copy the student information to update the record
    //note, the student id cannot change
    *record = student;
    return 1;
  }
}

/*
  Print all entries in the hash table.
*/
void ht_print(hash_table ht) {
  unsigned int i;
  for (i = 0; i < ht->num_buckets; i++) {
    table_node* node = ht->buckets[i];
    if (node != NULL) {
      //if the bucket is not empty, print the bucket number
      //followed by the students in the collision list
      printf("Bucket %d:\n", i);

      //now iterate through the collision list
      while (node != NULL) {
	printf("%07d | %-20s | %-2s\n", node->student.id,
	       node->student.name, node->student.grade);
	node = node->next;
      }

      //add a blank line after each bucket so the output is easier to read
      printf("\n");
    }
  }
}


