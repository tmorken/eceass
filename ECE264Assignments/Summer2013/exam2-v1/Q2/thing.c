#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "thing.h"

Thing Thing_construct(int w, char *l)
{
    // FILL IN CODE HERE!
}

Thing Thing_copy(Thing p)
{
    // FILL IN CODE HERE!
}

void Thing_merge(Thing *dst, Thing src)
{
    // FILL IN CODE HERE!
}

void Thing_destroy(Thing p)
{
    // FILL IN CODE HERE!
}

// -- DO NOT CHANGE THE BELOW CODE!
void Thing_print(Thing p)
{
    printf("weight = %d, label = %s\n", p.weight, p.label);
}

