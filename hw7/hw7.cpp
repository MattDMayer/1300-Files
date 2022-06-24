// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 6
#include <iostream>
#include "Book.h"
#include <fstream>
using namespace std;

int split(string toBeSplit, char splitPoint, string splitPieces[], int sizeOfSplitPieces)
{
    string looking;
    string splitPointConvert;
    splitPointConvert+=splitPoint;
    int finalLength=0;
    int placement, last=0;
    for(int i=0;i<toBeSplit.length()&&(sizeOfSplitPieces>placement);i++)
    {
        looking=toBeSplit.substr(i,1);
        if((looking==splitPointConvert))
        {
            splitPieces[placement]=toBeSplit.substr(last,i-last);
            placement++;
            last=i+1;
        }
        else if(i==toBeSplit.length()-1&&placement!=0)
        {
            for(int j=0;j<placement;j++)
            {
                finalLength+=splitPieces[j].length()+1;
            }
            if(placement<=sizeOfSplitPieces)
            {
                splitPieces[placement]=toBeSplit.substr(finalLength,toBeSplit.length()-(finalLength));
            }
        }
        else if(i==toBeSplit.length()-1&&placement==0)
        {
            splitPieces[placement]=toBeSplit;
        }
    }
    if(toBeSplit=="")
    {
        return 0;
    }
    else if(sizeOfSplitPieces<=placement)
    {
        return -1;
    }
    else
    {
        return placement+1;
    }
}
int readBooks(string fileName, Book books[], int numBooksStored, int bookArrSize)
{
    ifstream file;
    file.open(fileName);
    int size=bookArrSize*3;
    books[bookArrSize];
    string storeArray[size];
    if(bookArrSize==numBooksStored)
    {
        return -2;
    }
    string line;
    int index=0;
    if(file.fail())
    {
        return -1;
    }
    else
    {
        int index=0;
        while (getline(file,line))
        {
            split(line,',',storeArray,size);
            if(line!="")
            {
                books[numBooksStored+index].setAuthor(storeArray[0]);
                books[numBooksStored+index].setTitle(storeArray[1]);
                books[numBooksStored+index].setGenre(storeArray[2]);
                index++;
                if(numBooksStored+index==bookArrSize)
                {
                    file.close();
                    return numBooksStored+index;
                }
            }
        }
        file.close();
        return numBooksStored+index;
    } 
}
void printAllBooks(Book books[], int bookNumber)
{
    if (bookNumber<=0)
    {
        cout<<"No books are stored"<<endl;
    }
    else
    {
        cout<<"Here is a list of books"<<endl;
        for(int i=0;i<bookNumber;i++)
        {
            cout<<books[i].getTitle()<<" by "<<books[i].getAuthor()<<endl;
        }
    }
}

//This main function is the only real change between this problem and the one's before.
int main()
{    
    //Here I initialize the book object array. I also print the menu once here outside of the loop because I print the menu
    //At the end of my while loop. I let the user enter the control number and the loop goes forever until quit is picked.
    Book books[50];
    int control =0;
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Read books"<<endl;
    cout<<"2. Print all books"<<endl;
    cout<<"3. Quit"<<endl;
    cin>>control;
    string line;
    string fileName;
    ifstream file;
    int bookVar;
    while(control!=3)
    {
        //Here is option one, I have the readBooks function returning to a variable, so it doesn't constantly get called and cause errors.
        //If it returns to -2, -1, or 50 a special message is played to let the user know what has happened with their data and why
        //the outputs the user are getting are what they are.
        if(control==1)
        {
            cout<<"Enter a book file name: "<<endl;
            cin>> fileName;
            file.open(fileName);
            bookVar=readBooks(fileName, books, bookVar, 50);
            if(bookVar==-2)
            {
                cout<<"Database is already full. No books were added."<<endl;
            }
            else if(bookVar==-1)
            {
                cout<<"No books saved to the database."<<endl;
            }
            else if(bookVar==50)
            {
                cout<<"Database is full. Some books may have not been added."<<endl;
            }  
            else
            {
                cout<<"Total books in the database: "<<bookVar<<endl;
            }
            //I also make sure to close the file regardless of the path it takes.
            file.close();
        }
        else if(control==2)
        {
            //Here I use the printAllBooks file based off of the amount of books stored in the library. BookVar, is declared
            //before object one to avoid problems with a non-declared variable if option two is picked first.
            printAllBooks(books,bookVar);
        }
        else
        {
            //If not 1, 2, or 3 are chosen an Invalid input staement is returned.
            cout<<"Invalid input."<<endl;
        }  
        //Here I just reprint the menu at the end of the while loop and let the user put in inputs to keep the menu
        //going infinitley long as it is needed to be.
        cout<<"======Main Menu====="<<endl;
        cout<<"1. Read books"<<endl;
        cout<<"2. Print all books"<<endl;
        cout<<"3. Quit"<<endl;
        cin>>control;
    }
    //I put my goodbye statement right at the end of all my code so that regardless of how much pathing is going inside the loop, at the
    //end when the loop is broken and the user wants to quit, they can get a message.
    cout<<"Good bye!";
    return 0;
}