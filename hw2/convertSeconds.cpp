//CSCI 1300 Fall 2020
//Author: Matthew Mayer
//Recitation: 518
//Homework 2 - Problem #1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int seconds;
    cout << "Enter a number of seconds:" << endl;
    cin >> seconds;
    int hours =0 ;
    int minutes=0;
    int converter;
    if (seconds >= 3600)
    {
        converter = seconds / 3600;
        hours = converter;
        seconds = seconds - (3600 * converter);
    }
    if ( seconds >= 60)
    {
        converter = seconds / 60;
        minutes = converter;
        seconds = seconds - (60 * converter);
    }
    cout << hours << " hour(s) " << minutes << " minute(s) " <<  seconds << " second(s)"<< endl;
    return 0;
}