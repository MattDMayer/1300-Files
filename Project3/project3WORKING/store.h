#ifndef STORE_H
#define STORE_H
#include <iostream>
#include "attack.h"
#include "creature.h"
#include "items.h"
#include "libraryOfThings.h"
#include <string>
#include "player.h"
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

class store{
    private:
        item itemArray[4];
        int sale;
        creature creatureArray[4];
        creature selectedCreature;
        item selectedItem;
        item healthPotion;
        item manaPotion;
        item catToy;
        item holyHandGernade;
        creature one;
        creature two;
        creature three;
        creature four;
    public:
        store();
        int listItems();
        player purchaseSelectedItem(player user, int choice);
        int listCreatures();
        player purchaseSelectedCreature(player user, int choice);
};
#endif