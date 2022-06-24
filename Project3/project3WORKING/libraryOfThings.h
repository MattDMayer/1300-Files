#ifndef LIBRARYOFTHINGS_H
#define LIBRARYOFTHINGS_H
#include <iostream>
#include "attack.h"
#include "creature.h"
#include <vector>
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

class libraryOfThings{
    private:
        attack attackArray[18];
        creature creatureArray[12];
        string grassNames[5];
        string waterNames[5];
        string fireNames[5];
        creature chosenOne;
        int tourneyLvl;
    public:
        libraryOfThings();
        attack getOneRandomAttack();
        vector <attack> getVectorOfFourAttacks();
        creature getARandomCreature(int tourneyLvl);
};
#endif