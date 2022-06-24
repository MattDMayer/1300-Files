//Code written by Matthew Mayer 2020
//Partner: Kevin Lacjack

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream> 
#include "creature.h"
#include <vector>
#include "items.h"
using namespace std;

class player
{
    private:
    string name;
    int money;
    int numOfCreatures;
    vector<creature> creatures;
    vector<item> items;

    public:
    player();
    player(string inputname, vector<creature> inputcreatures,vector<item> inputitems, int inputmoney);
    string getName();
    void setName(string inputname);
    int getMoney();
    void addMoney(int inputmoney);
    void subtractMoney(int inputmoney);
    creature getCreatureAt(int index);
    item getItemAt(int index);
    void addItem(item itemGive);
    void removeItemAt(int index);
    void addCreature(creature creatureAdd);
    vector <creature> getCreatureVector();
    vector <item> getItemVector();
    void setCreatureVector(vector<creature> newCreatureVector);
    void setItemsVector(vector<item> newItemVector);
    void listUserCreatues();
    void listUserItems();

};
#endif