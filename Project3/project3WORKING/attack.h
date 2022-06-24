#ifndef ATTACK_H
#define ATTACK_H
#include <iostream>
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

class attack{
    private:
        string attackName;
        int damage;
        string type;
        int manaCost;
    public:
        attack();
        attack(string attackName, int damage, string type, int manaCost);
        string getName();
        int getDamage();
        string getType();
        int getManaCost();
        void setName(string inputName);
        void setDamage(int inputDamage);
        void setType(string inputType);
        void setManaCost(int inputManaCost);
};
#endif