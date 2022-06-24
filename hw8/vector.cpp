// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 8 - Problem 1
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    int number=0;
    vector<int> counts;
    while (number!=-1)
    {
        //All of these first cases are just in place to make sure that the vector is manipulated in the proper way according to
        //what the homework pdf says.
        cout<<"Please enter a number:"<<endl;
        cin>> number;
        if (counts.size()==0&&number>=1)
        {
            //This one is here in front specifiaclly for the case where it is both divisible by 3 and 5 but only one opperation
            //can be completed due to size.
            counts.push_back(number);
        }
        else if((counts.size()==1)&&number%5==0&&number%3==0)
        {
            counts.pop_back();
        }
        else if((counts.size()!=0)&&number%5==0&&number%3==0)
        {
            counts.erase(counts.begin());
            counts.pop_back();
        }
        else if((counts.size()!=0)&&number%5==0)
        {
           // counts.push_back(number);
            counts.erase(counts.begin());
        }
        else if((counts.size()!=0)&&number%3==0)
        {
            //counts.push_back(number);
            counts.pop_back();
        }
        else if(number<1&&number!=-1)
        {
            //This is for invalid inputs.
            cout<<"The number should be a positive integer or -1."<<endl;
        }
        else if(number==-1)
        {
            //Empty on purpose
            //This is just to make sure -1 isn't added to, or changes the vector.
        }
        else
        {
            //If none of the other cases are true this just adds the user value to the vector.
            counts.push_back(number);
        }
    }
   if (counts.size()==0)
   {
       cout<<"The vector is empty."<<endl;
   }
   else
   {
        int min=counts[0];
        int max=counts[0];
        //Loops is made so that the for loop works properly and doesn't give an error with variables.
        int loops = counts.size();
        for(int i=0;i<loops;i++)
        {
            //This first loop is to assign mins and maxes.
            if (min>counts[i])
            {
                min=counts[i];
            }
            if(max<counts[i])
            {
                max=counts[i];
            }
        }
        cout<<"The elements in the vector are:";
        for(int i=0;i<loops;i++)
        {
            //This second for loop is used to print the elements in the vector.
            cout<<" "<<counts[i];
        }
        cout<<endl<<"Min = "<<min<<endl;
        cout<<"Max = "<<max<<endl;
   }
    return 0;
}