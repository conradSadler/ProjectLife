#include "Board.h"

#ifndef Game_H
#define Game_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

class Game
{
    private:
        string winner;
        int parseUserInputInteger() const;
        char parseUserInput() const;
        int pointConversionHelper(string question) const;
        int calculateWinner();
        Life CubTrainingPlayer(Life player);
        Life PrideLandsPlayer(Life player);
    public:
        Game();
        bool play();
        void setWinner(string);
        string getWinner();
        void outputRandomPositiveEvents();
        int playerMenu();
        Life pointConversion(Life player,int caseOfConversion);
        Life menuDecision(int decision, Life player, const Board playingBoard, const int playerIndex);
        

};

#endif