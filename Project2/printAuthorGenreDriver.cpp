// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 5
#include <iostream>
#include "Book.h"
using namespace std;

//This function basicaly just checks to see if the genre and an author first letter match. If they do it adds to a variable and puts
//the author and title into an array. Using it to print both and make the list work.
int printAuthorGenre(string genre, char firstLetter, Book books[], int numBooksStored)
{
    string convert;
    convert=firstLetter;
    int matchedBooks[numBooksStored];
    int match=0;
    for(int i=0;i<numBooksStored;i++)
    {
        if(books[i].getGenre()==genre&&(books[i].getAuthor().substr(0,1)==convert))
        {
            matchedBooks[match]=i;
            match++;
        }
    }
    //This is here if there are no matches, if there are none it returns 0 and prints out a message.
    if(match==0)
    {
        cout<<"No titles found for this genre-author pair."<<endl;
        return match;
    }
    //The else statement is here just to print and make a list of books that match.
    else
    {
        cout<<"Here is a list of books that match this genre-author pair:"<<endl;
        for(int i=0;i<match;i++)
        {
            cout<<books[matchedBooks[i]].getTitle()<<" by "<<books[matchedBooks[i]].getAuthor()<<endl;
        }
        return match;
    }
}
//Main is empty as it doesn't need to do anything.
int main()
{
    return 0;
}