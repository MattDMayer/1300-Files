// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 5 - Problem 5

#include <iostream>
#include <iomanip>
using namespace std;

/*
    My split method takes in a string that will be split apart, a character that triggers the string to be split, the array that the split 
    pieces will go into, and how many indexs the array will have. The first thing it does it change the split point character into a string
    so it can better read and interact with it. I then loop through the string that is being split for it's length one character at a time.
    If a substring ever equals the splitting character it will go into an if statment sequence. The first case is for making splits for any 
    case but the last one, the second case is for handeling the last splited segment as it won't have the split marked for it, rather it's 
    the remainder of what wasn't marked. Finally there is a statment that is merely a check to see if there are no characters to split, in
    which case the first index of the array is just set to the whole string. After all of that, the function either returns 0 if no splits
    were found, -1 if there were more splits than could fit into the array, and then the number of split strings produced if the other cases
    aren't happening.
*/
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

//Main doesn't do anything in this program, it just ends.much in this program, it just calls my split function with a specific case for testing.
int main()
{
string testcase = "Tokyo,Bangalore,Boulder,London,Seattle";
char separator = ',';
const int SIZE = 3;
string arr[SIZE];
int tc4 = split(testcase, separator, arr, SIZE);
for (int i=0 ; i < SIZE; i++)
      cout << "arr["<< i << "]:" << arr[i] << endl;
cout << "Function returned value: " << tc4 << endl;
}