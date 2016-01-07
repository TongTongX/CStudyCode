#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"


// return the number of occurrences of the value v in the queue q
int q_count_value(queue q, int v){
  int count = 0;
  int tmp_val;
  // printf("q->start->val is %d\n", q->start->val);
  q_item_t* tmp_next = q->start;
  // printf("q->length is %d\n",q->length);
  while( tmp_next != NULL ){
    tmp_val = tmp_next->val; 
    tmp_next = tmp_next->next;
    if ( tmp_val == v ){
      ++count;
    }    
  }
  return count;
}


// test q_count_value
void test_count_value(){
  printf("\ntest_count_value starts...\n");
  
  queue q1;
  queue q2;
  queue q3;
  queue q4;

  //initialize the queue
  q1 = q_create(10);
  q2 = q_create(10);
  q3 = q_create(10);
  q4 = q_create(10);

  int i;
  for (i = 0; i < 10; ++i) {
    q_add(q1, i);
    assert(q_length(q1) == i+1);
  }

  for (i = 0; i < 10; ++i) {
    q_add(q2, 0);
    assert(q_length(q2) == i+1);
  }

  for (i = 0; i < 10; ++i) {
    q_add(q3, 10);
    assert(q_length(q3) == i+1);
  }

  for (i = 0; i < 10; ++i) {
    q_add(q4, i%3);
    assert(q_length(q4) == i+1);
  }

  if ( q_count_value(q1,5) == 1 ){
    printf("test No.1 succeeded!\n");    
  }
  else{
    printf("test No.1 failed!\n");
    printf("q_count_value(q1,0) = %d\n", q_count_value(q1,0));
  }
  
  if ( q_count_value(q2,0) == 10 ){
    printf("test No.2 succeeded!\n");    
  }
  else{
    printf("test No.2 failed!\n");
    printf("q_count_value(q2,0) = %d\n", q_count_value(q2,0));
  }
  
  if ( q_count_value(q3,0) == 0 ){
    printf("test No.3 succeeded!\n");    
  }
  else{
    printf("test No.3 failed!\n");
    printf("q_count_value(q3,0) = %d\n", q_count_value(q3,0));    
  }
  
  if ( q_count_value(q4,0) == 4 ){
    printf("test No.4 succeeded!\n");    
  }
  else{
    printf("test No.4 failed!\n");
    printf("q_count_value(q4,0) = %d\n", q_count_value(q4,0)); 
  }
  
  q_destroy(q1);
  q_destroy(q2);
  q_destroy(q3);
  q_destroy(q4);
  
  printf("test_count_value ends...\n\n");
}

int main() {
  test_count_value();
  
  return 0;
}
