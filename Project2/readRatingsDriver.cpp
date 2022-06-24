// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 7
#include <fstream>
#include <iostream>
#include <cmath>
#include"User.h"
using namespace std;

//Just the split function from before
int split (string toBeSplit, char delim, string arr[], int size){
    int lastPos = 0;
    int arryPosition=0;
    int length = toBeSplit.length();
    for (int i = 0; i < length; i++){
        if (arryPosition >= size){
            return -1;
        }
        else if (toBeSplit[i]==delim){
            arr[arryPosition] = toBeSplit.substr(lastPos,i-lastPos);
            arryPosition = arryPosition+1;
            lastPos=i+1;
        }
        else if (i == length-1){
            arr[arryPosition] = toBeSplit.substr(lastPos);
            arryPosition = arryPosition+1;
            lastPos=i+1;
        }
    }
    //returns the number of things in the array
    return arryPosition;
}
//This function takes in a file name, a User array, takes in the ammout of users stored in the array, the size of the array, and an ammount 
//of book columns.
int readRatings(string filename, User users[], int numUsersStored, int userArrSize, int maxCol)
{
    ifstream file;
    User temp;
    string line;
    string tempArr[51];
    int size=51;
    file.open(filename);
    int thingsInArray;
    maxCol=50;
    //If the number of users stored is greater than or equal to the array size, it returns -2.
    if(numUsersStored>=userArrSize)
    {
        return -2;
    }
    //If the file fails to work it returns -1.
    else if(file.fail())
    {
        return -1;
    }
    //Otherwise it will move on to reading the file and assigning values.
    else
    {
        while(getline(file,line))
        {
            //This if statment is here just to handle blank lines in files.
            if(line=="")
            {
                //Do nothing
            }
            //If the line isn't blank it assigns a temp array and then a temp user then a user in the array, with a name, and a set of ratings.
            else
            {
                thingsInArray=split(line,',',tempArr,size);
                temp.setUsername(tempArr[0]);
                temp.setNumRatings(thingsInArray-1);
                for(int i=1;i<thingsInArray;i++)
                {
                    temp.setRatingAt(i-1,stoi(tempArr[i]));
                }
                users[numUsersStored]=temp;
                numUsersStored++;
                //This is here to make sure that the loop won't add more useres then the array can fit.
                if (numUsersStored>=userArrSize)
                {
                    return numUsersStored;
                }
            } 
        }
        //At the end the number of useres stored is returned.
        return numUsersStored;
    }
}

//This main function doesn't do anything, it is just here right now.
int main()
{
    User users[100];
    readRatings("ratings.txt",users,0,100,50);
    cout<<users[12].getUsername();
    return 0;
}