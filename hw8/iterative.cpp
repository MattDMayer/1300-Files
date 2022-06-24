// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 8 - Problem 3
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

string decimalToBinaryIterative(int start)
{
    vector<int> binary;
    string end;
    int division=start;
    //Uses this loop to put the zeroes and ones of binary into a vector for later printing.
    while(division!=0)
    { 
        binary.push_back(division%2);
        //Here division is divided by two to work through the decimal number.
        division=division/2;
    }
    for(int i=binary.size()-1;i>=0;i--)
    {
        end+=to_string(binary[i]);
    }
    //This if statement is here just to handle the decimal input being zero.
    if(start==0)
    {
        return "0";
    }
    return end;
}

int main()
{
    //Main just tests the function.
    cout<<decimalToBinaryIterative(18);
    return 0;
}