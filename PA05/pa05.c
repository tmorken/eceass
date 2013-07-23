#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa05.h"



int main(int argc, char * argv[])
{
  char length;
  HuffNode * tree;
  
  if(argc != 3)
  {
    printf("Not enough input arguments.");
    
    return EXIT_FAILURE;
  }
  
  FILE * input_file_ptr = fopen(argv[1], "r");
  FILE * output_file_ptr = fopen(argv[2], "w");
  
  if(input_file_ptr == NULL)
  {
    printf("The input file does not exist.");
    
    return EXIT_FAILURE;
  }
  
  
  if(output_file_ptr == NULL)
  {
    printf("The output file does not exist.");
    
    return EXIT_FAILURE;
  }
 
  
  length = strlen(argv[1]);
  
  if(argv[1][length - 1] == 'h')
  {
    tree = create_character_tree(input_file_ptr);
    Huff_postOrderPrint(tree, output_file_ptr);
  }
  else
  {
    //tree = create_bit_tree(input_file_ptr);  //is this the same?
    //print function?
  }
  
  
  if(argv[1][length - 1] == 't')
  {
    tree = load_header(FILE * input_file_ptr)
    //Huff_postOrderPrint(tree, output_file_ptr);
  }
  
 
 tree_destroy(tree);
 
 fclose(input_file_ptr);
 fclose(output_file_ptr);
 
 return EXIT_SUCCESS;
 
}
  
  