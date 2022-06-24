// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 5 - Problem 3

#include <iostream>
#include <iomanip>
using namespace std;

/*
The insert function takes in a string with ascending values, the ammount of spaces in that array with data, the total amount of cells
in the array, and a number to be inserted into the array. The function first checks to see if there is space to add another cell of data
into the array. If all indexes of the array are already full. The function just returns the total size of the array, as that is the amount
of elements in the array. Otherwise the code goes through trying to find which index the insertion belongs to, it will then go through the
array again, although this time it traverses the array backwards. It moves each piece of data after the insertion up 1 index, then adds
the insertion, and then just sets the rest of the array equal to its previous self. With this the function has added to the array and will
return the amount of cells that the array has.
*/

int insert(int ascending[], int numInArray, int totalSize, int insertion)
{
    int other[numInArray+1];
    int index=0;
    if(totalSize==numInArray)
    {
        return totalSize;
    }
    else
    {
        int index=0;
        for(int i=0;i<numInArray;i++)
        {
            if (insertion>ascending[i])
            {
                index++;
            }
        }
        for(int j=numInArray;j>-1;j--)
        {
            if(j<index)
            {
                ascending[j]=ascending[j];
            }
            else if(j==index)
            {
                ascending[j]=insertion;
            }
            else
            {
                ascending[j]=ascending[j-1];
            }
        }
        return numInArray+1;
    }
}

// The main function isn't very special, it literally does nothing.
int main()
{
    return 0;
}