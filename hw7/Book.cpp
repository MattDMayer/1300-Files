// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 3 - 6
#include <iostream>
#include "Book.h"
using namespace std;

//This is the default constructor for a book with no parameters.
    Book::Book()
    {
        title="";
        author="";
        genre="";
    }
    //This is the consturctor for a book with specified parameters.
    Book::Book(string setTitle, string setAuthor, string setGenre)
    {
        title=setTitle;
        author=setAuthor;
        genre=setGenre;
    }
    //This is a function for getting the title for a book.
    string Book::getTitle()
    {
        return title;
    }
    //This is the function to set a title for a book.
    void Book::setTitle(string newTitle)
    {  
        title=newTitle;
    }
    //This is the function for the code to access a particular book's title.
    string Book::getAuthor()
    {
        return author;
    }
    //This is the function to let a user set the title of a particular book.
    void Book::setAuthor(string newAuthor)
    {
        author=newAuthor;
    }
    //This is the function to return a particular book's genre.
    string Book::getGenre()
    {
        return genre;
    }
    //This is a function that lets the user set a genre for a book.
    void Book::setGenre(string newGenre)
    {
        genre=newGenre;
    }