// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 1
#include <iostream>
#include "Planet.h"
using namespace std;

//My main function is really the main function provided for part one, but with some of the data changed a little bit
//to bug test some math I was working with when the radius was 600.
int main()
{    
    string name = "Magret Thatcher";
    double radius = 600, newRadius = 600;    
    Planet ball = Planet(name, radius);
    cout << "Planet Name: " << ball.getName() << endl;
    cout << "Planet Radius: " << ball.getRadius() << endl;    
    cout << "Planet Volume: " << ball.getVolume() << endl;    
    ball.setName("Jupiter");    
    ball.setRadius(newRadius);    
    cout << "Planet Name: " << ball.getName() << endl;     
    cout << "Planet Radius: " << ball.getRadius() << endl;    
    cout << "Planet Volume: " << ball.getVolume() << endl;
    return 0;
}