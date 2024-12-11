#include <string>
#include <fstream>
#include <iostream>
#include "PlayerMetaData.h"
#include "RandomNum.h"
using namespace std;

#ifndef LIFE_H
#define LIFE_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 * 
 * This class focuses on storing all attributes relevent to a player in the game
 */

class Life:private PlayerMetaData //is-implemented-in-terms-of relationship
{
    private:
        string pName;
        string advisor;
        string attributes[5];
        const static int attributesSize = 5;
        double pPridePoints;
        int pStrength,pStamina,pWisdom,pAge,advisorNumber;
        int split(string original, char delimiter, string splitParts[], const int splitPartsSize);
        RandomNum randomNumObject;
        void setAdvisorNumber(int x) {advisorNumber = x;}  //set to private becasue set Advisor number should not be changed outside of setAdvisor()
        void tileImpactExtended(string tileImp);

    public:
        Life();
        Life(string,int,int,int);
        string getName();
        string getAdvisor();
        int getStrength();
        int getStamina();
        int getWisdom();
        double getPridePoints();
        int getAge();
        int getAdvisorNumber();
        void tileImpact(string);
        void setName(string name); 
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom); 
        void setPridePoints(double pride_points); 
        void setAge(int age);
        void setAdvisor();
        void trainCub(int strength,int stamina, int wisdom);
        void toPrideLands();
        void printStats();
        bool displayCharacters();
        bool setCharacter(string);
        inline void push(int i)
        {
            PlayerMetaData::push(i);
        }
        inline int pop()
        {
            return PlayerMetaData::pop();
        }
};

#endif