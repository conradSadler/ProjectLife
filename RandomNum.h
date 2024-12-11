#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

#ifndef RandomNum_H
#define RandomNum_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

class RandomNum
{
    private:
        const static bool var1 = true;
        const static bool var2 = true;
        const static bool var3 = true;
        const static bool var4 = true;

    public:
        inline RandomNum()
        {
            srand(time(NULL));
        }
        inline int getRandNum()
        {
            return rand();
        }
};

#endif