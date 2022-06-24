//CSCI 1300 Fall 2020
//Author: Matthew Mayer
//Recitation: 518
//Homework 2 - Problem #1

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int population;
    cout << "Enter the current population:" << endl;
    cin>> population;
    //add for births
    population = population + (31536000/8);
    //subtract for deaths
    population = population - (31536000/12);
    // add for immigration
    population = population + (31536000/27);
    cout << "The population in one year: " <<population;
    return 0;
}