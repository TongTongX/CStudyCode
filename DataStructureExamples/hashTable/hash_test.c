#include <stdio.h>
#include <string.h>
#include "hash_table.h"

int same(student_info s1, student_info s2) {
  if (s1.id != s2.id) return 0;
  if (strcmp(s1.name, s2.name)) return 0;
  if (strcmp(s1.grade, s2.grade)) return 0;

  return 1;
}

//try adding the student to the hash table, "exp" is the
//expected return value
void insert_test(hash_table ht, student_info student, int exp) {
  int res = ht_insert(ht, student);

  if (res != exp) {
    printf("Error adding %s with id %d: expected %d, got %d\n",
	   student.name, student.id, exp, res);
  }
}

//lookup the student with the given "id" in the table, "exp"
//is the expected return value and student is what the student
//record should look like if it is returned
void lookup_test(hash_table ht, int id, int exp, student_info student) {
  student_info found;
  int res = ht_lookup(ht, id, &found);

  if (res != exp) {
    printf("Error finding id %d: expected %d, got %d\n",
	   id, exp, res);
  }
  else if (res == 1 && same(student, found) == 0) {
    printf("Found %d %s %s\nExpected %d %s %s\n",
	   found.id, found.name, found.grade,
	   student.id, student.name, student.grade);
  }
}

//update the student record with the given id, "exp" is the
//expected return value.
void update_test(hash_table ht, student_info student, int exp) {
  int res = ht_update(ht, student);
    if (res != exp) {
    printf("Error updating %s with id %d: expected %d, got %d\n",
	   student.name, student.id, exp, res);
  }
}

int main() {
  student_info students[] = {
    {1234567, "Jillian", "B"},
    {1325124, "Stacey", "A-"},
    {8743230, "Doug", "A"},
    {0102030, "Barry", "F"},
    {5555555, "Michael", "A-"},
    {1293875, "Kelsey", "C"},
    {5239883, "Barry", "A+"}
  };

  hash_table ht = ht_create(10);

  int i;
  for (i = 0; i < 7; ++i) {
    insert_test(ht, students[i], 1);
  }

  ht_print(ht);
    
  //has same ID as "Doug"
  student_info doug_v2 = {8743230, "Douglas", "A"};

  insert_test(ht, doug_v2, 0);

  update_test(ht, doug_v2, 1);

  lookup_test(ht, doug_v2.id, 1, doug_v2);

  ht_destroy(ht);

  return 0;
}

