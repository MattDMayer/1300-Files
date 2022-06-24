// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 1 - Problem 2


#include <iostream> 
#include <iomanip>  
using namespace std; 
/*
    Boolean function that simply checks for each vowel (both capital and lowervase), if it finds that the character is a vowel, 
    regardless of it being upper or lower case, the boolean function returns true. If anything else was inputed, the boolean
    returns false.
*/
bool isVowel(char letter)
{
    if(letter=='a'||letter=='e'||letter=='i'||letter=='o'||letter=='u'||letter=='A'||letter=='E'||letter=='I'||letter=='O'||letter=='U')
    {
        return true;
    }
    else
    {
        return false;
    }  
}
// Main here is just used for getting user input and then calling the function with that input.
int main()
{
    char enter;
    cin>>enter;
    cout<<isVowel(enter);
    return 0;
}