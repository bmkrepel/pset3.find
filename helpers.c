/**
 * helpers.c
 * 
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // do binary search to see if value is in values[]
    int min = 0;
    int max = n -1;
    
    if (binarySearch(value, values, min, max))
    {
        return 1;
    }
    else
        return 0;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // selection sort
    for (int i = 0; i <= n - 1; i++)
    {
        int min = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[min])
            {
                min = j;
            }
           
        }
        if (min != i)
        {

            int tmp = values[min];
            values[min] = values[i];
            values[i] = tmp;
        } 
    }
    return;
}

/**
 * implements binary search
 */
int binarySearch(int key, int array[], int min, int max)
{
    // verify array has values left
    if (min > max)
    {
        return 0;
    }
    else
    {
        // calculate midpoint
        int midpoint = (max + min) / 2;
        
        // if midpoint value is less than key, search left
        if (array[midpoint] > key)
        {
            binarySearch(key, array, min, midpoint - 1);
        }
        // if midpoint value is greater than key, search right
        else if (array[midpoint] < key)
        {
            binarySearch(key, array, midpoint + 1, max);
        }
        // otherwise, value is key
        else
            return 1;
    }
    
    return 0; 
}


