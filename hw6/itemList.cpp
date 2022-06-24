// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 6 - Problem 1

#include <iostream> 
#include <iomanip>  
#include <fstream>
using namespace std; 

/*
This main function asks the user to enter a file, if it doesn't exist it says so, if it does exist and meets the file criteria it 
puts each non blank line in an array. The stream is then closed, the text part of the array is taken into another array, and the price is 
also taken into another array. The amount of non blank lines is outputted, and then the highest and lowest prices are calculated, and then
outputed.
*/
int main()
{
    cout<<"Enter the file name: "<<endl;
    string fileName;
    cin>>fileName;
    ifstream file;
    file.open(fileName);
    string lines[99999];
    bool more=true;
    string line;
    int index=0;
    int comma=0;
    int greatestf, leastf=0;
    if(file.fail())
    {
        cout<<"Could not open file."<<endl;
    }
    else
    {
        while(getline(file,line))
        {
            if(line!="")
            {
                lines[index]=line;
                index++;
            }
        }
        cout<<"The number of lines: "<<index<<endl;
        file.close();
        double price[index];
        string final[index];
        for(int i=0;i<index;i++)
        {
            for(int j=0;j<lines[i].length();j++)
            {
                line=lines[i].substr(j,1);
                if(line==",")
                {
                    comma=j;
                    price[i]=stod(lines[i].substr(comma+1,lines[i].length()-comma+1));
                    final[i]=lines[i].substr(0,comma);
                }
            }
        }
        double greatest, least=price[0];
        for(int k=0;k<index;k++)
        {
            if(price[k]>greatest)
            {
                greatestf=k;
                greatest=price[k];
            }
            if(price[k]<least)
            {
                leastf=k;
                least=price[k];
            }
        }
        cout<<"The most expensive product: "<<final[greatestf]<<endl;
        cout<<"The least expensive product: "<<final[leastf]<<endl;
    }
    return 0;
}