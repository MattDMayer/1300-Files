// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 1 - Problem 1


#include <iostream> 
#include <iomanip>  
using namespace std; 
/*
	This function simply takes in an input string called parameter, and then loops for the length of that string, a one character substring
	the function then adds all of these substrings to a string called final, and in the end it outputs final, while the function
	technically returns nothing as it is a void function.
*/
void reverse(string parameter)
{
	string final;
	int index=parameter.length()-1;
	for(int i=0;i<parameter.length();i++)
	{
		final += parameter.substr(index,1);
		index--;
	}
	cout <<final;
	return;
}
//Main is just used to declare a string here, and to get the user's input for said string, then calling the function with that input.
int main()
{
	string word;
	getline(cin,word);
	reverse(word);
	return 0;
}