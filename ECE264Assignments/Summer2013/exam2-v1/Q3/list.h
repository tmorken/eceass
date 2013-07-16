#ifndef LIST_H
#define LIST_H

// DO NOT CHANGE THIS FILE!

typedef struct listnode {
  struct listnode * next;
  int value;
} Node;

/* 
   Insert a new value into the linked list. The values in the list
   must appear in increasing (ascending) order, i.e. if q is p->next,
   q->value must be greater than or equal to p->value.  It is possible
   that two adjacent nodes have the same value.

   The function returns the new head of the linked list.
*/
Node *List_insert(Node *head, int v);

/* 
   Delete the node whose value is v. If no node has this value,
   the list is unchanged.
   The function returns the new head of the linked list.
 */
Node *List_delete(Node *head, int v);

/* Print the whole list */
void List_print(Node *head);

/* delete all nodes in the list */
void List_destroy(Node *head);

#endif /* list.h */
