//CSCI 1300 Fall 2020
//Author: Matthew Mayer
//Recitation: 518
//Homework 2 - Problem #1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double tempF;
    cout << "Enter a temperature in Fahrenheit: ";
    cin>> tempF;
    double tempC;
    double factor = (double)5/9;
    tempC = factor*(tempF-32);

    cout <<endl << "The temperature " << tempF << " degrees Fahrenheit is "<< fixed<< setprecision(2)<< tempC << " degrees Celsius.";
    return 0;
}