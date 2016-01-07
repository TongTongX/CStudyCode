#include <stdio.h>
#include <string.h>
#include "hash_table.h"


/* The ht_count_name function will return the number of students stored 
 * in the hash table ht whose name equals test_name.
 * You may assume test_name is already null terminated.
 */
int ht_count_name(hash_table ht, char test_name[40]){
  int count = 0;
  int i;
  for ( i = 0; i < ht->num_buckets; ++i ){

    table_node* node = ht->buckets[i];

    while ( node != NULL ){
      if ( !strcmp( node->student.name, test_name ) ) {
        ++count;     
      }
      node = node->next; 
    }
  }

  printf("%d\n", count);
  return count;
}

void test_count_name(){
  printf("test begins!\n");
  
  student_info students[] = {
    {1234567, "Jillian", "B"},
    {1325124, "Stacey", "A-"},
    {8743230, "Doug", "A"},
    {0102030, "Barry", "F"},
    {5555555, "Michael", "A-"},
    {1293875, "Michael", "C"},
    {5239883, "Barry", "A+"},
    {1432562, "Barry", "A+"},
    {2376543, "Barry", "A+"},
    {1254325, "Barry", "A+"},
    {2345445, "Barry", "A+"}           
  };

  hash_table ht = ht_create(10);

  int i;
  for (i = 0; i < 11; ++i) {
    ht_insert(ht, students[i]);
  }

  ht_print(ht);
  
  char test_name1[40] = "YuZhu";
  char test_name2[40] = "Barry";
  char test_name3[40] = "Doug";
  char test_name4[40] = "Michael"; 

  if ( ht_count_name(ht,test_name1) == 0 ){
    printf("test1 successed\n");
  }
  else{
    printf("test1 failed\n");
  }
  
  if ( ht_count_name(ht,test_name2) == 6 ){
    printf("test2 successed\n");
  }
  else{
    printf("test2 failed\n");
  }
  
  if ( ht_count_name(ht,test_name3) == 1 ){
    printf("test3 successed\n");
  }
  else{
    printf("test3 failed\n");
  }
  
  if ( ht_count_name(ht,test_name4) == 2 ){
    printf("test4 successed\n");
  }
  else{
    printf("test4 failed\n");
  }    

  ht_destroy(ht);  
  
  printf("test ends!\n");
}


int main() {

  
  
  test_count_name();
  

  return 0;
}
