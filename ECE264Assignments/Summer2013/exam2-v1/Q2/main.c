/*
  PROBLEM: Fill in the missing code in the file thing.c.  Follow the
  specifications given for each function in thing.h.  You are NOT
  allowed to change thing.h!
  
  TEST: run "make test" to test your output---the diff should exit
  with no errors.
 */

#include "thing.h"
#include <stdlib.h>

int main(int argc, char * argv[])
{
  Thing p1 = Thing_construct(20, "Computer");
  Thing p2 = Thing_construct(11, "Monitor");
  Thing p3 = Thing_copy(p1);
  Thing_print(p1);
  Thing_print(p2);
  Thing_print(p3);
  Thing_merge(&p1, p2);
  Thing_print(p1);
  Thing_print(p2);
  Thing_print(p3);
  Thing_destroy(p1);
  Thing_destroy(p2);
  Thing_destroy(p3);  
  return EXIT_SUCCESS;
}
