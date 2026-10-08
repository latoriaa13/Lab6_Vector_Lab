/**********************************************
*  Filename: operation.c
*  Description: define vector operations
*  Author: Ava Latoria
*  Date: 10/1/26
**********************************************/

#include "operation.h"

vect add(vect a, vect b)
{
    vect result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

vect subtract(vect a, vect b)
{
    vect result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    
    return result;
}

vect multiply(vect a, double scalar)
{
    vect result;

    result.x = a.x * scalar;
    result.y = a.y * scalar;
    result.z = a.z * scalar;

    return result;
}