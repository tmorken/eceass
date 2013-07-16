#ifndef THING_H
#define THING_H
/* DO NOT CHANGE THIS FILE */
/* You must be careful about memory management.  You will receive
   50% penalty if there is memory leak. */
/* You will receive zero if the program exits abnormally (such as
   segmentation fault). */
typedef struct {
  int weight;       
  char *label;
} Thing;

/* Create a new Thing object and assign attributes.  Note that you
   must copy the contents of the label string! */
Thing Thing_construct(int weight, char *label);

/* create a new Thing object and make the attributes the same as an
   existing object. CAUTION: must use deep copy */
Thing Thing_copy(Thing t);

/* Both dest and src are objects already created.  This function makes the 
   dest's weight the sum of the the two objects' weight.
   dest's label is the concatenation of the two objects' labels.
   HINT: use strcat to concatenate two strings. */
void Thing_merge(Thing *dst, Thing src);

void Thing_print(Thing t);

/* release memory */
void Thing_destroy(Thing t);

#endif
