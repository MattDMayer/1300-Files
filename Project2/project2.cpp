// CS1300 Fall 2020
// Author: Matthew Mayer & Kevin Lacjak
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Project 2 - Problem 11 & 12

#include <iostream>
#include <cmath>
#include "user.h"
#include "Book.h"
#include <iomanip>
#include <fstream>
using namespace std;

int split (string toBeSplit, char delim, string arr[], int size){
    int lastPos = 0;
    int arryPosition=0;
    int maxCol = 50;
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
            //DO NOTHING
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

int countGenre(string genre, Book books[], int numBooksStored)
{
    int genreMatch=0;
    for(int i=0;i<numBooksStored;i++)
    {
        if(books[i].getGenre()==genre)
        {
            genreMatch++;
        }
    }
    return genreMatch;
}

int printAuthorGenre(string genre, char firstLetter, Book books[], int numBooksStored)
{
    string temp;
    int matchedBooks[numBooksStored];
    int match=0;
    for(int i=0;i<numBooksStored;i++)
    {
        temp = books[i].getAuthor();
        if((books[i].getGenre()==genre) && (temp[0] == firstLetter))
        {
            matchedBooks[match] = i;
            match = match + 1;
        }
    }
    if(match==0)
    {
        cout<<"No titles found for this genre-author pair."<<endl;
        return match;
    }
    else
    {
        cout<<"Here is a list of books that match this genre-author pair:"<<endl;
        for(int i=0;i<match;i++)
        {
            cout<<books[matchedBooks[i]].getTitle()<<" by "<<books[matchedBooks[i]].getAuthor()<<endl;
        }
        return match;
    }
}

int addUser(string UserName, User users[], int numRatings, int numUsersStored, int userArrSize){
    User newUser;
    if (numUsersStored>=userArrSize){
        return -2;
    }
    if(UserName== ""){
        return -1;
    }
    for(int i = 0; i < numUsersStored; i++){
        if(UserName == users[i].getUsername()){
            return -1;
        }
    }
    newUser.setUsername(UserName);
    users[numUsersStored] = newUser;
    return numUsersStored + 1;
}

int readRatings(string filename, User users[], int numUsersStored, int userArrSize, int maxCol) {
    ifstream file;
    string line;
    int thingsInArray;
    int size = 51;
    User tempUser;
    string tempArray[size];
    file.open(filename);
    if(numUsersStored>=userArrSize)
    {
        return -2;
    }
    else if(file.fail())
    {
        return -1;
    }
    else
    {
        while(getline(file,line))
        {
            thingsInArray = split(line,',',tempArray,size);
            if (line == ""){
                //do nothing
            }
            else{
            tempUser.setUsername(tempArray[0]);
            tempUser.setNumRatings(thingsInArray-1);
            for (int i = 1; i < thingsInArray; i++){
                tempUser.setRatingAt(i-1,stoi(tempArray[i]));
            }
            users[numUsersStored] = tempUser;
            numUsersStored = numUsersStored+1;
            if (numUsersStored >= userArrSize){
                return numUsersStored;
            }
            }
        }
        return numUsersStored;
    }
}

string lowercase(string toBeLowered){
    int length = toBeLowered.length();
    for (int i = 0; i < length; i++){
        toBeLowered[i]=tolower(toBeLowered[i]);
    }
    return toBeLowered;
}

int getRating(string username,string titleOfBook,User users[],Book books[],int numOfUsers, int numOfBooks){
    int tempPosBook = -1;
    int tempPosUser = -1;
    for (int i = 0; i < numOfBooks; i++){
        if (lowercase(titleOfBook) == lowercase(books[i].getTitle())){
            tempPosBook = i;
            break;
        }
    }
    if (tempPosBook == -1){
        return -3;
    }
    for (int i = 0; i < numOfUsers; i++){
        if (lowercase(username) == lowercase(users[i].getUsername())){
            return users[i].getRatingAt(tempPosBook);  
            tempPosUser = i; 
        }
    }
    return -3;
}

User getUserIndex (string username, User users[], int numOfUsers){
    User TheChosenOne;
    User Fail("fail",0,0);
    for(int i = 0; i < numOfUsers; i++){
        if (username == users[i].getUsername()){
            TheChosenOne = users[i];
            return TheChosenOne;
        }
    }
    return Fail;
}

int getNumOfRatingsOfUser(User user, int numOfBooks){
    int numOfRatingOfUser = 0;
    for (int i = 0; i < numOfBooks; i++){
        if (user.getRatingAt(i) > 0){
            numOfRatingOfUser = numOfRatingOfUser+1;
        }
    }
    return numOfRatingOfUser;
}

double getAverageRatings (User user, int numOfBooks){
    int numOfRatingOfUser = 0;
    double average = 0;
    for (int i = 0; i < numOfBooks; i++){
        if (user.getRatingAt(i) > 0){
            numOfRatingOfUser = numOfRatingOfUser+1;
            average = user.getRatingAt(i) + average;
        }
    }
    return average = average / double(numOfRatingOfUser);
}

int getUserStats(string username, User users[], int numOfUsers, int numOfBooks){
    double average = 0.0;
    int numOfRatings;
    User TheOne;
    TheOne = getUserIndex(username, users, numOfUsers);
    if (TheOne.getUsername() == "fail"){
        cout << username << " does not exist." << endl;
        return -3;
    }
    else{
        numOfRatings = getNumOfRatingsOfUser(TheOne, numOfBooks);
        if (numOfRatings == 0){
            cout << TheOne.getUsername() << " has not rated any books." << endl;
            return 0;
        }
        cout << TheOne.getUsername() << " rated " << numOfRatings << " books" << endl;
        average = getAverageRatings(TheOne,numOfBooks);
        cout << fixed << setprecision(2) << TheOne.getUsername() << "'s average rating was " << average << endl;
        return 1;
    }
}

int main(){
    string genre;
    string fileName;
    string bookTitle;
    string username;
    Book books[50];
    User users[100];
    string authorChar;
    int genereNum;
    int tempUsersStored;
    int numOfRatings = 0;
    int tempRatingOfBook;
    int numUsersStored = 0;
    int numReturnedTitles;
    int numBookStored = 0;
    int tempBooksStored = 0;
    string control = "0";
    while(control != "9"){
        cout<<"Select a numerical option: "<<endl;
        cout<<"======Main Menu====="<<endl;
        cout<<"1. Read books from file"<<endl;
        cout<<"2. Print all books"<<endl;
        cout<<"3. Book-count by genre"<<endl;
        cout<<"4. Filter books by genre, author"<<endl;
        cout<<"5. Add user"<<endl;
        cout<<"6. Read ratings"<<endl;
        cout<<"7. Get rating"<<endl;
        cout<<"8. Get user statistics"<<endl;
        cout<<"9. Quit"<<endl;
        getline(cin,control);
        switch(stoi(control)){
            case 1:
                cout << "Enter a book file name:" << endl;
                getline(cin,fileName);
                tempBooksStored = readBooks(fileName, books, numBookStored, 50);
                if (tempBooksStored == -1){
                    cout << "No books saved to the database." << endl;
                }
                else if (tempBooksStored == -2){
                    cout << "Database is already full. No books were added." << endl;
                }
                else if (tempBooksStored >= 50){
                    cout << "Database is full. Some books may have not been added." << endl;
                    numBookStored = 50;
                }
                else{
                    cout << "Total books in the database: " << tempBooksStored << endl;
                    numBookStored = tempBooksStored;
                }
                break;
            case 2:
                printAllBooks(books,numBookStored);
                break;
            case 3:
                cout << "Enter the genre:" << endl;
                getline(cin,genre);
                genereNum = countGenre(genre, books, numBookStored);
                cout << "Total " << genre << " books in the database: " << genereNum << endl;
                break;
            case 4:
                cout << "Enter the genre:" << endl;
                getline(cin,genre);
                cout << "Enter first char of author name:" << endl;
                getline(cin,authorChar);
                numReturnedTitles = printAuthorGenre(genre, authorChar[0], books, numBookStored);
                cout << "Number of titles found for this filter: " << numReturnedTitles << endl;
                break;
            case 5:
                cout << "Enter a user name:" << endl;
                getline(cin,username);
                tempUsersStored = addUser(username,users,numOfRatings,numUsersStored,100);
                if (tempUsersStored == -2){
                    cout << "Database is already full. User cannot be added." << endl;
                }
                else if (tempUsersStored == -1){
                    cout << "User already exists or the username is empty." << endl;
                }
                else {
                    cout << "Welcome, " << username << "!" << endl;
                    numUsersStored = tempUsersStored;
                }
                break;
            case 6:
                cout << "Enter the ratings file name:" << endl;
                getline(cin,fileName);
                tempUsersStored = readRatings(fileName,users,numUsersStored,100,50);
                if (tempUsersStored == -1){
                    cout << "No ratings saved to the database." << endl;
                }
                else if (tempUsersStored == -2){
                    cout << "Database is already full. No ratings were added." << endl;
                }
                else if (tempUsersStored == 100){
                    cout << "Database is full. Some ratings may have not been added." << endl;
                }
                else{
                    cout << "Total users in the database: " << tempUsersStored << endl;
                    numUsersStored = tempUsersStored;
                }
                break;
            case 7:
                cout << "Enter a user name:" << endl;
                getline(cin,username);
                cout << "Enter a book title:" << endl;
                getline(cin,bookTitle);
                tempRatingOfBook = getRating(username,bookTitle,users,books,numUsersStored,numBookStored);
                if (tempRatingOfBook == -3){
                    cout << username << " or " << bookTitle << " does not exist." << endl;
                }
                else{
                    cout << username << " rated " << bookTitle << " with " << tempRatingOfBook << endl;
                }
                break;
            case 8:
                cout << "Enter a user name:" << endl;
                getline(cin,username);
                getUserStats(username, users, numUsersStored, numBookStored);
                break;
            case 9:
                cout << "Good bye!" << endl;
                break;
            default:
            cout << "Invalid input." << endl;
            break;
        }       
    }
    return 0;
}