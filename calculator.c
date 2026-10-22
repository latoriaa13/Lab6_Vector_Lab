/**********************************************
*  Filename: calculator.c
*  Description: define calculator function
*  Author: Ava Latoria
*  Date: 10/15/26
**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculator.h"
#include "csv.h"
#include "vector.h"
#include "functions.h"

void calculator(void)
{
    char input[256];

    while (1)
    {
        char *token1;
        char *token2;
        char *token3;
        char *token4;
        char *token5;

        vect v1;
        vect v2;
        vect result;

        int index1;
        int index2;

        printf("minimat> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        // first token
        token1 = strtok(input, " ,\n");

        if (token1 == NULL)
        {
            continue;
        }


        // quit
        if (strcmp(token1, "quit") == 0)
        {
            break;
        }

        // save to csv
        if (strcmp(token1, "save") == 0)
        {
            token2 = strtok(NULL, " \n");
            
            if (token2 == NULL)
            {
                printf("Usage: save filename.csv\n");
            }
            else
            {
                savecsv(token2);
            }

            continue;
        }

        // load from CSV
        if (strcmp(token1, "load") == 0)
        {
            token2 = strtok(NULL, " \n");
            
            if (token2 == NULL)
            {
                printf("Usage: load filename.csv\n");
            }
            else
            {
                loadcsv(token2);
            }

            continue;
        }


        // clear
        if (strcmp(token1, "clear") == 0)
        {
            clearvects();
            printf("Vector memory cleared.\n");
            continue;
        }


        // list
        if (strcmp(token1, "list") == 0)
        {
            listvects();
            continue;
        }


        // other tokens
        token2 = strtok(NULL, " ,\n");
        token3 = strtok(NULL, " ,\n");
        token4 = strtok(NULL, " ,\n");
        token5 = strtok(NULL, " ,\n");

        strcpy(v1.name, token1);

        // display a vector
        if (!token2)
        {
            int veci = findvect(token1);

            if (veci >= 0)
            {
                printvect(getvect(veci));
            }
            else
            {
                printf("Vector %s does not exist.\n", token1);
            }

            continue;
        }

        // assignment
        if (strcmp(token2, "=") == 0)
        {
            if (token3 == NULL)
            {
                printf("Invalid assignment.\n");
                continue;
            }

            // direct assignment
            if (token4 != NULL &&
                token5 != NULL &&
                strcmp(token4, "+") != 0 &&
                strcmp(token4, "-") != 0 &&
                strcmp(token4, "*") != 0)
            {
                v1.x = atof(token3);
                v1.y = atof(token4);
                v1.z = atof(token5);

                if (addvect(v1) < 0)
                {
                    printf("Unable to allocate memory.\n");
                }
                else
                {
                    printvect(v1);
                }

                continue;
            }


            /**********************************
            * Operation with assignment
            * c = a + b
            * c = a - b
            * c = a * 2
            **********************************/
            if (token4 != NULL && token5 != NULL)
            {
                index1 = findvect(token3);

                if (index1 < 0)
                {
                    printf("Vector %s does not exist.\n", token3);
                    continue;
                }

                v2 = getvect(index1);


                // Addition
                if (strcmp(token4, "+") == 0)
                {
                    index2 = findvect(token5);

                    if (index2 < 0)
                    {
                        printf("Vector %s does not exist.\n", token5);
                        continue;
                    }

                    result = add(v2, getvect(index2));
                }

                
                // Subtraction
                else if (strcmp(token4, "-") == 0)
                {
                    index2 = findvect(token5);

                    if (index2 < 0)
                    {
                        printf("Vector %s does not exist.\n", token5);
                        continue;
                    }

                    result = subtract(v2, getvect(index2));
                }


                // Scalar multiplication
                else if (strcmp(token4, "*") == 0)
                {
                    result = multiply(v2, atof(token5));
                }


                else
                {
                    printf("Invalid operation.\n");
                    continue;
                }


                // Give result the new vector name
                strcpy(result.name, token1);

                if (addvect(result) < 0)
                {
                    printf("Unable to allocate memory.\n");
                }
                else
                {
                    printvect(result);
                }

                continue;
            }


            printf("Invalid assignment.\n");
            continue;
        }


        // Operations without assignment
        if (token3 != NULL)
        {
            index1 = findvect(token1);

            if (index1 >= 0)
            {
                v1 = getvect(index1);


                // Addition
                if (strcmp(token2, "+") == 0)
                {
                    index2 = findvect(token3);

                    if (index2 < 0)
                    {
                        printf("Vector %s does not exist.\n", token3);
                        continue;
                    }

                    result = add(v1, getvect(index2));
                }


                // Subtraction
                else if (strcmp(token2, "-") == 0)
                {
                    index2 = findvect(token3);

                    if (index2 < 0)
                    {
                        printf("Vector %s does not exist.\n", token3);
                        continue;
                    }

                    result = subtract(v1, getvect(index2));
                }


                // Scalar multiplication
                else if (strcmp(token2, "*") == 0)
                {
                    result = multiply(v1, atof(token3));
                }


                else
                {
                    printf("Invalid operation.\n");
                    continue;
                }


                strcpy(result.name, "ans");
                printvect(result);

                continue;
            }


            // Scalar multiplication
            if (strcmp(token2, "*") == 0)
            {
                index2 = findvect(token3);

                if (index2 >= 0)
                {
                    result = multiply(getvect(index2),
                                      atof(token1));

                    strcpy(result.name, "ans");

                    printvect(result);

                    continue;
                }
            }
        }


        // If nothing matched
        printf("Invalid command.\n");
    }
}