#include <iostream>
#include "attack.h"
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

attack::attack(){
    attackName = "";
    damage = 0;
    type = "";
    manaCost = 0;
}

attack::attack(string inputName, int inputDamage, string inputType, int inputManaCost){
        attackName = inputName;
        damage = inputDamage;
        type = inputType;
        manaCost = inputManaCost;
}

string attack::getName(){
    return attackName;
}

int attack::getDamage(){
    return damage;
}

string attack::getType(){
    return type;
}

int attack::getManaCost(){
    return manaCost;
}
void attack::setName(string inputName)
{
    attackName=inputName;
}
void attack::setDamage(int inputDamage)
{
    damage=inputDamage;
}
void attack::setType(string inputType)
{
    type=inputType;
}
void attack::setManaCost(int inputManaCost)
{
    manaCost=inputManaCost;
}