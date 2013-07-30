
/**
 * The ENTIRE assignment should be completed within this file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#include "pa06.h"

void * prime_test(void * balls);

typedef struct prime
{
  int prime_status;
  uint128 start;
  uint128 end;
  uint128 value;
}prime_object;

/**
 * Read a uint128 from a string.
 * This function is provided for your convenience.
 */
uint128 alphaTou128(const char * str)
{
    uint128 ret = 0;
    while(*str >= '0' && *str <= '9') {
	ret *= 10; // "left-shift" a base-ten number
	ret += (*str - '0'); // add in the units
	++str;
    }
    return ret;
}




/**
 * The caller is responsible for freeing the result 
 */
char * u128ToString(uint128 value)
{
  int i;
  int length = 0;
  int digit;
  
  uint128 temp = value;
  
  while(temp > 0)
  {
    temp /= 10;
    length++;
  }
  
  temp = value;
  
  char * string = malloc(sizeof(char) * (length + 1));
  string[length] = '\0';
  
  for(i = length - 1; i >= 0; i--)
  {
    digit = temp % 10;
    string[i] = digit + '0';
    temp /= 10;
  }
  
  return string;
}






/**
 * Test is 'value' is prime.
 * 'n_threads' is the number of threads to create to complete this computation.
 * Return TRUE of FALSE.
 * 
 * LEAK NO MEMORY
 *
 * Good luck!
 */
int primalityTestParallel(uint128 value, int n_threads)
{
  int status = 0; 
  
  if(value == 1 || value == 2 || value == 3)
  {
    //status = TRUE;
    
    //return status;
    return TRUE;
  }
  
  
  if(value % 2 == 0)
  {    
    //status = FALSE;
    
    //return status;
    return FALSE;
  }
  
  uint128 i;
  uint128 j;
  uint128 k;
  
  uint128 max = floor(sqrt(value));
  uint128 chunk = (max + n_threads + 1) / n_threads;
  
  prime_object * thread_instance = malloc(sizeof(prime_object) * n_threads);
  pthread_attr_t * attribute = malloc(sizeof(pthread_attr_t) * n_threads);
  pthread_t * thread = malloc(sizeof(pthread_t) * n_threads);

  for(i = 0; i < n_threads; i++)
  {
    thread_instance[i].start = i * chunk;
    thread_instance[i].end = (i + 1) * chunk - 1;
    thread_instance[i].value = value;
    
    if(thread_instance[i].start < 3)
    {
      thread_instance[i].start = 3;
    }
    else if((thread_instance[i].start % 2) == 0)
    {
      thread_instance[i].start += 1;
    }
    
    pthread_attr_init(&attribute[i]);  
    pthread_create(&thread[i], &attribute[i], prime_test , (void *)&thread_instance[i]);
  }
  
  for(j = 0; j < n_threads; j++)
  {
    pthread_join(thread[j], NULL);
  }
  
  status = TRUE;
  
  for(k = 0; k < n_threads; k++)
  { 
    //printf("\nhey guys WUTWUT\n");
    if(thread_instance[k].prime_status != 1)
    {
      //printf("\ninner for loop, FALSE BITCHES\n");
      status = FALSE;	
      k = n_threads;
    }
    //printf("\n\nTRUE BITCHES\n\n");
    //status = TRUE;
  }

  free(thread);
  free(attribute);
  free(thread_instance);
  
  return status;
}
      
      
void * prime_test(void * thread_instance)
{
  uint128 i;
  
  prime_object * test = (prime_object *)thread_instance;
  
  for(i = (test -> start); i <= (test -> end); i += 2)
  {
    if((test -> value % i) == 0)
    {
      
      test -> prime_status = FALSE;
      //thing -> prime_status = test -> prime_status;
      //printf("FALSE\n\n\n\n\n\n\n");
      return NULL;
    }
  }
  
  test -> prime_status = TRUE;

  
  return NULL;//thing -> prime_status;
}
      
    

