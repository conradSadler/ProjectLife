#include <string>
#include <fstream>
#include <iostream>
#include "PlayerMetaData.h"
using namespace std;

#ifndef LIFE_H
#define LIFE_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

class Life:public PlayerMetaData
{
    private:
        string pName;
        string advisor;
        int pStrength,pStamina,pWisdom,pPridePoints,pAge,advisorNumber;
        int split(string original, char delimiter, string splitParts[], const int splitPartsSize);
        void setAdvisorNumber();

    public:
        Life();
        Life(string,int,int,int);
        string getName();
        string getAdvisor();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        int getAge();
        int getAdvisorNumber();
        void tileImpact(string);
        void setName(string name); 
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom); 
        void setPridePoints(int pride_points); 
        void setAge(int age);
        void setAdvisor();
        void trainCub(int strength,int stamina, int wisdom);
        void toPrideLands();
        void printStats();
        bool displayCharacters();
        bool setCharacter(string);
};

#endif