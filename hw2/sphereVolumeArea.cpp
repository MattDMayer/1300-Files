//CSCI 1300 Fall 2020
//Author: Matthew Mayer
//Recitation: 518
//Homework 2 - Problem #1

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double radius;
    cout << "Enter a radius:" << endl;
    cin >> radius;
    double volume;
    const double FOURTHIRDS = (double)4/3;
    volume= pow(radius,3)*M_PI*FOURTHIRDS;
    cout << "Volume: " << setprecision(6)<< volume;
    double surfaceArea=  4*M_PI*pow(radius, 2);
    cout << endl << "Surface area: " <<setprecision(6)<< surfaceArea;
    return 0;
}