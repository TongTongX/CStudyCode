#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

/*
  Struct to hold student record.
*/
typedef struct {
  unsigned int id;
  char name[40];
  char grade[3];
} student_info;

/*
  Struct to hold collision list entry.
*/
typedef struct table_node {
  student_info student;
  struct table_node* next;
} table_node;

/*
  Struct to hold hash table.
*/
typedef struct {
  table_node** buckets;
  unsigned int num_buckets;
} hash_table_instance;

typedef hash_table_instance* hash_table;

/*
  Create a new empty hash table with the
  specified number of buckets.
*/
hash_table ht_create(unsigned int size);

/*
  Reallocate all space used by the
  hash table and its entries.
*/
void ht_destroy(hash_table ht);

/*
  Looks up to find the student with the given "id".
  If successful, memory pointed to by "student" will
  contain a copy of this student's record and 1 is returned.

  If unsuccessful, 0 will be returned and the memory pointed
  to by "student" will not be changed.
*/
int ht_lookup(hash_table ht, int id, student_info* student);

/*
  Returns 1 if the student was added successfully,
  0 if there was already a student with the given
  id in the table
*/
int ht_insert(hash_table ht, student_info student);

/*
  Update the student record of the student with
  the given id. Returns 1 if successful, 0 if
  no such student is in the table.
*/
int ht_update(hash_table ht, student_info student);

/*
  Print all entries in the hash table.
*/
void ht_print(hash_table ht);

#endif
