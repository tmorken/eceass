#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static Node *Node_construct(int v)
{
    // INSERT CODE HERE!
}

Node *List_insert(Node *head, int v)
{
    // INSERT CODE HERE!
}

Node * List_delete(Node *head, int v)
{
    // INSERT CODE HERE!
}

void List_destroy(Node *head)
{
    // INSERT CODE HERE!
}

/* print the whole list */
void List_print(Node *head)
{
    while (head != NULL) {
	printf("%d ", head->value);
	head = head->next;
    }
    printf("\n");
}
