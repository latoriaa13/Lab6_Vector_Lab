/**********************************************
*  Filename: functions.c
*  Description: define functions
*  Author: Ava Latoria
*  Date: 10/15/26
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "vector.h"

void listvects(void)
{
    int i;

    if (getvectcount() == 0)
    {
        printf("No vectors stored.\n");
        return;
    }

    for (i = 0; i < getvectcount(); i++)
    {
        printvect(getvect(i));
    }
}


// displays program help info
void help(void)
{
    printf("MiniMat Vector Calculator\n\n");

    printf("Commands:\n");
    printf("  a = 1 2 3\n");
    printf("  a = 1,2,3\n");
    printf("  a + b\n");
    printf("  a - b\n");
    printf("  a * 2\n");
    printf("  2 * a\n");
    printf("  c = a + b\n");
    printf("  list\n");
    printf("  clear\n");
    printf("  quit\n");
}