/**********************************************
*  Filename: operation.c
*  Description: declare vector operations
*  Author: Ava Latoria
*  Date: 10/1/26
**********************************************/

typedef struct
{
    char name[20];
    double x;
    double y;
    double z;
} vect;

vect add(vect a, vect b);

vect subtract(vect a, vect b);

vect multiply(vect a, double scalar);