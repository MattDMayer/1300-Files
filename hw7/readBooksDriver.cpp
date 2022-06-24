// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 7 - Problem 4
#include <iostream>
#include "Book.h"
#include <fstream>
using namespace std;


//This is the split function from homework 5 with no changes made to it, it just takes a string and splits it into pieces when finding
//a specific character, and assigns it to a string array.
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

//This function takes in a file, a book array, a number of books already in the array, and the size of the books array.
int readBooks(string fileName, Book books[], int numBooksStored, int bookArrSize)
{
    ifstream file;
    file.open(fileName);
    int size=bookArrSize*3;
    books[bookArrSize];
    string storeArray[size];
    //Here is a check to see if the array is full, if it is, -2 is returned.
    if(bookArrSize==numBooksStored)
    {
        return -2;
    }
    string line;
    int index=0;
    //This if statment is a check to see if the file failed to open, if it did, this returns -1.
    if(file.fail())
    {
        return -1;
    }
    else
    {
        //If the two checks are passed, the split function splits each line of the array by the ',' character and assigns the data in order
        //to the storeArray array. A book in the book array at the amount of loops of lines checked + initial books is assigned the data
        //from this array before the process repeats.
        int index=0;
        while (getline(file,line))
        {
            split(line,',',storeArray,size);
            //This if statment is only here to make sure the program skips over blank lines.
            if(line!="")
            {
                books[numBooksStored+index].setAuthor(storeArray[0]);
                books[numBooksStored+index].setTitle(storeArray[1]);
                books[numBooksStored+index].setGenre(storeArray[2]);
                index++;
                //This if statment check is used to see if the book array is full, if it is, the function returns the size of the book array.
                if(numBooksStored+index==bookArrSize)
                {
                    file.close();
                    return numBooksStored+index;
                }
            }
        }
        //If the code makes it to this point no other checks have been hit, and the total ammount of books in the book array are returned.
        file.close();
        return numBooksStored+index;
    } 
}
//Main here is empty, as I don't have files to test I can't call on the function and have it output anything but a return value of -1.
int main()
{    
    
    return 0;
}