/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // validate that the user enters one or two command line arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // set int "n" equal to argv[1] and convert argv[1] from string to an int
    int n = atoi(argv[1]);

    // if there is a second arg, use the it to seed function rand otherwise seed with 1
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    // print n number of random characters on their own line
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }

    // that's all folks
    return 0;
}
