/**********************************************
*  Filename: vector.c
*  Description: define vector storage
*  Author: Ava Latoria
*  Date: 10/1/26
**********************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

static vect *vectors = NULL;
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

    vect *temp;

    index = findvect(newvect.name);

    // vector exists
    if (index >= 0)
    {
        vectors[index] = newvect;

        return index;
    }

    // first vector 
    if (vector_count == 0)
    {
        vectors = malloc(sizeof(vect));

        if (vectors == NULL)
        {
            return -1;
        }
    }
    else
    {
        temp = realloc(vectors,
                       (vector_count + 1) * sizeof(vect));

        if (temp == NULL)
        {
            return -1;
        }

        vectors = temp;
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
    free(vectors);

    vectors = NULL;

    vector_count = 0;
}

int getvectcount(void)
{
    return vector_count;
}

void printvect(vect v)
{
    printf("%s = %.2f %.2f %.2f\n",
           v.name,
           v.x,
           v.y,
           v.z);
}