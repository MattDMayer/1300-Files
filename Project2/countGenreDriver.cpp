// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 4
#include <iostream>
#include "Book.h"
using namespace std;

//Count Genre function is here taking in a genre, a book array, and the numbers of books stored in the array. It loops through the book array
// looking for a genre match of a string of a genre, finding a match it adds to a number and returns it, if no matches happen, it returns 0.

int countGenre(string genre, Book books[], int numBooksStored)
{
    int genreMatch=0;
    for(int i=0;i<numBooksStored;i++)
    {
        if(books[i].getGenre()==genre)
        {
            genreMatch++;
        }
    }
    return genreMatch;
}

int main()
{
    return 0;
}