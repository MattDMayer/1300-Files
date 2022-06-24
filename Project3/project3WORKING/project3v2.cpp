#include <iostream>
#include <string>
#include "creature.h"
#include "attack.h"
#include "libraryOfThings.h"
#include "items.h"
#include "player.h"
#include "store.h"
#include "battle.h"
#include <fstream>
using namespace std;

//Code written by Kevin Lacjak and Matthew Mayer 2020

int split (string toBeSplit, char delim, string arr[], int size){
    int lastPos = 0;
    int arryPosition=0;
    int maxCol = 50;
    int length = toBeSplit.length();
    for (int i = 0; i < length; i++){
        if (arryPosition >= size){
            return -1;
        }
        else if (toBeSplit[i]==delim){
            arr[arryPosition] = toBeSplit.substr(lastPos,i-lastPos);
            arryPosition = arryPosition+1;
            lastPos=i+1;
        }
        else if (i == length-1){
            arr[arryPosition] = toBeSplit.substr(lastPos);
            arryPosition = arryPosition+1;
            lastPos=i+1;
        }
    }
    //returns the number of things in the array
    return arryPosition;
}
//startUpMenu coded by: Matthew Mayer

player startUpMenu()
{
    player plaTest;
    int control=0;
    while(control!=1&&control!=2)
    {
        cout<<"Welcome user! Are you a new or a returning player?"<<endl;
        cout<<"1. New"<<endl;
        cout<<"2. Returning"<<endl;
        cin>>control;
        if(control==1)
        {
            string playerName;
            cout<<"Welcome new player!"<<endl;
            cout<<"What is you name?"<<endl;
            cin>>playerName;
            if (playerName == "Quigley"){
                plaTest.addMoney(10000);
            }
            plaTest.setName(playerName);
            int creatureNum=0;
            cout<<"Which starter creature would you like? (Enter the number in front of the creature you want.)"<<endl;
            cout<<"1. Greta, Grass type creature who likes getting attention."<<endl;
            cout<<"2. Bruce, Water type creature who is kind of a chad."<<endl;
            cout<<"3. Ralphie, Fire type creature who likes to give charity to those in need."<<endl;
            cin>>creatureNum;
            string creatureName = "Ralphie";
            string type = "grass";
            libraryOfThings attacks;
            if(creatureNum==1)
            {
                cout<<"Great choice!"<<endl;
                creatureName="Greata";
                type="grass";
                //Health is up for change for all creatures.
            }
            else if(creatureNum==2)
            {
                cout<<"Awesome choice!"<<endl;
                creatureName="Bruce";
                type="water";
            }
            else if (creatureNum==42069){
                cout<<"GodModeActivated"<<endl;
                attack DabOnHaters("Dab on Haters",500,"fire",1);
                attack diamondSword("Diamond Sword",450,"fire",1);
                attack takeAwaySpringBreak("Take away Spring Break",600,"fire",1);
                attack globalThermonuclearWar("Global Thermonuclear War",750,"fire",0);
                attack godmodeAttacks[4] = {DabOnHaters,diamondSword,takeAwaySpringBreak,globalThermonuclearWar};
                creature godmode("John Wick","fire",100,godmodeAttacks);
                plaTest.addCreature(godmode);
            }
            else
            {
                if(creatureNum==3)
                {
                    cout<<"Nice choice!"<<endl;
                }
                else
                {
                    cout<<"Ralphie thinks you're a person in need, and joins you."<<endl;
                }
                creatureName="Ralphie";
                type="fire";
            }
            attack starterAttacks [4];
            for(int i=0;i<4;i++)
            {
                starterAttacks[i]=attacks.getOneRandomAttack();
            }
            creature starter(creatureName, type,100, starterAttacks);
            plaTest.addCreature(starter);
        }
        else if(control==2)
        {
            ifstream file;
            string fileName;
            string line;
            while(fileName!="Quit")
            {
                cout<<"Please enter a file name:"<<endl;
                cin>>fileName;
                file.open(fileName);
                if(file.fail()&&fileName!="Quit")
                {
                    cout<<"A file by that name cannot be found, please try again."<<endl;
                    cout<<"If you would like to back out, type: Quit"<<endl;
                    file.close();
                }
                else if(fileName=="Quit")
                {
                    control=3;
                }
                else
                {
                    creature loadCreature;
                    string temp[999];
                    attack attacks[4];
                    attack attackLoad;
                    item itemLoad;
                    int attackNum=3;
                    int data=-1;
                    while(getline(file, line))
                    {
                        if(line.substr(0,5)=="Name:")
                        {
                            data=0;
                        }
                        else if(line.substr(0,10)=="Creatures:")
                        {
                            data=1;
                        }
                        else if(line.substr(0,6)=="Items:")
                        {
                            data=2;
                        }
                        else if(line.substr(0,6)=="Money:")
                        {
                            data=3;
                        }
                        else if(data==0)
                        {
                            plaTest.setName(line);
                        }
                        else if(data==1)
                        {
                            split(line,',',temp,999);
                            loadCreature.setName(temp[0]);
                            loadCreature.setType(temp[1]);
                            loadCreature.setHealth(stoi(temp[2]));
                            for(int i=0;i<4;i++)
                            {
                                attackLoad.setName(temp[attackNum]);
                                attackNum++;
                                attackLoad.setDamage(stoi(temp[attackNum]));
                                attackNum++;
                                attackLoad.setType(temp[attackNum]);
                                attackNum++;
                                attackLoad.setManaCost(stoi(temp[attackNum]));
                                attackNum++;
                                attacks[i]=attackLoad;
                                loadCreature.setAttack(attackLoad,i);
                            }
                            plaTest.addCreature(loadCreature);
                            attackNum=3;
                        }
                        else if(data==2)
                        {
                            split(line,',',temp,999);
                            itemLoad.setName(temp[0]);
                            itemLoad.setModType(temp[1]);
                            itemLoad.setModValue(stoi(temp[2]));
                            plaTest.addItem(itemLoad);
                        }
                        else if(data==3)
                        {
                            plaTest.addMoney(stoi(line));
                        }
                    }
                    file.close();
                    return plaTest;
                }
            }
        }
        else
        {
            cout<<"Invalid input, please try again."<<endl;
        }
    }
    return plaTest;
}

//Coded by Matthew Mayer
void saveFile(player savePlayer)
{
    ofstream outputFile;
    string fileName;
    cout<<"Please input the name you want for your save. We will automatically add the file formatting for you."<<endl;
    cin>>fileName;
    fileName=fileName+".txt";
    cout<<fileName;
    outputFile.open(fileName);
    outputFile<<"Name:"<<endl;
    outputFile<<savePlayer.getName()<<endl;
    outputFile<<"Creatures:"<<endl;
    attack saveAttack;
    vector<creature> saveCreatures=savePlayer.getCreatureVector();
    for(int i=0;i<saveCreatures.size();i++)
    {
        outputFile<<saveCreatures[i].getName()<<",";
        outputFile<<saveCreatures[i].getType()<<",";
        outputFile<<saveCreatures[i].getHealth()<<",";
        for(int j=0;j<4;j++)
        {
            if(j==0)
            {
                saveAttack=saveCreatures[i].getAttack1();
            }
            else if(j==1)
            {
                saveAttack=saveCreatures[i].getAttack2();
            }
            else if(j==2)
            {
                saveAttack=saveCreatures[i].getAttack3();
            }
            else if(j==3)
            {
                saveAttack=saveCreatures[i].getAttack4();
            }
            outputFile<<saveAttack.getName()<<",";
            outputFile<<saveAttack.getDamage()<<",";
            outputFile<<saveAttack.getType()<<",";
            if(j==3)
            {
                outputFile<<saveAttack.getManaCost()<<endl;
            }
            else
            {
                outputFile<<saveAttack.getManaCost()<<",";
            }
        }
    }
    item saveItem;
    vector<item> saveItems=savePlayer.getItemVector();
    outputFile<<"Items:"<<endl;
    for(int i=0;i<saveItems.size();i++)
    {
        outputFile<<saveItems[i].getName()<<",";
        outputFile<<saveItems[i].getModType()<<",";
        outputFile<<saveItems[i].getModValue()<<endl;
    }
    outputFile<<"Money:"<<endl;
    outputFile<<savePlayer.getMoney();
    outputFile.close();
}

//Sort Creatures coded by Matthew Mayer, use sortTest.setCreatureVector(sortCreatures(sortTest)); to activate it in code for putting
//it together.
vector<creature> sortCreatures(player playerWithCreatures)
{
    vector<creature> creatureSort=playerWithCreatures.getCreatureVector();
    int size=creatureSort.size();
    int j;
    creature temp;
    int renameChoice;
    string newName;
    cout<<"Before your creatures are alphabetically sorted, would you like to rename a creature?[Y/N]"<<endl;
    char sureRename;
    cin>>sureRename;
    if(tolower(sureRename)==121)
    {
        for(int i=0;i<creatureSort.size();i++)
        {
            if(i!=creatureSort.size()-1)
            {
                cout<<i+1<<". "<<creatureSort[i].getName()<<", "; 
            }
            else if(i=creatureSort.size()-1)
            {
                cout<<i+1<<". "<<creatureSort[i].getName() << endl; 
            }
            else if (i==0&& creatureSort.size()==1)
            {
                cout<<i+1<<". "<<creatureSort[i].getName()<<endl;
            }
            else if(i==0&&creatureSort.size()!=1)
            {
                cout<<i+1<<". "<<creatureSort[i].getName()<<", ";
            }
            
        }
        cout<<"Which creature do you want to rename?"<<endl;
        cin>>renameChoice;
        if(renameChoice<=creatureSort.size()&&renameChoice>-1)
        {
            cout<<"What will this creature's new name be? (Note the creature can't have a space in it's new name.)"<<endl;
            cin>>newName;
            creatureSort[renameChoice-1].setName(newName);
        }
        else
        {
            cout<<"That was not a valid input so no creatures will not have their names changed."<<endl;
        }
    }
    else
    {
        cout<<"You opted not to rename any of your creatures."<<endl;
    }

    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if((toupper(creatureSort[j].getName()[0])<toupper(creatureSort[i].getName()[0])))
            {
                temp=creatureSort[i];
                creatureSort[i]=creatureSort[j];
                creatureSort[j]=temp;
            }
        }
    }
    return creatureSort;
}
void mainMenu(player gamePlayer)
{
    //This will display the main menu and take in an option from the user.
    //It will desplay the player's name, how many creatures they have, how many items and their money at the top
    // 1. Sign up for tournament
    //      This will have a sub menu for which lvl tournament
    //      Make three level tournaments and each one has random names and types.
    //          Check and see if user can afford tournament.
    //          If they can, subtract cost and start battle.
    // 2. Go to shop
    //      This will display a sub menu for either item shop or creature shop
    // 3. View and edit creatures owned
    //      Sort creatures by alphabetic order and display them all
    //      This will display a menu to rename any creature if the user wants to
    // 4. View Items
    // 5. Create save file
    // 6. Quit
    //      Will ask user if they're sure they want to quit.
    //SECRET CODE IDEA: If user enters "Quigley" the program will max out money for user
    int control=0;
    bool sureQuit;
    char quitter;
    int itemPick;
    battle bat(gamePlayer);
    store generalGoods;
    srand (time(NULL));
    while(control!=6)
    {
        cout<<"--------------------"<< endl;
        cout<<"Player Name: "<< gamePlayer.getName();
        cout<<"   Number of creatures: "<<gamePlayer.getCreatureVector().size();
        cout<<"   Number of items: "<<gamePlayer.getItemVector().size();
        cout<<"   Money: "<<gamePlayer.getMoney()<<endl;
        cout<<endl;
        cout<<"1. Sign up for tournament"<<endl;
        cout<<"2. Go to shop"<<endl;
        cout<<"3. View and edit creatures owned"<<endl;
        cout<<"4. View items"<<endl;
        cout<<"5. Create save file"<<endl;
        cout<<"6. Quit"<<endl;
        cout<<"Enter a menu option:"<<endl;
        cin>>control;
        switch(control)
        {
            default:
            {
                cout<<"Invalid input try a different input"<<endl;
                break;
            }
            case 1:
            {
                cout<<"Which level of tournament do you want to compete in?"<<endl;
                cout<<"1. Level: 1 Cost: 0 Award: 25  Battles: 3"<<endl;
                cout<<"2. Level: 2 Cost: 75 Award: 150 Battles: 6"<<endl;
                cout<<"3. Level: 3 Cost: 300 Award: 500 Battles: 12"<<endl;
                cout<<"4. Quit"<<endl;
                cin>>control;
                switch(control)
                {
                    default:
                    {
                        //Intentionally empty
                        control=1;
                        break;
                    }
                    case 1:
                    {
                        bat.setPlayer(gamePlayer);
                        gamePlayer=bat.oneTurn(1, gamePlayer);
                        control=1;
                        break;
                    }
                    case 2:
                    {
                        if (gamePlayer.getMoney()<75){
                            cout << "You dont have enough money to compete!" << endl;
                        }
                        else{
                            gamePlayer.subtractMoney(75);
                            cout << "$75 subtracted from your inventory!" << endl;
                            bat.setPlayer(gamePlayer);
                            gamePlayer=bat.oneTurn(2, gamePlayer);
                        }
                        control=1;
                        break;
                    }
                    case 3:
                    {
                        if(gamePlayer.getMoney()<300){
                            cout << "You dont have enough money to compete!" << endl;
                        }
                        else{
                            gamePlayer.subtractMoney(300);
                            cout << "$300 subtracted from your inventory" << endl;
                            bat.setPlayer(gamePlayer);
                            gamePlayer=bat.oneTurn(3, gamePlayer);
                        }
                        control=1;
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                cout<<"Do you want to go to the item shop or the creature shop?"<<endl;
                cout<<"1. Item shop"<<endl;
                cout<<"2. Creature shop"<<endl;
                cin>>control;
                if(control==1)
                {
                    itemPick=generalGoods.listItems();
                    gamePlayer=generalGoods.purchaseSelectedItem(gamePlayer,itemPick);
                    if (gamePlayer.getItemVector().size()>0){
                        cout<<gamePlayer.getItemAt(gamePlayer.getItemVector().size()-1).getName();
                    }
                }
                else
                {
                    itemPick=generalGoods.listCreatures();
                    gamePlayer=generalGoods.purchaseSelectedCreature(gamePlayer,itemPick);
                }
                control=2;
                break;
            }
            case 3:
            {
                gamePlayer.setCreatureVector(sortCreatures(gamePlayer));
                gamePlayer.listUserCreatues();
                break;
            }
            case 4:
            {
                gamePlayer.listUserItems();
                break;
            }
            case 5:
            {
                saveFile(gamePlayer);
                break;
            }
            case 6:
            {
                cout<<"Are you sure you want to quit? [Y/N]"<<endl;
                cin>>quitter;
                if(tolower(quitter)==121)
                {
                    cout<<"Good bye!"<<endl;
                }
                else
                {
                    cout<<"Thank you for staying!"<<endl;
                }
                break;
            }
        }
    }
}

int main()
{
    player gamePlayer;
    gamePlayer=startUpMenu();
    mainMenu(gamePlayer);

}
