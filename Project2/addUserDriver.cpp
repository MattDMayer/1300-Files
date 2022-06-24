// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 9
#include <fstream>
#include <iostream>
#include <cmath>
#include"User.h"
#include"Book.h"
using namespace std;

int addUser(string UserName, User users[], int numRatings, int numUsersStored, int userArrSize)
{
    User newUser;
    if (numUsersStored>=userArrSize)
    {
        return -2;
    }
    if(UserName=="")
    {
        return -1;
    }
    for(int i=0;i<numUsersStored;i++)
    {
        if(UserName==users[i].getUsername())
        {
            return -1;
        }
    }
    newUser.setUsername(UserName);
    users[numUsersStored]=newUser;
    return numUsersStored+1;
}

//This main function doesn't do anything, it is just here right now.
int main()
{
    return 0;
}