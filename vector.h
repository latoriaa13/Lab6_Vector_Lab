/**********************************************
*  Filename: vector.h
*  Description: declare vector storage functions
*  Author: Ava Latoria
*  Date: 10/1/26
**********************************************/

#include "operation.h"

#define MAX_VECTORS 10

int addvect(vect newvect);

int findvect(char *name);

vect getvect(int index);

void clearvects(void);

int getvectcount(void);
