// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 3
#include <iostream>
#include "Book.h"
using namespace std;

//My main function is really the main function provided for part one, but set up to work with the book object and its data.
int main()
{    
    string author="Karl Marx";
    string title="Harry Potter and the Audacity of this Bitch";
    string genre="Non-Fiction";
    Book novel=Book(title, author, genre);
    cout << "Title: " << novel.getTitle() << endl;
    cout << "Author: " << novel.getAuthor() << endl;    
    cout << "Genre: " << novel.getGenre() << endl;    
    novel.setTitle("Someone Stole my Sweetroll");    
    novel.setAuthor("Engles");
    novel.setGenre("Horror");    
    cout << "Title: " << novel.getTitle() << endl;     
    cout << "Author: " << novel.getAuthor() << endl;    
    cout << "Genre: " << novel.getGenre() << endl;
    return 0;
}