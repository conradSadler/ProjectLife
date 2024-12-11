#include <string>
using namespace std;

#ifndef Tile_H
#define Tile_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

class Tile
{
    public:
        string type;
        char color;
        string impact;
        const static bool used = true;

        inline Tile()
        {
            type = "";
            color= '-';
            impact = "";
        }
};

#endif