//Code written by Matthew Mayer 2020
//Partner: Kevin Lacjack

#include "player.h"
#include <iostream> 
#include "creature.h"
#include "items.h"
#include <vector>
using namespace std;
    player::player()
    {
        name="";
        money=0;
        vector<creature> creatures;
        vector<item> items;
    }
    player::player(string inputname, vector<creature> inputcreatures, vector<item> inputitems, int inputmoney)
    {
        creature empty;
        name=inputname;
        money=inputmoney;
        for(int i=0;i<inputcreatures.size();i++)
        {
            creatures.push_back(inputcreatures[i]);
        }
        for(int i=0;i<inputitems.size();i++)
        {
            items.push_back(inputitems[i]);
        }
    }
    void player:: setName(string inputname)
    {
        name=inputname;
    }
    string player:: getName()
    {
        return name;
    }
    int player::getMoney()
    {
        return money;
    }
    void player:: addMoney(int change)
    {
        money=money+change;
    }
    void player:: subtractMoney(int change)
    {
        money=money-change;
    }
    creature player:: getCreatureAt(int index)
    {
        return creatures[index];
    }
    item player:: getItemAt(int index)
    {
        return items[index];
    }
    void player:: addItem(item itemGive)
    {
        items.push_back(itemGive);
    }
    void player:: removeItemAt(int index)
    {
        items.erase(items.begin()+index);
    }
    void player:: addCreature(creature creatureAdd)
    {
        creatures.push_back(creatureAdd);
    }
    vector <creature> player::getCreatureVector(){
        return creatures;
    }
    vector <item> player::getItemVector(){
        return items;
    }
    void player:: setCreatureVector(vector<creature> newCreatures)
    {
        creatures = newCreatures;
    }
    void player:: setItemsVector(vector<item> newItems)
    {
        items = newItems;
    }
    void player::listUserCreatues(){
        creature tempCreature;
        cout << name << "'s creatures:" << endl;
        cout << "--------------------" << endl;
        for (int i = 0; i < creatures.size(); i++){
            tempCreature = creatures.at(i);
            cout << "Name: " << tempCreature.getName()<<endl;
            cout << "   Type: " << tempCreature.getType() << endl;
            cout << "   Health: " << tempCreature.getHealth() << endl;
            cout << "   Mana: " << tempCreature.getMana() << endl;
        }
    }
    void player::listUserItems(){
        item tempItem;
        cout << name << "'s items:" << endl;
        cout << "--------------------" << endl;
        for (int i = 0; i < items.size(); i++){
            tempItem = items.at(i);
            cout << "Name: " << tempItem.getName() << endl;
            cout << "   Type: " << tempItem.getModType() << endl;
        }
    }