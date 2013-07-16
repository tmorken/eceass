/*
  PROBLEM: In IPA2-1, you were asked to partition an integer into the
  sum of positive integers.  In this question, you need to partition
  an integer into the sum of *distinct* integers.  In other words, the
  same number cannot be reused in the same partition (you can of
  course reuse the same number in different partitions).

  Fill in code in the function partition() below; you may of course
  also define new functions if you find that it is necessary.
  
  EXAMPLE: An integer partition of the number 4 is the following:

  [1 1 1 1]
  [1 1 2]
  [1 2 1]
  [2 1 1]
  [1 3]
  [3 1]
  [2 2]
  [4]

  An integer partition with unique integers of the number 4 is the
  following:
  [1 3]
  [3 1]
  [4]
  
  These are the only partitions where the same integer is only used at
  most one time (for example, [2 2] and [1 1 1 1] reuse the same
  integer several times).

  INPUT: argv[1]: a positive integer to be partitioned

  OUTPUT: Use the function printResult (code given below) to generate
  the correct output.

  TEST: run "make test" to test your output---the diff should exit
  with no errors.

  The output order does not matter.  Please check the Makefile.  The
  outputs are sorted before comparison.

 */

#include <stdio.h>
#include <stdlib.h>

void printResult(int *array, int length)
{
    int iter;
    printf("[");
    for (iter = 0; iter < length - 1; iter ++) {
	printf("%d ", array[iter]);
    }
    printf("%d", array[length - 1]);
    printf("]\n");
}

void partition(int value)
{
    // FILL IN CODE HERE!
}

int main(int argc, char * argv[])
{
    if (argc < 2) {
	printf("Need a positive integer.\n");
	return EXIT_FAILURE;
    }
    int value = (int) strtol(argv[1], NULL, 10);
    if (value <= 0) {
	printf("Need a positive integer.\n");
	return EXIT_FAILURE;
    }
    partition(value);
    return EXIT_SUCCESS;
}
