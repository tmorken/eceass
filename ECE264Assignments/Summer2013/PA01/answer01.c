/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 *
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa01.h.
 */

#include "pa01.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * See the file "expected/expected_unsorted" for the output specification
 */

void printFunction(int * part, int length)
{
  int ind = 0;
  
  for(ind = 0; ind < length - 1; ind++)
  {
    printf("%d + ", part[ind]);
  }
  
  printf("%d\n", part[length - 1]);
}


void partitionAllCalc(int * result, int ind, int left)
{
  int val = 0;
  
  if(left == 0)
  {
    printf("= ");
    printFunction(result, ind);
  }
  
  for(val = 1; val <= left; val++)
  {
    result[ind] = val;
    partitionAllCalc(result, ind + 1, left - val);
  }
}


void partitionIncreasingCalc(int * result, int ind, int left)
{
  int val = 0;
  
  if(left == 0)
  {
    printf("= ");
    printFunction(result, ind);
  }
  
  for(val = 1; val <= left; val++)
  {
    result[ind] = val;
    
    if(ind == 0)
    {
      partitionIncreasingCalc(result, ind + 1, left - val);
    }
    else if(result[ind] > result[ind -1])
    {
      partitionIncreasingCalc(result, ind + 1, left - val);
    }
  }
}


void partitionUniqueCalc(int * result, int ind, int left)
{
  int val = 0;
  int i;
  int cond = 0;
  
  if(left == 0)
  {
    printf("= ");
    printFunction(result, ind);
  }
  
  for(val = 1; val <= left; val++)
  {
    result[ind] = val;
    
    for(i = 0; i < ind; i++)
    {
      if(result[i] == result[ind])
      {
	cond = 1;
      }
    }
    
    if(cond == 0)
    {
      partitionUniqueCalc(result, ind + 1, left - val);
    }
    
    cond = 0;
  }
}
  
  

  
void partHelp(int left, int designator)
{
  int arr[MAXLENGTH] = {0};
  
  if(designator == 1)
  {
    partitionAllCalc(arr, 0, left);
  }
  
  if(designator == 2)
  {
    partitionIncreasingCalc(arr, 0, left);
  }
  
  if(designator == 3)
  {
    partitionUniqueCalc(arr, 0, left);
  }
}

 
  
void partitionAll(int value)
{
  printf("partitionAll %d\n", value);
  
  partHelp(value, 1);
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void partitionIncreasing(int value)
{
  printf("partitionIncreasing %d\n", value);
  
  partHelp(value, 2);
}
/*
 * =================================================================
 * This function prints the partitions that use unique values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 3 + 2 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 are invalid partitions.
 *
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void partitionUnique(int value)
{
  printf("partitionUnique %d\n", value);

  partHelp(value, 3);
      
}

/*
 * =================================================================
 */
void printPermute(char * charset, int length)
{
  int iter;
  
  for(iter = 0; iter < length; iter++)
  {
    printf("%c ", charset[iter]);
  }
  
  printf("\n");
}

void swap(char * c1, char * c2)
{
  char t = *c1;
  *c1 = *c2;
  *c2 = t;
}

void recursivePermute(char * charset, int ind, int length)
{
  int iter;
  if(ind == length)
  {
    printPermute(charset, length);
  }
  for(iter = ind; iter < length; iter++)
  {
    swap(& charset[iter], & charset[ind]);
    recursivePermute(charset, ind + 1, length);
    swap(& charset[iter], & charset[ind]);
  }
}

void permute(char * charset, int length)
{
  printf("permute %d\n", length);
  
  recursivePermute(charset, 0, length);
}




