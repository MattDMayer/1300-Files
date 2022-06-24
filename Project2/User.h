// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 6

#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User
{
    private:
        string username;
        int numRatings;
        static const int size = 50;
        int ratings[50];
    public:
        User();
        User(string username, int ratings[], int numRatings);  
        string getUsername();
        void setUsername(string name);
        int getRatingAt(int index);
        bool setRatingAt(int index, int value);
        int getNumRatings();
        void setNumRatings(int input);
        int getSize();
};
#endif