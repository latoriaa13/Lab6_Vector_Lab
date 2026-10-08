/**********************************************
*  Filename: vector.c
*  Description: define vector storage
*  Author: Ava Latoria
*  Date: 10/1/26
**********************************************/

#include <string.h>
#include "vector.h"

static vect vectors[MAX_VECTORS];
static int vector_count = 0;

int findvect(char *name)
{
    int i;

    for (i = 0; i < vector_count; i++)
    {
        if (strcmp(vectors[i].name, name) == 0)
        {
            return i;
        }
    }

    return -1;
}


int addvect(vect newvect)
{
    int index;

    index = findvect(newvect.name);

    // Vector already exists
    if (index >= 0)
    {
        vectors[index] = newvect;
        return index;
    }

    // No more room  
    if (vector_count >= MAX_VECTORS)
    {
        return -1;
    }
    
    vectors[vector_count] = newvect;
    vector_count++;

    return vector_count - 1;
}


vect getvect(int index)
{
    return vectors[index];
}


void clearvects(void)
{
    vector_count = 0;
}


int getvectcount(void)
{
    return vector_count;
}
