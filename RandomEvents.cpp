# include "RandomEvents.h"
# include <fstream>
# include <iostream>

/**
 * Description: This function is a private member function that is only used by the constructor for splitting up all of a characters traits into a array of strings
 * @param original is the originial string that will be split up
 * @param delimiter is the character that determines when the string is split
 * @param splitParts[] is the array of strings where the split up parts of original will be added
 * @param splitPartsSize is the length of splitParts[]
 * @return returns the amount of splits that happend
 */
int RandomEvents:: split(string original, char delimiter, string splitParts[], const int splitPartsSize)
{    
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
/**
 * This constructor populates two arrays of structs, one for positive events and one for negative events
 */
RandomEvents::RandomEvents()
{
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
            if((fileInfo[0] == '/' && fileInfo[1] == '/'))  // look at file. '//' is the start of the line before the events start
            {
                determineSeg++;
                getline(inputFile,fileInfo);
            }
            if(determineSeg == 1 && firstRecorded == false)  //record negative events
            {
                for(int i = 0; i < 20; i++)
                {
                    getline(inputFile,fileInfo);
                    split(fileInfo,'|',temp,tempSize);
                    negativeEvents[i].eventName = temp[0];
                    negativeEvents[i].path = temp[1];
                    negativeEvents[i].advisor = temp[2];
                    negativeEvents[i].pridePoints = temp[3];
                }
                firstRecorded = true;
            }
            else if(determineSeg == 2 && secondRecorded == false)  //record positive events
            {
                for(int i = 0; i < 30; i++)
                {
                    getline(inputFile,fileInfo);
                    split(fileInfo,'|',temp,tempSize);
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

void RandomEvents::printLists(int i)  //tester function
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
/**
 * This function returns a positive event struct from the struct array with matching path as the path argument
 * @param randomNumberIndex is a random number between [0,30]
 * @param path represents the path the character is on. Events are path dependent
 */
RandomEvents::positiveEvent RandomEvents::getPositiveEvent(int randomNumberIndex, string path)
{
    if( (randomNumberIndex > -1 && randomNumberIndex < 30) && (path == "1" || path == "0") )
    {
        while(true) //keeps iterating until a event is returned from function
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
/**
 * This function returns a positive event struct from the struct array with matching path as the path argument
 * @param randomNumberIndex is a random number between [0,20]
 * @param path represents the path the character is on. Events are path dependent
 */
RandomEvents::negativeEvent RandomEvents::getNegativeEvent(int randomNumberIndex, string path)
{
    if( (randomNumberIndex > -1 && randomNumberIndex < 20) && (path == "1" || path == "0") )
    {
        while(true) //keeps iterating until a event is returned from function
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