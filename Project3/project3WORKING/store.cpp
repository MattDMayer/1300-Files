#include <iostream>
#include <string>
#include "store.h"
#include "player.h"
#include "creature.h"
#include "attack.h"
#include "libraryOfThings.h"
#include "items.h"
#include <cmath>
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

store::store(){
    libraryOfThings library;
    int sale = 0;
    item hP("Health Potion", "+25 HP", 25);
    item mP("Mana Potion","+25 MP", 25);
    item cT("Cat Toy","Skip Opponent's Turn",0);
    item hHG("Holy Hand Grenade","50HP of Damage to Opponent",50);
    item tempArray[4] = {hP,mP,cT,hHG};
    for (int i = 0; i < 4; i++){
        itemArray[i] = tempArray [i];
    }
}

int store::listItems(){
    int input;
    bool quit = false;
    int saleChance;
    item tempItem;
    saleChance = rand() % 4 + 1;
    if (saleChance == 1){
        cout << "Congragulations! Today we're having a 20% sale!" << endl;
        sale = 1;
    }
    else if (saleChance != 0){
        sale = 0;
    }
    cout << "Here are the items for sale!" << endl;
    for (int i = 0; i < 4; i++){
        tempItem = itemArray[i];
        cout << "Item " << i+1 << ":" << endl;
        cout << tempItem.getName() << endl;
        cout << tempItem.getModType() << endl;
        if (i == 0){
            //hp cost
            cout << "Cost: $" << 10 * pow(.8,sale) << endl;
        }
        else if (i == 1){
            //mp cost
            cout << "Cost: $" << 10 * pow(.8,sale) << endl;
        }
        else if (i == 2){
            //ct cost
            cout << "Cost: $" << 20 * pow(.8,sale) << endl;
        }
        else if (i == 3){
            //hhg cost
            cout << "Cost: $" << 50 * pow(.8,sale) << endl;
        }
        cout << "--------------------" << endl;
    }
    while (quit == false){
        cout << "Type the number of the item youre interesting in buying in order to purchase it! Or enter 0 to exit the store!" << endl;
        cin >> input;
        if ((input < 0) || (input > 4)){
            cout << "Invalid option." << endl;
        }
        else{
            quit = true;
        }
    }
    return input;
}

int store::listCreatures(){
    int input;
    bool quit = false;
    int saleChance;
    libraryOfThings library;
    creature tempCreature;
    attack temp1;
    attack temp2;
    attack temp3;
    attack temp4;
    attack tempAttack;
    one = library.getARandomCreature(3);
    two = library.getARandomCreature(3);
    three = library.getARandomCreature(3);
    four = library.getARandomCreature(3);
    one.setHealth(100);
    two.setHealth(100);
    three.setHealth(100);
    four.setHealth(100);
    creature tempCreatArry[4] = {one, two, three, four};
    saleChance = rand() % 4 + 1;
    if (saleChance == 1){
        cout << "Congragulations! Today we're having a 20% sale!" << endl;
        sale = 1;
    }
    else if (saleChance != 1){
        sale = 0;
    }
    for (int i = 0; i < 4; i++){
        creatureArray[i] = tempCreatArry[i];
    }
    cout << "Here are the creatures for sale!" << endl;
    for (int i = 0; i < 4; i++){
        tempCreature = creatureArray[i];
        temp1 = tempCreature.getAttack1();
        temp2 = tempCreature.getAttack2();
        temp3 = tempCreature.getAttack3();
        temp4 = tempCreature.getAttack4();
        attack tempAttackArray[4]={temp1,temp2,temp3,temp4};
        cout << "Creature: " << i+1 << endl;
        cout << "   Name: " << tempCreature.getName()<<endl;
        cout << "   Type: " << tempCreature.getType() << endl;
        cout << "   Health: " << tempCreature.getHealth() << endl;
        cout << "   Mana: " << tempCreature.getMana() << endl;
        for (int j = 0;j < 4;j++){
            tempAttack = tempAttackArray[j];
            cout << "   Attack: " << j+1 << endl;
            cout << "       Name: " << tempAttack.getName() << endl;
            cout << "       Type: " << tempAttack.getType() << endl;
            cout << "       Damage: " << tempAttack.getDamage() << endl;
            cout << "       Mana Cost: " << tempAttack.getManaCost() << endl;
        }
        cout << "--------------------"  << endl;
    }
    cout << "Cost of all creatures: $" << 50 * pow(.8,sale) << endl;
    cout << endl;
    while (quit == false){
        cout << "Type the number of the creature youre interesting in buying in order to purchase it! Or enter 0 to exit the store!" << endl;
        cin >> input;
        if ((input < 0) || (input >4)){
            cout << "Invalid option." << endl;
        }
        else{
            quit = true;
        }
    }
    return input;
}

player store::purchaseSelectedItem(player user, int input){
    int choice = input;
    int userMoney = user.getMoney();
    int tempCost;
    switch (choice){
    case 1:
        tempCost = (10 * pow(.8,sale));
        if (userMoney >= tempCost){
            user.subtractMoney(tempCost);
            user.addItem(itemArray[0]);
            cout << "Health Potion added to inventory! $" << tempCost << "has been removed from your money." << endl;
        }
        else{
            cout << "You do not have enough money to purchase this item. Compete in a tournament and come back later. Good luck!" << endl;
        }
        break;
    case 2:
        tempCost = (10 * pow(.8,sale));
        if (userMoney >= tempCost){
            user.subtractMoney(tempCost);
            user.addItem(itemArray[1]);
            cout << "Mana Potion added to inventory! $" << tempCost << " has been removed from your money." << endl;
        }
        else{
            cout << "You do not have enough money to purchase this item. Compete in a tournament and come back later. Good luck!" << endl;
        }
        break;
        break;
    case 3:
        tempCost = (20 * pow(.8,sale));
        if (userMoney >= tempCost){
            user.subtractMoney(tempCost);
            user.addItem(itemArray[2]);
            cout << "Cat Toy added to inventory! $" << tempCost << " has been removed from your money." << endl;
        }
        else{
            cout << "You do not have enough money to purchase this item. Compete in a tournament and come back later. Good luck!" << endl;
        }
        break;
    case 4:
        tempCost = (50 * pow(.8,sale));
        if (userMoney >= tempCost){
            user.subtractMoney(tempCost);
            user.addItem(itemArray[3]);
            cout << "Holy Hand Gernade added to inventory! $" << tempCost << " has been removed from your money." << endl;
        }
        else{
            cout << "You do not have enough money to purchase this item. Compete in a tournament and come back later. Good luck!" << endl;
        }
        break;
    default:
        cout << "Come back soon!" << endl;
    }
    cout << "--------------------" << endl;
    return user;
}

player store::purchaseSelectedCreature(player user,int input){
    int choice = input;
    int tempCost = (50 * pow(.8,sale));
    int userMoney = user.getMoney();
    if (userMoney >= (50 * pow(.8,sale))){
        switch (choice){
            case 1:
                user.subtractMoney(tempCost);
                user.addCreature(one);
                cout << one.getName() <<" added to inventory! $" << tempCost << " has been removed from your money." << endl;
            break;
            case 2:
                user.subtractMoney(tempCost);
                user.addCreature(two);
                cout << two.getName() <<" added to inventory! $" << tempCost << " has been removed from your money." << endl;
            break;
            case 3:
                user.subtractMoney(tempCost);
                user.addCreature(three);
                cout << three.getName() <<" added to inventory! $" << tempCost << " has been removed from your money." << endl;
            break;
            case 4:
                user.subtractMoney(tempCost);
                user.addCreature(four);
                cout << four.getName() <<" added to inventory! $" << tempCost << " has been removed from your money." << endl;
            break;
        }
    }
    else{
        cout << "You do not have enough money to purchase any creatures. Compete in a tournament and come back later. Good luck!" << endl;
    }
    return user;
}