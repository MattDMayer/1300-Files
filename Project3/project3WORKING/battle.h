#ifndef BATTLE_H
#define BATTLE_H
#include "attack.h"
#include "player.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Code written by Kevin Lacjack
//Partner: Matthew Mayer

class battle{
    private:
        player user;
        vector <creature> usersCreatures;
        vector <creature> opponentsCreatures;
        vector <item> usersItems;
        creature currentUserCreature;
        creature currentOpponentCreature;
    public:
        battle();
        battle(player user);
        void setPlayer(player inputUser);
        void createOpponentCreatures(int lvl);
        void setPlayerFighter(int positionOfCreatueInVector);
        void setOpponentFighter(int positionOfCreatureInVector);
        void listAllAttacks();
        attack getRandomOpponentAttack();
        creature getPlayerFighter();
        creature getOpponentFighter();
        int selectCreatureToFight();
        player oneTurn(int lvl, player inputUser);
};
#endif