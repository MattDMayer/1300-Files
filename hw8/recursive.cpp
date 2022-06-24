// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 8 - Problem 4
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

//Using a public vector to store the variables throuhgout the recursion process.
vector<string> binary;

//The calculate function exists and is also recursive. It's purose is to gather and put together all of the recursive ones and zeroes
//That come from the decimal to binary function.
string calculate(vector<string> binary, int movement, string complete)
{
    //If this condition is met, the recursion ends and the final put together binary number is given back to the decimal to binary function.
    if(binary.size()==complete.length())
    {
        return complete;
    }
    //Otherwize complete is updated with a new character from recursion and the recursion continues.
    else
    {
        complete=complete+binary[movement];
        movement++;
        return calculate(binary,movement,complete);
    }
}

string decimalToBinaryRecursive(int input)
{
    int division;
    int next=input%2;
    //This if statement is here as the base case to stop the recursion.
    if(input==0)
    {
        return "0";
    }
    else
    {
        //Here the input is divided by two and the recursion happens as the function calls itself.
        division=input/2;
        decimalToBinaryRecursive(division);
        //Here the recursion input after modulus division is put into the public vector.
        binary.push_back(to_string(next));
        //Here the calculate helper function is called, letting the final binary number being displayd at the end of the code.
        return calculate(binary,0,"");
    }
}
//This main function is just used to print a test case for me to bugtest.

int main()
{
    cout<<decimalToBinaryRecursive(18);
    return 0;
}