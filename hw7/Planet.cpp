// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 1 & 2
#include <iostream>
#include "Planet.h"
#include <cmath>
using namespace std;
//Here is a constructor for a planet with no called name or radius, just setting some default values.
Planet::Planet()
{
    planetName="";
    planetRadius=0.0;
}
//Here is a constructor so the planet can be called with data for its name and radius.
Planet::Planet(string setName, double setRadius)
{
    planetName=setName;
    planetRadius=setRadius;
}
//Here is a function for returning the planet's name.
string Planet::getName()
{
    return planetName;
}
//Here is a function for setting a new name of the planet.
void Planet::setName(string newName)
{
    planetName=newName;
}
// This is a double function which just returns the private data of the planet's radius.
double Planet::getRadius()
{
    return planetRadius;
}
//This is just a function to set a new radius for the planet after it has been created.
void Planet::setRadius(double newRadius)
{
    planetRadius=newRadius;
}
//This function just uses a little bit of math to get the volume of the planet from its radius.
double Planet::getVolume()
{
    double volume=0.0;
    const double FOURTHIRDS= double(4.0/3.0);
    volume=pow(planetRadius,3)*FOURTHIRDS*M_PI;
    return volume;
}