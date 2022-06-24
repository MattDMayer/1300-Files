#include <iostream>
#include <string>
#include "creature.h"
#include "attack.h"
#include "libraryOfThings.h"
#include "items.h"
#include <vector>
using namespace std;
//Code written by Kevin Lacjak 2020
//Partner: Matthew Mayer

libraryOfThings::libraryOfThings(){
    //grass attacks
    attack grassWhip("Grass Whip",10,"grass",5);
    attack poisonIvy("Poison Ivy",15,"grass",5);
    attack sting("Sting",5,"grass",5);
    attack biteG("Bite",5,"grass",5);
    attack remindofCollegeDebt("Remind of college debt",20,"grass",10);
    attack taxFraud("Tax Fraud",20,"grass",10);
    //water attacks
    attack biteW("Bite",5,"water",5);
    attack meowingMidLecture("Meowing-Mid-Lecture",25,"water",10);
    attack errode("Errode",10,"water",5);
    attack waterGun("Water Gun",10,"water",5);
    attack evaporate("Evaporate",10,"water",5);
    attack coloradoGreeleyStench("Colorado Greeley Stench",15,"water",10);
    //fire attacks
    attack biteF("Bite",5,"fire",5);
    attack FifthdegreeBurns("5th Degree Burns",25,"fire",10);
    attack TheTragedyofDarthPlageiustheWise("The tragedy of Darth Plageius the Wise",50,"fire",15);
    attack hurtFeelings("Hurt Feelings",15,"fire",5);
    attack PETA("PETA",15,"fire",10);
    attack spitFire("Spit Fire",10,"fire",5);
    //array of all these attacks
    attack temp[18] = {grassWhip,poisonIvy,sting,biteG,remindofCollegeDebt,taxFraud,biteW,meowingMidLecture,errode,waterGun,evaporate,coloradoGreeleyStench,biteF,FifthdegreeBurns,TheTragedyofDarthPlageiustheWise,hurtFeelings,PETA,spitFire};
    for (int i = 0; i < 18; i++){
        attackArray[i]=temp[i];
    }
    //grass names
    string name1 = "beeeeeeeeeeeeee";
    string name2= "ant";
    string name3= "ssarg";
    string name4="Segmentation bug";
    string name5="Timone";
    //put all the grass strings in an array
    string tempGrassNames[5] = {name1,name2,name3,name4,name5};
    for (int i = 0; i < 5; i++){
        grassNames[i]=tempGrassNames[i];
    }
    //water names
    string name6 = "splash mountain";
    string name7 = "ride-the-wave";
    string name8 ="thirsty";
    string name9 ="moist";
    string name10="SharkBoy";
    //put all water strings in an array;
    string tempWaterNames[5]={name6,name7,name8,name9,name10};
    for (int i = 0; i < 5; i++){
        waterNames[i]=tempWaterNames[i];
    }
    //fire names
    string name11 ="ahh im on fire";
    string name12="flamer";
    string name13="burning-man";
    string name14="roasty toasty";
    string name15="LavaGirl";
    //put all fire names in an array
    string tempFireNames[5]={name11,name12,name13,name14,name15};
    for (int i = 0; i < 5; i++){
        fireNames[i]=tempFireNames[i];
    }
}

attack libraryOfThings::getOneRandomAttack(){
    int random1 = rand() % 18;
    attack one;
    one = attackArray[random1];
    return one;

}

vector <attack> libraryOfThings::getVectorOfFourAttacks(){
    vector <attack> vectorAttack;
    attack temp;
    for (int i = 0; i < 4; i++){
        temp = getOneRandomAttack();
        vectorAttack.push_back(temp);
    }
    return vectorAttack;
}

creature libraryOfThings::getARandomCreature(int myTourneyLvl){
    int typeNum = rand() % 3;
    int healthNum;
    int tempHealthNum;
    int nameNum = rand() % 5;
    string type;
    attack attacks[4];
    string name;
    vector <attack> attackVectorTemp;
    attackVectorTemp = getVectorOfFourAttacks();
    for (int i = 0; i < 4; i++){
        attacks[i] = attackVectorTemp.at(i);
    }
    if (myTourneyLvl == 1){
        tempHealthNum = rand() % 20 + 30;
    }
    else if (myTourneyLvl == 2){
        tempHealthNum = rand() % 50 + 25;
    }
    else if (myTourneyLvl == 3){
        tempHealthNum = rand() % 25 + 75;
    }
    else{
        tempHealthNum = rand() % 101;
    }
    healthNum = tempHealthNum;
    if (typeNum == 0){
        type = "grass";
        name = grassNames[nameNum];
    }
    else if (typeNum == 1){
        type = "water";
        name = waterNames[nameNum];
    }
    else if (typeNum == 2){
        type = "fire";
        name = fireNames[nameNum];
    }
    creature x(name,type,healthNum,attacks);
    return x;
}


