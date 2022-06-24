// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 8 - Problem 2
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int> v1, vector<int> v2)
{
    int loop=v1.size();
    vector<int> shuffled;
    //This case handles if both vectors have 0 size, in which case an empty vector is returned.
    if(v1.size()==0&&v2.size()==0)
    {
        return shuffled;
    }
    //These two return one of the inputed vectors if the other one is empty.
    else if(v1.size()!=0&&v2.size()==0)
    {
        return v1;
    }
    else if (v1.size()==0&&v2.size()!=0)
    {
        return v2;
    }
    //The cases where sizes are the same and neither are emtpy. In this case it just puts the order with input 1 then 2.
    else if(v1.size()!=0&&v1.size()==v2.size())
    {
        for(int i=0;i<loop;i++)
        {
            shuffled.push_back(v1[i]);
            shuffled.push_back(v2[i]);
        }
        return shuffled;
    }
    else
    {
        //This is where the second is inputed with a larger size, so it is handled first.
        if(v1.size()<v2.size())
        {
            loop=v1.size();
            for(int i=0;i<loop;i++)
            {
                shuffled.push_back(v2[i]);
                shuffled.push_back(v1[i]);
            } 
        }
        else
        //This si the counterpart for the second input being smaller.
        {
            loop=v2.size();
            for(int i=0;i<loop;i++)
            {
                shuffled.push_back(v1[i]);
                shuffled.push_back(v2[i]);
            } 
        }   
        //Depending on which one was smaller i is set to the size of the previous part and the rest of the incomplet vector is added to 
        //the shuffled vector.
        if(v1.size()<v2.size())
        {
            for(int i=v1.size();i<v2.size();i++)
            {
                shuffled.push_back(v2[i]);
            }
            return shuffled;
        }
        else
        {
            for(int i=v2.size();i<v1.size();i++)
            {
                shuffled.push_back(v1[i]);
            }
            return shuffled;
        }  
    }  
}
// Main is empty here.
int main()
{
    return 0;
}