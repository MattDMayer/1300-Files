// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2- Problem 3

#include <iostream>
#include "Book.h"
#include <fstream>
using namespace std;


//Split function from homework 5
int split (string toBeSplit, char delim, string arr[], int size){
    int lastPos = 0;
    int arryPosition=0;
    int length = toBeSplit.length();
    for (int i = 0; i < length; i++){
        if (arryPosition >= size){
            return -1;
        }
        else if (toBeSplit[i]==delim){
            arr[arryPosition] = toBeSplit.substr(lastPos,i-lastPos);
            arryPosition = arryPosition+1;
            lastPos=i+1;
        }
        else if (i == length-1){
            arr[arryPosition] = toBeSplit.substr(lastPos);
            arryPosition = arryPosition+1;
            lastPos=i+1;
        }
    }
    //returns the number of things in the array
    return arryPosition;
}

//Read books function from homework 7
int readBooks(string fileName, Book books[], int numBooksStored, int booksArrSize){
    ifstream file;
    string line;
    int i = 0;
    Book tempBook;
    string arr[booksArrSize];
    file.open(fileName);
    if (file.is_open()){
        if (numBooksStored == booksArrSize){
            return -2;
        }
        while(getline(file, line)){
            if (line == ""){
                
            }
            else{
                if ((numBooksStored > 0) && (i == 0)){
                    i = numBooksStored;
                }
                if (i >= booksArrSize){
                    return i;
                }
                split(line, ',', arr, 50);
                tempBook = Book(arr[1],arr[0],arr[2]);
                books[i] = tempBook;
                i=i+1;
            }
        }
        return i;
    }
    else{
        return -1;
    }
}

//Function copy pasted from homework 7.
void printAllBooks(Book books[], int booksInArr){
    if (booksInArr <= 0){
        cout << "No books are stored" << endl;
    }
    else{
        cout << "Here is a list of books" << endl;
        for(int i = 0; i < booksInArr; i++){
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;
        }
    }
}

//Main just to test stuff.
int main(){
    // print one book
    Book books[1];
    // putting books in the books arr
    books[0].setTitle("Calculus1");
    books[0].setAuthor("Gottfried Leibniz");
    printAllBooks(books, 1);
}
