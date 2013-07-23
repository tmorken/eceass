#ifndef PA05_H
#define PA05_H

typedef struct _huffnode 
{
  int value;
  struct _huffnode *left;
  struct _huffnode *right;
} HuffNode;

typedef struct _stack 
{
  struct _stack * next;
  HuffNode * node;
} Stack;

HuffNode * create_character_tree(FILE *);
//HuffNode * get_bits(FILE *, int);
Stack * pop_stack(Stack *);
Stack * push_stack(Stack *, HuffNode *);
HuffNode * create_HuffmanNode(char);
void Huff_postOrderPrint(HuffNode *, FILE *);
void tree_destroy(HuffNode *);

#endif
