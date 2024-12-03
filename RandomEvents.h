#include <string>
using namespace std;

#ifndef RandomEvents_H
#define RandomEvents_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 * 
 * This class focuses on parsing and storing the events read in from random_events.txt
 * 
 * Each event is formated like the following in random_events.txt:
 * Description | PathType (0 = cubTraining; 1 = straight to the pride lands) | Advisor (0 = none; 1 = Rafiki (invisibility); 2 = Nala (night vision); 3 = Sarabi (energy manipulation); 4 = Zazu (weather control); 5 = Sarafina (super speed)) | PridePoints (lose or gain)
 */

class RandomEvents
{
    public:
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
        RandomEvents();
        void printLists(int i);
        negativeEvent getNegativeEvent(int randomNumberIndex, string path);
        positiveEvent getPositiveEvent(int randomNumberIndex, string path);
    private:
        negativeEvent negativeEvents[20];
        positiveEvent positiveEvents[30];
        string temp[4];
        static const int tempSize = 4;
        int split(string original, char delimiter, string splitParts[], const int splitPartsSize);
};

#endif