#include <string>
using namespace std;

#ifndef RandomEvents_H
#define RandomEvents_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 * Description | PathType (0 = cubTraining; 1 = straight to the pride lands) | Advisor (0 = none; 1 = Rafiki (invisibility); 2 = Nala (night vision); 3 = Sarabi (energy manipulation); 4 = Zazu (weather control); 5 = Sarafina (super speed)) | PridePoints (lose or gain)
 */

class RandomEvents
{
    private:
        struct positiveEvent
        {
            string eventName;
            string path;
            string pridePoints;
        };
        struct negativeEvent
        {
            string eventName;
            string path;
            string advisor;
            string pridePoints;
        };
        negativeEvent negativeEvents[20];
        positiveEvent positiveEvents[30];
        string temp[4];
        static const int tempSize = 4;
    public:
        RandomEvents();
        void printLists(int i);
        negativeEvent getNegativeEvent(int randomNumberIndex, string path);
        positiveEvent getPositiveEvent(int randomNumberIndex, string path);
        int split(string original, char delimiter, string splitParts[], const int splitPartsSize);


};

#endif