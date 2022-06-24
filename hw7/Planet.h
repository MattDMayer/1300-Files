// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 1 & 2
#include <iostream>
using namespace std;
//Below is just defining the functions and variables that the Planet class will use as defined in the instructions
//for problem one.
class Planet
{
    public:
    Planet();
    Planet(string planetName, double planetRadius);
    string getName();
    void setName(string planetName);
    double getRadius();
    void setRadius(double planetRadius);
    double getVolume();
    private:
    string planetName;
    double planetRadius;
};