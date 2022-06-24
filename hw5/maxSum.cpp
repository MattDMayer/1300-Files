// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 5 - Problem 4

#include <iostream>
#include <iomanip>
using namespace std;

/*
The function max sum makes an array with 10 columns and a setable amount of rows, it then grabs the largest number from each row
and outputs a sum that is all of the largest numbers from each row added together. To do this it adds all iterations of max
which is orignally set to the first column of each row, but is then replaced if another index in said row is greater than it.
*/
int maxSum(int array[][10],int rowNum)
{
    int sum=0;
    int max;
    for(int i=0;i<rowNum;i++)
    {
        max=array[i][0];
        for(int j=0;j<10;j++)
        {
            if(array[i][j]>max)
            {
                max=array[i][j];
            }
        }
        sum+=max;
    }
    return sum;
}
//Main doesn't do anything in this program, it just ends.
int main()
{
    return 0;
}