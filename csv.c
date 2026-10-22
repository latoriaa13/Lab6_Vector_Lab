/**********************************************
*  Filename: csv.c
*  Description: define csv functions
*  Author: Ava Latoria
*  Date: 10/15/26
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "csv.h"

void savecsv(char *fname)
{
    FILE *file;
    int i;
    vect v;

    file = fopen(fname, "w");

    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    for(i = 0; i < getvectcount(); i++)
    {
        v = getvect(i);

        fprintf(file,
                "%s,%f,%f,%f\n",
                v.name,
                v.x,
                v.y,
                v.z);
    }

    fclose(file);
}

void loadcsv(char *fname)
{
    FILE *file;
    char line[100];

    vect v;

    file = fopen(fname, "r");
    
    if(file == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    clearvects();

    while(fgets(line, sizeof(line), file))
    {
        sscanf (line,
               "%[^,],%lf,%lf,%lf",
               v.name,
               &v.x,
               &v.y,
               &v.z);

        addvect(v);
    }

    fclose(file);
}