// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 6 - Problem 2

#include <iostream> 
#include <iomanip>  
#include <fstream>
using namespace std; 
//The function as a whole takes a text file and assigns each name an average value of sales.
int readSales(string fileName, string names[], int monthlySales[][12], int size)
{
    //This just is for opening the file and for establishing variables.
    ifstream file;
    file.open(fileName);
    string line;
    int last,lineNum, index, month=0;
    double avg[1000];
    string numSet;
    if(file.fail())
    {
        return -1;
    }
    else
    {
        while(getline(file,line))
        {
            //This part of the loop is used to assign each name to an array of names.
            if(lineNum%2==0)
            {
                names[index]=line;
                lineNum++;
            }
            else if(lineNum%2!=0)
            {
                month=0;
                last=0;

                //This for loop is used to assign each numerical value from the file into the monthlysales array which is used to
                //calculate the average of each employees sales.
                for(int i=0;i<line.length();i++)
                {
                    if(month==0&&line.substr(i,1)==",")
                    {
                        monthlySales[index][month]=stoi(line.substr(0,i));   
                        last=i+2;   
                        month++;
                    }
                    else if(((month>0)&&(month<11))&&line.substr(i,1)==",")
                    {
                        monthlySales[index][month]=stoi(line.substr(last,i-last));
                        month++;
                        last=i+2;
                    }
                    else if(month==11)
                    {
                        monthlySales[index][month]=stoi(line.substr(last,line.length()-last));
                    }
                }
                index++;

                //This if statement and break is meant to just handle segmentation faults, resulting from more names existing than the size
                //allows.
                if(index==size)
                {
                    break;
                }
                lineNum++;
            }
        }
        file.close();
        //This is just used to calculate each average and to output it.
        for(int i=0;i<index;i++)
        {
            avg[i]=0;
            for(int j=0;j<12;j++)
            {
                avg[i]+=monthlySales[i][j];
            }
            avg[i]=double(avg[i]/12);
            cout<<names[i]<<": "<<setprecision(1)<<fixed<<avg[i]<<endl;
        }
        return index;
    }
}
// main doesn't do much here, just calling some default perameters and calling the file for testing.
int main()
{
    string fileName = "sales.txt";
    const int SIZE = 10;
    string names[SIZE]; 
    int sales[SIZE][12]; 
    int val = readSales(fileName, names, sales, SIZE); 
    cout << "return value: " << val << endl; 
    return 0;
}