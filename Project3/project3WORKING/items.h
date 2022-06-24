#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

class item{
    private:
        string name;
        string modType;
        int modValue;
    public:
        item();
        item(string name, string modType, int modValue);
        string getName();
        string getModType();
        int getModValue();
        void setName(string inputName);
        void setModValue(int inputModValue);
        void setModType(string inputModType);
};
#endif