#include <iostream>
#include <cmath>
#include"User.h"
using namespace std;

// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 6

int main(){
    int arrayTest[5] = {3,4,1,5};
    User empty;
    User test("Gr3ttaTh3Cat",arrayTest,4);
    cout << empty.getUsername() << endl;
    cout << empty.getRatingAt(2) << endl;
    cout << empty.getNumRatings() << endl;
    cout << empty.getSize() << endl;
    cout << test.getUsername() << endl;
    cout << test.getRatingAt(2) << endl;
    cout << test.getNumRatings() << endl;
    cout << test.getSize() << endl;
}