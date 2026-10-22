/**********************************************
*  Filename: myveclab.c
*  Description: 3D vector calculator with help funcitons
*  Author: Ava Latoria
*  Date: 10/1/26
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "csv.h"
#include "calculator.h"
#include "functions.h"

int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
    {
        help();
        return 0;
    }

    if (argc > 1)
    {
        printf("Invalid command line argument.\n");
        return 1;
    }

    calculator();

    clearvects();

    return 0;
}