// CS1300 Fall 2020
// Author: Matthew Mayer
// Recitation: 518 – Madhusudhan Mahabhaleshwara
// Homework 5 - Problem 6 / Extra Credit

#include <iostream>
#include <iomanip>
using namespace std;

// All this program does is take a user inputed string, makes each character a substring and adds it to the array that totals them, if there
//is more than 0 of a character in the user inuted string, it will output how many characters there were in the string.

int main()
{
    int characterCounter[26];
    for(int a=0;a<26;a++)
    {
        characterCounter[a]=0;
    }
    cout<<"Enter a word:"<<endl;
    string word;
    cin>>word;
    string one;
    for(int i=0;i<word.length();i++)
    {
        one=word.substr(i,1);
        if(one=="a")
        {
            characterCounter[0]++;
        }
        if(one=="b")
        {
            characterCounter[1]++;
        }
        if(one=="c")
        {
            characterCounter[2]++;
        }
        if(one=="d")
        {
            characterCounter[3]++;
        }
        if(one=="e")
        {
            characterCounter[4]++;
        }
        if(one=="f")
        {
            characterCounter[5]++;
        }
        if(one=="g")
        {
            characterCounter[6]++;
        }
        if(one=="h")
        {
            characterCounter[7]++;
        }
        if(one=="i")
        {
            characterCounter[8]++;
        }
        if(one=="j")
        {
            characterCounter[9]++;
        }
        if(one=="k")
        {
            characterCounter[10]++;
        }
        if(one=="l")
        {
            characterCounter[11]++;
        }
        if(one=="m")
        {
            characterCounter[12]++;
        }
        if(one=="n")
        {
            characterCounter[13]++;
        }
        if(one=="o")
        {
            characterCounter[14]++;
        }
        if(one=="p")
        {
            characterCounter[15]++;
        }
        if(one=="q")
        {
            characterCounter[16]++;
        }
        if(one=="r")
        {
            characterCounter[17]++;
        }
        if(one=="s")
        {
            characterCounter[18]++;
        }
        if(one=="t")
        {
            characterCounter[19]++;
        }
        if(one=="u")
        {
            characterCounter[20]++;
        }
        if(one=="v")
        {
            characterCounter[21]++;
        }
        if(one=="w")
        {
            characterCounter[22]++;
        }
        if(one=="x")
        {
            characterCounter[23]++;
        }
        if(one=="y")
        {
            characterCounter[24]++;
        }
        if(one=="z")
        {
            characterCounter[25]++;
        }
    }

    if(characterCounter[0]>0)
    {
        cout<<"a: "<<characterCounter[0]<<endl;
    }
    if(characterCounter[1]>0)
    {
        cout<<"b: "<<characterCounter[1]<<endl;
    }
    if(characterCounter[2]>0)
    {
        cout<<"c: "<<characterCounter[2]<<endl;
    }
    if(characterCounter[3]>0)
    {
        cout<<"d: "<<characterCounter[3]<<endl;
    }
    if(characterCounter[4]>0)
    {
        cout<<"e: "<<characterCounter[4]<<endl;
    }
    if(characterCounter[5]>0)
    {
        cout<<"f: "<<characterCounter[5]<<endl;
    }
    if(characterCounter[6]>0)
    {
        cout<<"g: "<<characterCounter[6]<<endl;
    }
    if(characterCounter[7]>0)
    {
        cout<<"h: "<<characterCounter[7]<<endl;
    }
    if(characterCounter[8]>0)
    {
        cout<<"i: "<<characterCounter[8]<<endl;
    }
    if(characterCounter[9]>0)
    {
        cout<<"j: "<<characterCounter[9]<<endl;
    }
        if(characterCounter[10]>0)
    {
        cout<<"k: "<<characterCounter[10]<<endl;
    }
    if(characterCounter[11]>0)
    {
        cout<<"l: "<<characterCounter[11]<<endl;
    }
    if(characterCounter[12]>0)
    {
        cout<<"m: "<<characterCounter[12]<<endl;
    }
    if(characterCounter[13]>0)
    {
        cout<<"n: "<<characterCounter[13]<<endl;
    }
    if(characterCounter[14]>0)
    {
        cout<<"o: "<<characterCounter[14]<<endl;
    }
    if(characterCounter[15]>0)
    {
        cout<<"p: "<<characterCounter[15]<<endl;
    }
    if(characterCounter[16]>0)
    {
        cout<<"q: "<<characterCounter[16]<<endl;
    }
    if(characterCounter[17]>0)
    {
        cout<<"r: "<<characterCounter[17]<<endl;
    }
    if(characterCounter[18]>0)
    {
        cout<<"s: "<<characterCounter[18]<<endl;
    }
    if(characterCounter[19]>0)
    {
        cout<<"t: "<<characterCounter[19]<<endl;
    }
     if(characterCounter[20]>0)
    {
        cout<<"u: "<<characterCounter[20]<<endl;
    }
    if(characterCounter[21]>0)
    {
        cout<<"v: "<<characterCounter[21]<<endl;
    }
    if(characterCounter[22]>0)
    {
        cout<<"w: "<<characterCounter[22]<<endl;
    }
    if(characterCounter[23]>0)
    {
        cout<<"x: "<<characterCounter[23]<<endl;
    }
    if(characterCounter[24]>0)
    {
        cout<<"y: "<<characterCounter[24]<<endl;
    }
    if(characterCounter[25]>0)
    {
        cout<<"z: "<<characterCounter[25]<<endl;
    }
    return 0;
}