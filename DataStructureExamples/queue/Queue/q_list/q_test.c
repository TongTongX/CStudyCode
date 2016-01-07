#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main() {
  queue q;

  //initialize the queue
  q = q_create(10);

  int i;
  for (i = 0; i < 10; ++i) {
    q_add(q, i);
    assert(q_length(q) == i+1);
  }

  assert(q_front(q) == 0);

  q_remove(q);

  assert(q_length(q) == 9 && q_front(q) == 1);

  //should succeed, even though 11 items have been
  //inserted overall
  q_add(q, 10);

  printf("All good tests succeeded!\n");

  //this shouldn't crash now, the queue has no maximum size
  q_add(q, 11);

  q_destroy(q);

  return 0;
}
