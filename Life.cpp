#include "Life.h"

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

//private functions
/**
 * Description: This function is a private member function that is only used by set character for splitting up all of a characters traits into a array of strings
 * @param original is the originial string that will be split up
 * @param delimiter is the character that determines when the string is split
 * @param splitParts[] is the array of strings where the split up parts of original will be added
 * @param splitPartsSize is the length of splitParts[]
 * @return returns the amount of splits that happend
 */
int Life:: split(string original, char delimiter, string splitParts[], const int splitPartsSize)
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
        else if (!isspace(original[i])) //if the character is not a ' ','\f','\n','\r','\t','\v' then add it to the string
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

//end of private functions

//constructors

Life:: Life()
{
    pName = "";
    pStrength = 100;
    pStamina = 100;
    pWisdom = 100;
    pPridePoints = 0;
    pAge = 1;
}
        
Life::Life(string newName,int newStrength,int newStamina,int newWisdom)
{
    pName = newName;
    if(newStrength >= 100 && newStrength <= 1000)
    {
        pStrength = newStrength;
    }
    else
    {
        pStrength = 100;
    }
    if(newStamina >= 100 && newStamina <= 1000)
    {
        pStamina = newStamina;
    }
    else
    {
        pStamina = 100;
    }
    if(newWisdom >= 100 && newWisdom <= 1000)
    {
        pWisdom = newWisdom;
    }
    else
    {
        pWisdom = 100;
    }
    pPridePoints = 0;
    pAge = 1;
}
// end of constructors

//getters
string Life:: getName()
{
    return pName;
}
int Life:: getStrength()
{
    return pStrength;
}
int Life:: getStamina()
{
    return pStamina;
}
int Life:: getWisdom()
{
    return pWisdom;
}
int Life:: getPridePoints()
{
    return pPridePoints;
}
int Life:: getAge()
{
    return pAge;
}
/**
 * Description: This function prints out all of the players information
 */
void Life:: printStats()
{
    printf("%s, age %d\nStrength: %d\nStamina: %d\nWisdom: %d\nPride Points: %d\n",pName.c_str(),pAge,pStrength,pStamina,pWisdom,pPridePoints);
}
/**
 * Description: This function reads characters.txt and prints it the the output stream for the user to see
 */
bool Life:: displayCharacters()
{
    ifstream inputFile("characters.txt");
    if(inputFile.fail())
    {
        cout << "File Failed To Open" << endl;
        return false;
    }
    else
    {
        string hold;
        while(getline(inputFile, hold))
        {
            printf("%s\n",hold.c_str());
        }
    }
    inputFile.close();
    return true;
}
string Life::getAdvisor()
{
    return advisor;
}
int Life::getAdvisorNumber()
{
    return advisorNumber;
}
// end of getters

//setters

void Life:: setName(string name)
{
    pName = name;
}
void Life:: setStrength(int strength)
{
    if(strength < 100)
    {
        pStrength = 100;
    }
    else
    {
        pStrength = strength;
    }
}
void Life:: setStamina(int stamina)
{
    if(stamina <100)
    {
        pStamina = 100;
    }
    else
    {
        pStamina = stamina;
    }
}
void Life:: setWisdom(int wisdom)
{
    if(wisdom < 100)
    {
        pWisdom = 100;
    }
    else
    {
        pWisdom = wisdom;
    }
}
void Life:: setPridePoints(int pride_points)
{
    pPridePoints = pride_points;
}
void Life:: setAge(int age)
{
    pAge = age;
}
void Life:: trainCub(int strength,int stamina, int wisdom)
{
    pStrength+=strength;
    pStamina+=stamina;
    pWisdom+=wisdom;
    pPridePoints-=5000;
}

void Life:: toPrideLands()
{
    pStrength+=2000;
    pStamina+=1000;
    pWisdom+=2000;
    pPridePoints+=5000;
}

/**
|Option|Advisors| Description                                                                    |
|   1  |Rafiki  | Invisibility (the ability to become un-seen)                                   |
|   2  |Nala    | Night Vision (the ability to see clearly in darkness)                          |
|   3  |Sarabi  | Energy Manipulation (the ability to shape and control the properties of energy)|
|   4  |Zazu    | Weather Control (the ability to influence and manipulate weather patterns)     |
|   5  |Sarafina| Super Speed (the ability to run 4x faster than the maximum speed of lions)     |
 * Description: This function prints the contents of advisors.txt and lets the user decide what advisor they want to have
 */
void Life::setAdvisor()
{
    string fileInput;
    ifstream inputFile("advisors.txt");
    if(inputFile.fail())
    {
        cout << "File failed to open" << endl;
    }
    else
    {
        while(getline(cin,fileInput))  //outputing the contents of advisors.txt
        {
            cout << fileInput << endl;
        }
        inputFile.close();

        bool validInput = false;
        string userInput;
        while(!validInput)  //while the user has not entered valid input, continue assking for input
        {
            cout<< "Please enter an option from the list (1->5) or 0 to exit: ";
            getline(cin,userInput);
            userInput.erase(remove_if(userInput.begin(),userInput.end(),::isspace),userInput.end());  //removing all white space from the string
            switch(userInput[0])
            {
                case '0':
                    validInput = true;
                    break;
                case '1':
                    advisor = "Rafiki | Invisibility (the ability to become un-seen)";
                    advisorNumber = 1;
                    validInput = true;
                    break;
                case '2':
                    advisor = "Nala | Night Vision (the ability to see clearly in darkness)";
                    advisorNumber = 2;
                    validInput = true;
                    break;
                case '3':
                    advisor = "Sarabi | Energy Manipulation (the ability to shape and control the properties of energy)";
                    advisorNumber = 3;
                    validInput = true;
                    break;
                case '4':
                    advisor = "Zazu | Weather Control (the ability to influence and manipulate weather patterns)";
                    advisorNumber = 4;
                    validInput = true;
                    break;
                case '5':
                    advisor = "Sarafina | Super Speed (the ability to run 4x faster than the maximum speed of lions)";
                    advisorNumber = 5;
                    validInput = true;
                    break;
                default:
                    cout<< "Invalid user input please try again." << endl;
            }
        }
    }
}
// end of setters