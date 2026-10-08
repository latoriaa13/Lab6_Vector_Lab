/**********************************************
*  Filename: myveclab.c
*  Description: 3D vector calculator
*  Author: Ava Latoria
*  Date: 10/1/26
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

// prints 1 vector
void printvect(vect v)
{
    printf("%s = %.2f  %.2f  %.2f\n",
           v.name, v.x, v.y, v.z);
}

// prints all stored vectors
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


// handles user input and vector commands
void calculator(void)
{
    char input[100];

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
                    printf("Vector memory is full.\n");
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
                    printf("Vector memory is full.\n");
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

// main
int main(int argc, char *argv[])
{
    // help
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
    {
        help();
        return 0;
    }

    // invalid command
    if (argc > 1)
    {
        printf("Invalid command line argument.\n");
        printf("Use -h for help.\n");
        return 1;
    }

    calculator();

    return 0;
}
