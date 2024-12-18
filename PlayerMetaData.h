#include <vector>

#ifndef PlayerMetaData_H
#define PlayerMetaData_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 * 
 * This class records the player's positions on the board.
 */

class PlayerMetaData
{
    private:
        std::vector<int> pastPositions;
            //setting and getting vector should not be allowed
        std::vector<int> getVector();
        void setVector(std::vector<int>);

    public:

        PlayerMetaData(){std::vector<int> pastPositions;}
        virtual inline void push(int i)
        {
            pastPositions.push_back(i);
        }
        virtual inline int pop()
        {
            if(pastPositions.size() == 0)
            {
                return 0;
            }
            int back = pastPositions.back();
            pastPositions.pop_back();
            return back;
        }
};

#endif