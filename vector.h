/**********************************************
*  Filename: vector.h
*  Description: declare vector storage functions
*  Author: Ava Latoria
*  Date: 10/1/26
**********************************************/

#include "operation.h"

int addvect(vect newvect);

int findvect(char *name);

vect getvect(int index);

void clearvects(void);

int getvectcount(void);

void printvect(vect v);
