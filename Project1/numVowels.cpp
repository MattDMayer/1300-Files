// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 1 - Problem 3


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
/*
    This integer function takes in the line that the user entered, using a getline in case of spaces, and then uses the previously made 
    function to count for how many vowels are in the input string. The cool thing about this function is that it will loop for exactly 
    how long the input string is, as seen on line 37, to check every character, with no out of bounds checks, every time.
*/
int numVowels(string enter)
{
    int vowels=0;;
    int index=0;
    char subcharacter;
    for(int i=0;i<enter.length();i++)
    {
        subcharacter=enter[index];
        if(isVowel(subcharacter))
            {
              vowels++;;
             }
        index++;
    }
    return vowels;
}
// Main here is just used to declare a string, have the user input a string, and then to call the function with that input as a parameter.
int main()
{
	string phrase;
	getline(cin,phrase);
	cout<<numVowels(phrase);
	return 0;
}