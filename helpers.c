/**
 * helpers.c
 * 
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // do binary search to see if value is in values[]
    int min = 0;
    int max = n -1;
    binarySearch(value, values, min, max);
    
    // This may need to be taken out
    return -1;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[min])
            {
                min = j;
            }
            if (min != i)
            {

                int tmp = values[min];
                values[min] = values[i];
                values[i] = tmp;
            } 
        }
    }
    return;
}

/**
 * implements binary search
 */
bool binarySearch(int key, int array[], int min, int max)
{

    if (max < min)
    {
        return -1;
    }
    else
    {
        int midpoint = (min + max) / 2;
                
        if (array[midpoint] < key)
        {
            binarySearch(key, &array[midpoint], midpoint + 1, max);
        }
        else if (array[midpoint] > key)
        {
            binarySearch(key, &array[midpoint], min, midpoint - 1);
        }
        else
            return midpoint;
    }
    //may have to take this out
    return -1;
}
