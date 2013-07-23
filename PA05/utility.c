#include <stdio.h>
#include <stdlib.h>
#include "pa05.h"


Stack * pop_stack (Stack * top)
{
  Stack * temp = top -> next;
  
  free(top);
  
  return temp;
}

Stack * push_stack (Stack * top, HuffNode * node)
{
  Stack * current_top = malloc(sizeof(Stack)); //current_top = new_top
  
  current_top -> next = top;
  current_top -> node = node;
  
  return current_top;
}

HuffNode * create_HuffmanNode(char val)
{
  HuffNode * node = malloc(sizeof(HuffNode));
  
  node -> value = val;
  node -> left = NULL;
  node -> right = NULL;
  
  return node;
}

void tree_destroy(HuffNode * tree)
{
  if(tree == NULL)
  {
    return;
  }
  
  tree_destroy(tree -> left);
  tree_destroy(tree -> right);
  
  free(tree);
}


HuffNode * create_character_tree(FILE * input_file_ptr)
{
  int flag = 0;
  
  Stack * top = NULL;
  char ch;
  char chardata;
  
  HuffNode * rc;
  HuffNode * lc;
  HuffNode * new;
  
  while(flag == 0)
  {
    ch = fgetc(input_file_ptr);
    
    if(ch == '1')
    {
      chardata = fgetc(input_file_ptr);
      
      top = push_stack(top, create_HuffmanNode(chardata));
    }
    
    if(ch == '0')
    {
      rc = top -> node;
      top = pop_stack(top);
      
      if(top == NULL)
      {
	flag = 1;
      }
      else
      {
	lc = top -> node;
	
	new = create_HuffmanNode(0);
	new -> right = rc;
	new -> left = lc;
	
	top = pop_stack(top);
	top = push_stack(top, new);
      }
    }
  }
  
  return rc;
}



HuffNode * load_header(FILE * input_file_ptr)
{
  char ch = '0';
  int initial = 1;
  
  fseek(input_file_ptr, 0, SEEK_SET);
  
  Stack * top2 = NULL;

  while((ch = get_bits(input_file_ptr, 1) != 0) || (initial == 1) || top2 -> next != NULL)
  {
    initial = 0;
    
    if(ch == '1')
    {
      ch = get_bits(input_file_ptr, 8)
      
      top2 = push_stack(NULL, top2);
      
      top2 -> node = create_HuffmanNode(ch);
    }
    
    if(ch == '0')
    {
      HuffNode * node = create_HuffmanNode(0);
      
      node -> right = top2 -> node;
      top2 = pop_stack(top2);
      node -> left = top2 -> node;
      
      top2 = pop_stack(top2);
      top2 = push_stack(node, top2);
    }
  }
  
  Stack * temp = top2;
  free(top2);
  
  return temp -> node;
}      
      



char get_bits(FILE * input_file_ptr, int number)
{
  char ch;
  int counter;
  char read_bits;
  
  if(counter == 0)
  {
    fread(&ch, 1, 1, input_file_ptr)
    counter = 8;
  }
  
  if(counter < number)
  {
    read_bits = ch;
    read_bits = (read_bits << (8 - counter));
    fread(&ch, 1, 1, input_file_ptr);
    read_bits = (read_bits | (ch >> counter));
    
    return read_bits;
  }
  
  read_bits = ch;
  
  if(number == 1)
  {
    read_bits = (read_bits >> (counter - number)) & 0x01;
    counter--;
  }
  else
  {
    read_bits = (read_bits >> (counter - number));
    counter = 0;
  }
  
  return read_bits;
}
  
 
  

  




void Huff_postOrderPrint(HuffNode * tree, FILE * output_file_ptr)
{
    // Base case: empty subtree
    if (tree == NULL) 
    {
	return;
    }

    // Recursive case: post-order traversal

    // Visit left
    fprintf(output_file_ptr, "Left\n");
    
    Huff_postOrderPrint(tree -> left, output_file_ptr);
	fprintf(output_file_ptr, "Back\n");
    
	// Visit right
    fprintf(output_file_ptr, "Right\n");
    
    Huff_postOrderPrint(tree -> right, output_file_ptr);
	fprintf(output_file_ptr, "Back\n");
    
	// Visit node itself (only if leaf)
    if (tree -> left == NULL && tree -> right == NULL) 
    {
	fprintf(output_file_ptr, "Leaf: %c\n", tree -> value);
    }
    

}
