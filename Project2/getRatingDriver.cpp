// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 8
#include <fstream>
#include <iostream>
#include <cmath>
#include"User.h"
#include"Book.h"
using namespace std;

//Made a function to make all characters lowercase in a string to make it so the searching isn't case sensitive.
string lowercase(string toBeLowered)
{
    int length = toBeLowered.length();
    for (int i = 0; i < length; i++)
    {
        toBeLowered[i]=tolower(toBeLowered[i]);
    }
    return toBeLowered;
}
//Function basically finds the value of where the book is in the array, if it doesn't exist it returns -3, otherwise the program moves on and
//see if the reviewer name exists. If it doesn't it returns -3. If both things exist it looks for the user's review score at the location 
//where the book was initially found and the function returns that.
int getRating(string username,string titleOfBook,User users[],Book books[],int numOfUsers, int numOfBooks)
{
    int tempPosBook = -1;
    string tempBook;
    for (int i = 0; i < numOfBooks; i++)
    {
        if (lowercase(titleOfBook) == lowercase(books[i].getTitle()))
        {
            tempPosBook = i;
            tempBook = titleOfBook;
            break;
        }
    }
    if(tempPosBook==-1)
    {
        return-3;
    }
    for (int i = 0; i < numOfUsers; i++)
    {
        if (lowercase(username) == lowercase(users[i].getUsername()))
        {
            return users[i].getRatingAt(tempPosBook);
        }
    }
    return -3;
}

//This main function doesn't do anything, it is just here right now.
int main()
{
    return 0;
}