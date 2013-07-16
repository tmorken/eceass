/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * For this assignment, you must use qsort and give appropriate
 * comparison functions.
 *
 * You can assume that the input files have no empty lines and the
 * last line ends with '\n'.  You can count the number of lines by
 * counting the occurrences of '\n'.
 *
 * Hint: 
 * You can write additonal functions.
 *
 */

#include "pa02.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INT     0
#define STRING  1
#define FAILURE 0
#define SUCCESS 1
#define MAXLEN 80

/*
 * =================================================================
 * read the integers from the file whose name is inName
 * sort the integers
 * stored the sorted integers in the file whose name is outName
 */


static int compare(const void * p1, const void * p2)
{
  const int * intptr1 = (int *) p1;
  const int * intptr2 = (int *) p2;
  int intv1 = * intptr1;
  int intv2 = * intptr2;
  
  if(intv1 == intv2)
  {
    return 0;
  }
  
  if(intv1 > intv2)
  {
    return 1;
  }
  
  if(intv1 < intv2)
  {
    return -1;
  }
}



char memChar(





/*static char compare2(const void * p1, const void * p2)
{
  return strcmp(*(char **) p1, *(char **) p2);
}
*/


int lineCounter(int fptr)
{
  int temp;
  int numLines;
  
  numLines = 0;
  
  while((temp = getc(fptr)) != EOF)
  {
    if(temp == '\n')
    {
      numLines++;
    }
  }
  
  fclose(fptr);
  
  return(numLines);
}


void sortInt(char * inName, char * outName)
{
  
  FILE * fptr1;
  FILE * fptr2;
  
  fptr1 = fopen(inName, 'r');
  fptr2 = fopen(outName, 'w');
  
  int numLines;
  int iter;
  
  int * arr1;
  
  numLines = lineCounter(fptr1);
  
  arr1 = malloc(numLines * sizeof(int *);
  
  for(iter = 0; iter < numLines; iter++)
  {
    arr1 = malloc(MAXLEN * sizeof(int));
  }
  
  
  qsort(arr1, numLines, sizeof(int), compare1);      
}

/*
 * =================================================================
 * read the strings from the file whose name is inName
 * sort the strings
 * stored the sorted strings in the file whose name is outName
 *
 * The strings are sorted by ASCII order (using strcmp). Thus, 'B' will
 * appear before 'a'.
 */

void sortString(char * inName, char * outName)
{
}
