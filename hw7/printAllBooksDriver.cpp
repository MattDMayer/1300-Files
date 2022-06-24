// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 5
#include <iostream>
#include "Book.h"
#include <fstream>
using namespace std;

//printAllBooks function checks to see if book number is positive, if it is it lists all books and authors, if it is 0 or negative, 
//it tells the user that no books are stored.
void printAllBooks(Book books[], int bookNumber)
{
    if (bookNumber<=0)
    {
        cout<<"No books are stored";
    }
    else
    {
        cout<<"Here is a list of books"<<endl;
        for(int i=0;i<bookNumber;i++)
        {
            cout<<books[i].getTitle()<<" by "<<books[i].getAuthor()<<endl;
        }
    }
}
//Didn't put anything in main function as I didn't have text files to test printAllBooks with.
int main()
{    
    
    return 0;
}