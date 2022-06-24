// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 10

#include <iostream>
#include <cmath>
#include "User.h"
#include "Book.h"
#include <iomanip>
using namespace std;

//This is function is here to detect whether or not the user's name can be found. 
User getUserIndex (string username, User users[], int numOfUsers){
    User TheChosenOne;
    User Fail("fail",0,0);
    for(int i = 0; i < numOfUsers; i++){
        if (username == users[i].getUsername()){
            TheChosenOne = users[i];
            return TheChosenOne;
        }
    }
    return Fail;
}

//Get num ratings differentiates the amount of books that are present in the array, and only reports what books have been rated by the 
//user so it looks for non 0 ratings.
int getNumOfRatingsOfUser(User user, int numOfBooks){
    int numOfRatingOfUser = 0;
    for (int i = 0; i < numOfBooks; i++){
        if (user.getRatingAt(i) > 0){
            numOfRatingOfUser = numOfRatingOfUser+1;
        }
    }
    return numOfRatingOfUser;
}

//This function is used to calculate calculate the average score of the reviewer, using their number of ratings, and ratings to do so.
double getAverageRatings (User user, int numOfBooks){
    int numOfRatingOfUser = 0;
    double average = 0;
    for (int i = 0; i < numOfBooks; i++){
        if (user.getRatingAt(i) > 0){
            numOfRatingOfUser = numOfRatingOfUser+1;
            average = user.getRatingAt(i) + average;
        }
    }
    return average = average / double(numOfRatingOfUser);
}

//This is the core get user stats function doing the job of returning a -3, if the user doesn't exist, otherwise it executes the 
//other helper functions to return the amount of books rated, and what the average rating was.
int getUserStats(string username, User users[], int numOfUsers, int numOfBooks){
    double average = 0.0;
    int numOfRatings;
    User TheOne;
    TheOne = getUserIndex(username, users, numOfUsers);
    if (TheOne.getUsername() == "fail"){
        cout << username << " does not exist." << endl;
        return -3;
    }
    else{
        numOfRatings = getNumOfRatingsOfUser(TheOne, numOfBooks);
        if (numOfRatings == 0){
            cout << TheOne.getUsername() << " has not rated any books." << endl;
            return 0;
        }
        cout << TheOne.getUsername() << " rated " << numOfRatings << " books" << endl;
        average = getAverageRatings(TheOne,numOfBooks);
        cout << fixed << setprecision(2) << TheOne.getUsername() << "'s average rating was " << average << endl;
        return 1;
    }
}

int main()
{
    return 0;
}