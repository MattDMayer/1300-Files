// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 2
#include <iostream>
#include "Planet.h"
using namespace std;

//This function is a type int and takes in an array of planets with a size of how many planets go in the array.
//After declaring variables it checks to see if size is 0, if it is it returns -1, if not for the size taken into the function
//There will be a for loop where the function compares the smallest radius to the radius of each planet, if a radius is bigger
//Than the current radius, the radius is set to the bigger one, and the biggest index is set to that planet, after this loop
//the biggest radius will have been found at a certain index, and that index will be returned.
int maxRadius(Planet planetArr[], int size)
{
    double radius=0.0;
    int biggestIndex=0;
    if(size==0)
    {
        return -1;
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            if (radius< planetArr[i].getRadius()) 
            {
                radius=planetArr[i].getRadius();
                biggestIndex=i;
            }
        }
        return biggestIndex;
    }  
}

//My main funciton here really is just a test case from code runner to make sure that my system was properly working.
int main()
{    
    Planet planets[5];
    planets[0] = Planet("On A Cob Planet",1234);
    planets[1] = Planet("Bird World",4321);
    int idx = maxRadius(planets, 2);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
    return 0;
}