/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

#include "Board.h"
#ifndef Game_H
#define Game_H

class Game
{
    private:
        string winner;
    public:
        Game();
        bool play();
        void setWinner(string);
        string getWinner();

};

#endif