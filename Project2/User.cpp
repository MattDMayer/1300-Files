// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 6

#include <iostream>
#include <cmath>
#include "User.h"
using namespace std;

 User::User(){
    username = "";
    numRatings = 0;
    for (int i = 0; i < size; i++){
        ratings[i] = 0;
    }
}

User::User(string myUsername, int myRatings[], int myNumRatings){
    if (myNumRatings > size){
        cout << "Too many books. Try again with less books." << endl;
    }
    else{
        username = myUsername;
        numRatings = myNumRatings;
        for (int i = 0; i < myNumRatings; i++){
            ratings[i] = myRatings[i];
        }
    }
}

string User::getUsername(){
    return username;
}

void User::setUsername(string myUsername){
    username = myUsername;
}

int User::getRatingAt(int myIndex){
    if ((myIndex < 0) || (myIndex > size-1)){
        return -1;
    }
    else
    {
        return ratings[myIndex];
    }
}

bool User::setRatingAt(int myIndex, int myValue){
    if ((myIndex >= 0) && (myIndex < size) && (myValue >= 0) && (myValue <= 5)){
        ratings[myIndex] = myValue;
        return true;
    }
    else{
        return false;
    }
}

int User::getNumRatings(){
    return numRatings;
}

void User::setNumRatings(int myInput){
    numRatings = myInput;
}

int User::getSize(){
    return size;
}