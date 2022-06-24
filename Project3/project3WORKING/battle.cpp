#include <iostream>
#include "battle.h"
#include "items.h"
#include "attack.h"
#include "creature.h"
#include "libraryOfThings.h"
#include "player.h"
#include <string>
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

battle::battle(){
    player pEmpty;
    creature cEmpty;
    user = pEmpty;
    vector <creature> usersCreatures;
    vector <creature> opponentsCreatures;
    vector <item> usersItems;
    currentUserCreature = cEmpty;
    currentOpponentCreature = cEmpty;
}

battle::battle(player inputUser){
    user = inputUser;
    usersItems = user.getItemVector();
    usersCreatures = user.getCreatureVector();
}

void battle::setPlayer(player inputUser){
    user = inputUser;
    usersCreatures = user.getCreatureVector();
}

void battle::setPlayerFighter(int positionOfCreatueInVector){
    currentUserCreature = usersCreatures.at(positionOfCreatueInVector-1);
}

void battle::setOpponentFighter(int positionOfCreatueInVector){
    currentOpponentCreature = opponentsCreatures.at(positionOfCreatueInVector);
}

creature battle::getPlayerFighter(){
    return currentUserCreature;
}

creature battle::getOpponentFighter(){
    return currentOpponentCreature;
}

attack battle::getRandomOpponentAttack(){
    int attackChoice = rand() % 4 + 1;
    attack errorEmpty;
    switch (attackChoice){
    case 1:
        return currentOpponentCreature.getAttack1();
        break;
    case 2:
        return currentOpponentCreature.getAttack2();
        break;
    case 3:
        return currentOpponentCreature.getAttack3();
        break;
    case 4:
        return currentOpponentCreature.getAttack4();
        break;
    default:
        cout << "Invalid attack error" << endl;
        return errorEmpty;
    }
}

void battle::listAllAttacks(){
    attack tempAttack;
    cout << currentUserCreature.getName() << "'s attacks." << endl;
    attack attackArray[4] = {currentUserCreature.getAttack1(),currentUserCreature.getAttack2(),currentUserCreature.getAttack3(),currentUserCreature.getAttack4()};
    for (int j = 0;j < 4;j++){
        tempAttack = attackArray[j];
        cout << "Attack: " << j+1 << endl;
        cout << "   Name: " << tempAttack.getName() << endl;
        cout << "   Type: " << tempAttack.getType() << endl;
        cout << "   Damage: " << tempAttack.getDamage() << endl;
        cout << "   Mana Cost: " << tempAttack.getManaCost() << endl;
    }

}

void battle::createOpponentCreatures(int lvl){
    creature temp;
    libraryOfThings lib;
    switch (lvl){
    case 1:
        for (int i = 0; i < 3; i++){
            temp = lib.getARandomCreature(1);
            opponentsCreatures.push_back(temp);
        }
        break;
    case 2:
        for (int i = 0; i < 6; i++){
            temp = lib.getARandomCreature(2);
            opponentsCreatures.push_back(temp);
        }
        break;
    case 3:
        for (int i = 0; i < 12; i++){
            temp = lib.getARandomCreature(3);
            opponentsCreatures.push_back(temp);
        }
        break;
    default:
        cout << "Invalid Tournament Level" << endl;
        break;
    }
}

int battle::selectCreatureToFight(){
    int creatureChoice;
    char exitChoice;
    int count = 0;
    creature testCreature;
    bool exitOne = true;
    bool exitTwo = true;
    for(int i = 0; i < user.getCreatureVector().size(); i++){
        testCreature = user.getCreatureVector().at(i);
        if(testCreature.getHealth() <= 0){
            count = count + 1;
        }
    }
    if (count == user.getCreatureVector().size()){
        return -1;
    }
    while (exitOne == true){
        exitTwo = true;
        cout << "Please select a creature:" << endl;
        user.listUserCreatues();
        cin >> creatureChoice;
        setPlayerFighter(creatureChoice);
        cout << currentUserCreature.getName() << " selected. Are you sure?" << endl;
        while(exitTwo == true){
            cout << "Y/N" << endl;
            cin >> exitChoice;
            toupper(exitChoice);
            if (exitChoice == 'Y'){
                exitTwo = false;
            }
            else if (exitChoice == 'N'){
                exitTwo = false;
            }
            else{
                cout << "Invalid Input" << endl;
                exitTwo == true;
            }
        }
        if (currentUserCreature.getHealth() <= 0){
            cout << "That creature is unconcious! Please select a different creature." << endl;
        }
        else if (exitChoice == 'N'){
            
        }
        else{
            cout << currentUserCreature.getName() << " selected!" << endl;
            exitOne = false;
        }
    }
    return creatureChoice-1;
}

player battle::oneTurn(int lvl, player inputUser){
    bool exitTwo = true;
    bool bigLoop = true;
    bool skip = false;
    bool opponentAlive = false;
    bool userAlive = false;
    user = inputUser;
    int attackChoice;
    int itemChoice;
    int attackOrItem;
    int healthCheck;
    int damageDelt;
    int manaCost;
    int numOfBaddies;
    int roundNum = 0;
    attack tempAttack;
    attack tempOpAttack;
    item chosenItem;
    int opponentCreatureNum = 0;
    createOpponentCreatures(lvl);
    numOfBaddies = opponentsCreatures.size();
    while (bigLoop == true){
        if (roundNum >= numOfBaddies){
            cout << "You defeated all the opponents! YOU WIN!!" << endl;
            switch (lvl){
            case 1:
                user.addMoney(25);
                cout << "You have been awarded $25 for winning!" << endl;
                break;
            case 2:
                user.addMoney(150);
                cout << "You have been awarded $150 for winning!" << endl;
                break;
            case 3:
                user.addMoney(500);
                cout << "You have been awarded $500 for winning!" << endl;
                break;
            }
            usersCreatures.push_back(currentUserCreature);
            user.setCreatureVector(usersCreatures);
            for (int i = 0; i < usersCreatures.size(); i++){
                usersCreatures.at(i).setHealth(100);
            }
            return user;
        }
        else{
            if (opponentAlive == false){
                currentOpponentCreature = opponentsCreatures.at(opponentCreatureNum);
                opponentAlive = true;
            }
            cout << opponentCreatureNum+1 << "nd Opponent Creature: " << currentOpponentCreature.getName() << endl;
            cout << "   Type: " << currentOpponentCreature.getType() << endl;
            cout << "   Health: " << currentOpponentCreature.getHealth() << endl;
            cout << "   Mana: " << currentOpponentCreature.getMana() << endl;
            attack attackArray[4] = {currentOpponentCreature.getAttack1(),currentOpponentCreature.getAttack2(),currentOpponentCreature.getAttack3(),currentOpponentCreature.getAttack4()};
            for (int j = 0;j < 4;j++){
                tempAttack = attackArray[j];
                cout << "   Attack: " << j+1 << endl;
                cout << "       Name: " << tempAttack.getName() << endl;
                cout << "       Type: " << tempAttack.getType() << endl;
                cout << "       Damage: " << tempAttack.getDamage() << endl;
                cout << "       Mana Cost: " << tempAttack.getManaCost() << endl;
            }
            cout << "--------------------" << endl;
            if (userAlive == false){
                healthCheck = selectCreatureToFight();
                usersCreatures.erase(usersCreatures.begin()+healthCheck);
                user.setCreatureVector(usersCreatures);
                if (healthCheck == -1){
                    cout << "You have no consious creatures! You loose" << endl;
                    usersCreatures.push_back(currentUserCreature);
                    user.setCreatureVector(usersCreatures);
                    for (int i = 0; i < usersCreatures.size(); i++){
                        usersCreatures.at(i).setHealth(100);
                    }
                    return user;
                }
                userAlive = true;
                cout << "Prepare to fight!" << endl;
            }
            cout << "--------------------" << endl;
            cout << currentUserCreature.getName() << "'s turn!" << endl;
            cout << currentUserCreature.getName() << "'s health: " << currentUserCreature.getHealth() << endl;
            cout << "Mana: " << currentUserCreature.getMana() << endl;
            cout << "Type: " << currentUserCreature.getType() << endl;
            cout << "---------------------" << endl;
            exitTwo = true;
            while (exitTwo == true){
                cout << "--------------------"<<endl;
                cout << "Select Attack, enter 5 to view items or enter 6 to switch creature (You will take damage if you switch):" << endl;
                listAllAttacks();
                cin >> attackChoice;
                switch (attackChoice){
                case 1:
                    if (currentUserCreature.getMana() < currentUserCreature.getAttack1().getManaCost()){
                        cout << "Not enough mana" << endl;
                    }
                    else{
                        cout << currentUserCreature.getName() << " used " << currentUserCreature.getAttack1().getName() << endl;
                        damageDelt = currentUserCreature.getAttack1().getDamage();
                        manaCost = currentUserCreature.getAttack1().getManaCost();
                        exitTwo = false;
                        if ((currentUserCreature.getAttack1().getType() == "grass") && (currentOpponentCreature.getType() == "water")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                        else if ((currentUserCreature.getAttack1().getType() == "water") && (currentOpponentCreature.getType() == "fire")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                        else if ((currentUserCreature.getAttack1().getType() == "fire") && (currentOpponentCreature.getType() == "grass")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                    }
                    break;
                case 2:
                    if (currentUserCreature.getMana() < currentUserCreature.getAttack2().getManaCost()){
                        cout << "Not enough mana" << endl;
                    }
                    else{
                        cout << currentUserCreature.getName() << " used " << currentUserCreature.getAttack2().getName() << endl;
                        damageDelt = currentUserCreature.getAttack2().getDamage();
                        manaCost = currentUserCreature.getAttack2().getManaCost();
                        exitTwo = false;
                        if ((currentUserCreature.getAttack2().getType() == "grass") && (currentOpponentCreature.getType() == "water")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                        else if ((currentUserCreature.getAttack2().getType() == "water") && (currentOpponentCreature.getType() == "fire")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                        else if ((currentUserCreature.getAttack2().getType() == "fire") && (currentOpponentCreature.getType() == "grass")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                    }
                    break;
                case 3:
                    if (currentUserCreature.getMana() < currentUserCreature.getAttack3().getManaCost()){
                        cout << "Not enough mana" << endl;
                    }
                    else{
                        cout << currentUserCreature.getName() << " used " << currentUserCreature.getAttack3().getName() << endl;
                        damageDelt = currentUserCreature.getAttack3().getDamage();
                        manaCost = currentUserCreature.getAttack3().getManaCost();
                        exitTwo = false;
                        if ((currentUserCreature.getAttack3().getType() == "grass") && (currentOpponentCreature.getType() == "water")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                        else if ((currentUserCreature.getAttack3().getType() == "water") && (currentOpponentCreature.getType() == "fire")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                        else if ((currentUserCreature.getAttack3().getType() == "fire") && (currentOpponentCreature.getType() == "grass")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                    }
                    break;
                case 4:
                    if (currentUserCreature.getMana() < currentUserCreature.getAttack4().getManaCost()){
                        cout << "Not enough mana" << endl;
                    }
                    else{
                        cout << currentUserCreature.getName() << " used " << currentUserCreature.getAttack4().getName() << endl;
                        damageDelt = currentUserCreature.getAttack4().getDamage();
                        manaCost = currentUserCreature.getAttack4().getManaCost();
                        exitTwo = false;
                        if ((currentUserCreature.getAttack4().getType() == "grass") && (currentOpponentCreature.getType() == "water")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                        else if ((currentUserCreature.getAttack4().getType() == "water") && (currentOpponentCreature.getType() == "fire")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                        else if ((currentUserCreature.getAttack4().getType() == "fire") && (currentOpponentCreature.getType() == "grass")){
                            cout << "It was super affective" << endl;
                            damageDelt = damageDelt * 1.25;
                        }
                    }
                    break;
                    case 5:
                        user.listUserItems();
                        usersItems = user.getItemVector();
                        if (usersItems.size() == 0){
                            cout << "You have no items" << endl;
                            break;
                        }
                        cout << "Enter the number of which Item you want to use:" << endl;
                        cin >> itemChoice;
                        if (itemChoice > usersItems.size()){
                            cout << "Invalid Choice" << endl;
                            break;
                        }
                        chosenItem = usersItems.at(itemChoice-1);
                        usersItems.erase(usersItems.begin()+(itemChoice-1));
                        user.setItemsVector(usersItems);
                        if (chosenItem.getName() == "Holy Hand Grenade"){
                            damageDelt = 50;
                            exitTwo = false;
                        }
                        else if (chosenItem.getName() == "Health Potion"){
                            currentUserCreature.setHealth(currentUserCreature.getHealth()+25);
                            cout << currentUserCreature.getName() << "'s health was increased to " << currentUserCreature.getHealth() << "!" << endl;
                        }
                        else if (chosenItem.getName() == "Mana Potion"){
                            currentUserCreature.setMana(currentUserCreature.getMana()+25);
                            cout << currentUserCreature.getName() << "'s mana was increased to " << currentUserCreature.getMana() << "!" << endl;
                        }
                        else if (chosenItem.getName() == "Cat Toy"){
                            skip = true;
                        }
                        break;
                    case 6:
                        userAlive = false;
                        cout << "You will switch creatures after opponent's turn" << endl;
                        exitTwo = false;
                        usersCreatures.push_back(currentUserCreature);
                        user.setCreatureVector(usersCreatures);
                        damageDelt = 0;
                        break;
                default:
                    cout << "Invalid Attack" << endl;
                    break;
                }
            }
            currentUserCreature.setMana(currentUserCreature.getMana() - manaCost);
            currentOpponentCreature.setHealth(currentOpponentCreature.getHealth() - damageDelt);
            cout << currentUserCreature.getName() << " delt " << damageDelt << " damage!" << endl;
            if (currentOpponentCreature.getHealth() <= 0){
                cout << "You win this round!" << endl;
                cout << "-------------------" << endl;
                roundNum = roundNum+1;
                opponentCreatureNum = opponentCreatureNum +1;
                opponentAlive = false;
            }
            else if (skip == false)
            {
                cout << "-------------------" << endl;
                cout << currentOpponentCreature.getName() << "'s turn!" << endl;
                tempOpAttack = getRandomOpponentAttack();
                cout << currentOpponentCreature.getName() << " uses " << tempOpAttack.getName() << endl; 
                damageDelt = tempOpAttack.getDamage();   
                if ((tempOpAttack.getType() == "grass") && (currentUserCreature.getType() == "water")){
                    cout << "It was super affective" << endl;
                    damageDelt = damageDelt * 1.25;
                }
                else if ((tempOpAttack.getType() == "water") && (currentUserCreature.getType() == "fire")){
                    cout << "It was super affective" << endl;
                    damageDelt = damageDelt * 1.25;
                }
                else if ((tempOpAttack.getType() == "fire") && (currentOpponentCreature.getType() == "grass")){
                    cout << "It was super affective" << endl;
                    damageDelt = damageDelt * 1.25;
                }
                currentUserCreature.setHealth(currentUserCreature.getHealth() - damageDelt);
                cout << currentOpponentCreature.getName() << " delt " << damageDelt << " damage!" << endl;
                if (currentUserCreature.getHealth() <= 0){
                    cout << currentUserCreature.getName() << " fainted!!" << endl;
                    userAlive = false;
                    if (attackChoice == 6){
                        usersCreatures.pop_back();
                        user.setCreatureVector(usersCreatures);
                    }
                    usersCreatures.push_back(currentUserCreature);
                    user.setCreatureVector(usersCreatures);
                }
            }
            else if (skip == true){
                cout << "-----------------" << endl;
                cout << "Opponents turn skipped!" << endl;
                cout << "-----------------" << endl;
                skip = false;
            }
        }
    }
    //should never reach
    return user;
}