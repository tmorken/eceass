/*
  PROBLEM: Fill in the missing code for managing a sorted link list in
  the file list.c!  Follow the specifications given for each function
  in list.h.  You are NOT allowed to change list.h!
  
  TEST: run "make test" to test your output---the diff should exit
  with no errors.
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define DATA_SIZE 10

int main(int argc, char *argv[])
{
    int data1[DATA_SIZE] = {5, 6, 2, 7, 1, 4, 8, 3, 0, 9};
    int data2[DATA_SIZE] = {4, 9, 0, 3, 12, 8, 1, 39, -41, 6};
    Node *head = NULL;
    int iter;
    for (iter = 0; iter < DATA_SIZE; iter ++) {
	head = List_insert(head, data1[iter]);
	List_print(head);
    }
    for (iter = 0; iter < DATA_SIZE; iter ++) {
	head = List_delete(head, data2[iter]);
	List_print(head);
    }
    List_destroy(head);
    return EXIT_SUCCESS;
}
