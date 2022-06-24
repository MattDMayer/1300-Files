#include <iostream>
#include "creature.h"
#include "attack.h"
#include <string>
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

creature::creature(){
    attack def;
    name = "";
    type = "";
    health = 0;
    mana = 0;
    for (int i = 0; i < 4; i++){
        attacks[i] = def;
    }
}

creature::creature(string inputName, string inputType, int inputHealth, attack inputAttacks[4]){
    name = inputName;
    type = inputType;
    health = inputHealth;
    mana = 100;
    for (int i = 0; i < 4; i++){
        attacks[i] = inputAttacks[i];
    }
}

string creature::getName(){
    return name;
}

void creature::setName(string inputName){
    name = inputName;
}

string creature::getType(){
    return type;
}

int creature::getHealth(){
    return health;
}

void creature::setHealth(int inputHealth){
    health = inputHealth;
}

int creature::getMana(){
    return mana;
}

void creature::setMana(int inputMana){
    mana = inputMana;
}

void creature::setType(string inputType)
{
    type=inputType;
}

attack creature::getAttack1(){
    return attacks[0];
}

attack creature::getAttack2(){
    return attacks[1];
}

attack creature::getAttack3(){
    return attacks[2];
}

attack creature::getAttack4(){
    return attacks[3];
}
void creature::setAttack(attack inputAttack, int index)
{
    attacks[index]=inputAttack;
}
