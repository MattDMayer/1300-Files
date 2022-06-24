// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 5 - Problem 1

/*
In this program I just used the main method to call and output these non changing arrays. For each array, I created a for loop
with a variable to both move through the loop and to assign a cell of the array a certain value on each pass of the loop. I then
had each index's value printed out at the same time to show that each spot was being properly assigned.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double temps[10];
    for(int i=0;i<10;i++)
    {
        temps[i]=-459.67;
        cout<<temps[i]<<endl;
    }
    
    string colors[5];
    colors[0]="Red";
    colors[1]="Blue";
    colors[2]="Green";
    colors[3]="Cyan";
    colors[4]="Magenta";
    cout<<endl;
    for(int j=0;j<5;j++)
    {
        cout<<colors[j]<<endl;
    }
    cout<<endl;
    int sequence[100];
    for(int k=0;k<100;k++)
    {
        sequence[k]=k+1;
        cout<<sequence[k]<<endl;
    }
    cout<<endl;
    char letters[52];
    int upper=65;
    int lower=upper+32;

    for(int l=0;l<52;l++)
    {
        if(l%2!=0&&l!=0)
        {
            letters[l]=lower;
            cout<<letters[l]<<endl;
            upper++;
        }
        else if (l%2==0&&l==0)
        {
            letters[l]=upper;
            cout<<letters[l]<<" ";
        }
        else
        {
            letters[l]=upper;
            cout<<letters[l]<<" ";
        }
        lower=upper+32;
    }
    return 0;
}