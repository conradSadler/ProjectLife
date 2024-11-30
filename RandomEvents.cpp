# include "RandomEvents.h"
# include <fstream>
# include <iostream>

using namespace std;

/**
 * Description: This function is a private member function that is only used by set character for splitting up all of a characters traits into a array of strings
 * @param original is the originial string that will be split up
 * @param delimiter is the character that determines when the string is split
 * @param splitParts[] is the array of strings where the split up parts of original will be added
 * @param splitPartsSize is the length of splitParts[]
 * @return returns the amount of splits that happend
 */
int RandomEvents:: split(string original, char delimiter, string splitParts[], const int splitPartsSize)
{
    //NOTE: NO PASS BY REFRENCE IN ENTIRE PROJECT!!!
    
    int count = 0;
    string edditedOriginal;

    for(int i = 0; i < original.length(); i++)
    {
        if(original[i] == delimiter && count < splitPartsSize)
        {
            if(edditedOriginal.length() > 0)
            {
                splitParts[count] = edditedOriginal;
                count++;
            }
            edditedOriginal = "";
        }
        else if (original[i] == ' ' || !isspace(original[i])) //if the character is not a ' ','\f','\n','\r','\t','\v' then add it to the string
        {
            edditedOriginal += original[i];
        }
    }
    if(edditedOriginal.length() > 0 && count < splitPartsSize) //if the string eddited original is not empty and it is safe to add it to splitParts array, then add it.
    {
        splitParts[count] = edditedOriginal;
    }

    if(count == 0)
    {
        return 0;
    }
    return 1;

}

RandomEvents::RandomEvents()
{
    cout << "IN constructor" << endl;
    ifstream inputFile("random_events.txt");
    if(inputFile.fail())
    {
        cout << "Problem opening random_events.txt" << endl;
        return;
    }
    else
    {
        string fileInfo;
        bool secondRecorded = false;
        bool firstRecorded = false;
        int determineSeg = 0;
        while(getline(inputFile,fileInfo))
        {
            if((fileInfo[0] == '/' && fileInfo[1] == '/'))
            {
                cout << "IN"<<"!!!!" << endl;
                determineSeg++;
                getline(inputFile,fileInfo);
            }
            if(determineSeg == 1 && firstRecorded == false)  //for negative events
            {
                for(int i = 0; i < 20; i++)
                {
                    getline(inputFile,fileInfo);
                    split(fileInfo,'|',temp,tempSize);
                    cout << temp[0]<<"|" << endl;
                    negativeEvents[i].eventName = temp[0];
                    negativeEvents[i].path = temp[1];
                    negativeEvents[i].advisor = temp[2];
                    negativeEvents[i].pridePoints = temp[3];
                }
                cout << "_____________________________________"<<"!!!!" << endl;
                firstRecorded = true;
            }
            else if(determineSeg == 2 && secondRecorded == false)
            {
                for(int i = 0; i < 30; i++)
                {
                    getline(inputFile,fileInfo);
                    split(fileInfo,'|',temp,tempSize);
                    cout << temp[0]<<"*" << endl;
                    positiveEvents[i].eventName = temp[0];
                    positiveEvents[i].path = temp[1];
                    positiveEvents[i].pridePoints = temp[3];
                }
                secondRecorded = true;
            }
        }
        inputFile.close();
    }
}

void RandomEvents::printLists(int i)
{
    if(i == 0)
    {
        for(int i = 0; i < 30; i++)
        {
            cout << RandomEvents::positiveEvents[i].eventName << endl;
        }
    }
    else
    {
        for(int i = 0; i < 20; i++)
        {
            cout << RandomEvents::negativeEvents[i].eventName << endl;
        }
    }
}

RandomEvents::positiveEvent RandomEvents::getPositiveEvent(int randomNumberIndex, string path)
{
    if( (randomNumberIndex > -1 && randomNumberIndex < 30) && (path == "1" || path == "0") )
    {
        while(true)
        {
            if(positiveEvents[randomNumberIndex%30].path == path)
            {
                return positiveEvents[randomNumberIndex];
            }
            randomNumberIndex++;
        }
    }
    else
    {
        cout << "Invalid index for getting random event index 0 returned" << endl;
        return positiveEvents[0];
    }
}

RandomEvents::negativeEvent RandomEvents::getNegativeEvent(int randomNumberIndex, string path)
{
    if( (randomNumberIndex > -1 && randomNumberIndex < 20) && (path == "1" || path == "0") )
    {
        while(true)
        {
            if(negativeEvents[randomNumberIndex%20].path == path)
            {
                return negativeEvents[randomNumberIndex];
            }
            randomNumberIndex++;
        }
    }
    else
    {
        cout << "Invalid index for getting random event index 0 returned" << endl;
        return negativeEvents[0];
    }
}