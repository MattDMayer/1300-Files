// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 3 - 6
#include <iostream>
using namespace std;

//This is just the defining of a class which is all specified in the homework document.
class Book
{
    public:
    Book();
    Book(string title, string author, string genre);
    string getTitle();
    void setTitle(string newTitle);
    string getAuthor();
    void setAuthor(string newAuthor);
    string getGenre();
    void setGenre(string newGenre);

    private:
    string title;
    string author;
    string genre;
};