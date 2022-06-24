#ifndef CREATURE_H
#define CREATURE_H
#include "attack.h"
#include <iostream>
#include <string>
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

class creature{
    private:
        string name;
        string type;
        int health;
        int mana;
        attack attacks[4];
    public: 
        creature();
        creature(string name, string type, int health, attack attacks[4]);
        string getName();
        void setName(string name);
        string getType();
        int getHealth();
        void setHealth(int changeHealth);
        int getMana();
        void setType(string inputType);
        void setMana(int changeMana);
        attack getAttack1();
        attack getAttack2();
        attack getAttack3();
        attack getAttack4();
        void setAttack(attack newAttack, int inputindex);
};
#endif