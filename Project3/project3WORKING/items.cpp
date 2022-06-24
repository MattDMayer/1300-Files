#include <iostream>
#include "items.h"
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

item::item(){
    name = "";
    modType = "";
    modValue = 0;
}

item::item(string inputName, string inputModType, int inputModValue){
    name = inputName;
    modType = inputModType;
    modValue = inputModValue;
}

string item::getName(){
    return name;
}

string item::getModType(){
    return modType;
}

int item::getModValue(){
    return modValue;
}

void item::setName(string inputItemName)
{
    name=inputItemName;
}
void item::setModValue(int inputModValue)
{
    modValue=inputModValue;
}
void item::setModType(string inputModType)
{
    modType=inputModType;
}