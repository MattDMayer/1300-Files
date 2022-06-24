// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 5 - Problem 2

#include <iostream>
#include <iomanip>
using namespace std;

/*
This function takes in a double array and an integer that is used as the length of the array. It then makes variables for the average, min,
and max. by default, the average is set to 0 and the min and max are set to the value of the first cell of the array. The function then
compares the min and max variables to the value of every cell, if the cell is a more extreme min or max, the variables are set to that value.
At the same time every value is added to the average variable, and when the loop is completed the average value is divided by the 
array length variable, giving a total average. Finally every value is printed out with a max of two decimal places.
*/
void stats(double statsArray[],int store)
{
    double min,max, avg=0.0;
    min=statsArray[0];
    max=statsArray[0];
    for (int i=0;i<store;i++)
    {
        if (statsArray[i]<min)
        {
            min=statsArray[i];
        }
        if (statsArray[i]>max)
        {
            max=statsArray[i];
        }
        avg+=statsArray[i];
    }
    avg=double(avg/store);
    cout<<"Min: "<<setprecision(2)<<fixed<<min<<endl;
    cout<<"Max: "<<setprecision(2)<<fixed<<max<<endl;
    cout<<"Avg: "<<setprecision(2)<<fixed<<avg<<endl;
    return;
}
// The main function isn't very special, just creating an array with store as its length.
int main()
{
    int store=159;
    double statsArray[store];
    return 0;
}