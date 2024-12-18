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
/**
 * This function extends tileImpact and is only used by tileImpact to deal with player 
 * attribute deductions and additions becasue of tiles like oasis, Graveyard, Hyenas, and challenge Tiles.
 * @param tileImp is a tile object attribute that describes how the tile the player is on will impact the player
 */
void Life::tileImpactExtended(string tileImp)
{
    int indexOf = tileImp.find('|');
        /**
         * this substring 'parts' contains information about what attributes are supposed
         * to be added to and what attributes are suposed to be deducted from
         */
    string parts = tileImp.substr(0,indexOf);
    tileImp = tileImp.substr(indexOf+1);
        /**
         * This substring 'tileImp' contains information about how many points should be deducted or added
         */
    for(int i = 0; i < parts.length();i++)
    {
        switch(parts[i])  //parsing through parts
        {
            case '1':
                i++;
                if(parts[i] == '+')
                {
                    setStamina(pStamina+=stoi(tileImp));
                }
                else
                {
                    setStamina(pStamina-=stoi(tileImp));
                }
                break;
            case '2':
                i++;
                if(parts[i] == '+')
                {
                    setStrength(pStrength+=stoi(tileImp));
                }
                else
                {
                    setStrength(pStrength-=stoi(tileImp));
                }
                break;
            case '3':
                i++;
                if(parts[i] == '+')
                {
                    setWisdom(pWisdom+=stoi(tileImp));
                }
                else
                {
                    setWisdom(pWisdom-=stoi(tileImp));
                }
                break;
            default:
                cout << "Invalid tile impact" << endl;
        }
    }
}

//end of private functions

//constructors

Life:: Life()
{
    advisor = "";
    string attributes[5];
    advisorNumber = -1;
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
    advisorNumber = -1;
    advisor = "";
    string attributes[5];    
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

double Life:: getPridePoints()
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
    printf("%s, age %d\nStrength: %d\nStamina: %d\nWisdom: %d\nPride Points: %f\n",pName.c_str(),pAge,pStrength,pStamina,pWisdom,pPridePoints);
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

void Life:: setPridePoints(double pride_points)
{
    pPridePoints = pride_points;
}

void Life:: setAge(int age)
{
    pAge = age;
}
/**
 * This function sets the player with the appropriate stats if the player chooses the go to cub training
 */
void Life:: trainCub(int strength,int stamina, int wisdom)
{
    pStrength+=strength;
    pStamina+=stamina;
    pWisdom+=wisdom;
    pPridePoints-=5000;
}
/**
 * This function sets the player with the appropriate stats if the player chooses the go to the pride lands
 */
void Life:: toPrideLands()
{
    pStrength+=2000;
    pStamina+=1000;
    pWisdom+=2000;
    pPridePoints+=5000;
}

/**
 * Description: This function prints the contents of advisors.txt and lets the user decide what advisor they want to have.
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
        while(getline(inputFile,fileInput))  //outputing the contents of advisors.txt
        {
            cout << fileInput << endl;
        }
        inputFile.close();
        bool validInput = false;
        string userInput;
        while(!validInput)  //while the user has not entered valid input, continue assking for input
        {
            cout<< "Please enter an option from the list (1->5) or 0 to exit:" << endl;
            if(advisor != "")
            {
                cout << "\n--- You can not enter " << advisorNumber << " becasue " << advisor.substr(0,advisor.find('|')) <<"is your current advisor ---" << endl;
            }
            getline(cin,userInput);
            userInput.erase(remove_if(userInput.begin(),userInput.end(),::isspace),userInput.end());  //removing all white space from the string
            if(userInput.length() > 1)
            {
                cout<< "Invalid user input please try again.\n" << endl;
            }
            else if(userInput[0] == to_string(advisorNumber)[0])  //comparing integer that is a character to integer that is a character
            {
                cout<< "Invalid user input please try again.\n" << endl;
            }
            else
            {
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
                        cout<< "Invalid user input please try again.\n" << endl;
                }
            }
        }
    }
}

bool Life:: setCharacter(string name)
{
    fstream inputFile("characters.txt");
    if(inputFile.fail())
    {
        cout << "File Failed To Open" << endl;
        return false;
    }
    else
    {
        string hold;
        string characterChoiceName;
        int EndOfNameIndex;
        bool characterMade = false;
        getline(inputFile, hold);
        while(getline(inputFile, hold) && !characterMade)
        {

            EndOfNameIndex = hold.find('|');
            characterChoiceName = hold.substr(0,EndOfNameIndex);
            characterChoiceName.erase(remove_if(characterChoiceName.begin(), characterChoiceName.end(), ::isspace),characterChoiceName.end());
            
            if(characterChoiceName == name)
            {
                pName = name;
                split(hold.substr(EndOfNameIndex),'|',attributes,attributesSize); //splitting the part after the advisors name from the line read from advisors.txt 
                pAge = stoi(attributes[0]); //converting string to int
                pStrength = stoi(attributes[1]); //converting string to int
                pStamina = stoi(attributes[2]); //converting string to int
                pWisdom = stoi(attributes[3]); //converting string to int
                pPridePoints = stoi(attributes[4]); //converting string to int
                characterMade = true;
            }

        }
        if(characterMade == false)
        {
            cout << "Character was not made becasue user entered invalid input" << endl;
            return false;
        }
    }
    inputFile.close();
    return true;
}
/**
 * This function handles all impacts to the player's data members from special tiles.
 * if the player lands on a riddle tile, this function reads riddle from riddle.txt and gets user input to check if the user answered the riddle correctly
 * This function also  handles point player attribute deductions and additions becasue of tiles like oasis, Graveyard,Hyenas, and challenge Tiles.
 * @param tileImp is a tile object attribute that describes how the tile the player is on will impact the player
 */
void Life::tileImpact(string tileImp)
{
    // 1 = stamina ; 2 = strength ; 3 = wisdom
    if(tileImp == "riddle")
    {
        ifstream inputFile("riddles.txt");
        if(inputFile.fail())
        {
            cout << "Could not open riddles.txt" << endl;
            return;
        }
        else
        {
            int riddleLine = (randomNumObject.getRandNum() % 28) -1;
            string fileLine;
            getline(inputFile,fileLine);
            for(int i = 0; i < riddleLine; i++)
            {
                getline(inputFile,fileLine);
            }
            getline(inputFile,fileLine);
            cout << "Here is the riddle:" << endl;
            int indexOfSplit = fileLine.find('|');
            cout << fileLine.substr(0,indexOfSplit) << endl;
            string answer = fileLine.substr(indexOfSplit+1);
            answer.erase(remove_if(answer.begin(),answer.end(),::isspace),answer.end());  //removing all white space from the string
            cout << "Please enter an answer below:" << endl;
            cin >> fileLine;
            if(fileLine == answer)
            {
                cout << "\nCongratulations You Answered The Question Correctly\n" << endl;
                pWisdom+=500;
            }
            else
            {
                cout << "\nIncorrect Answer!\n" << endl;
            }
            
        }
        inputFile.close();
    }
    else if(tileImp != "")  //if it is not a grasslands tile
    {
        tileImpactExtended(tileImp);
    }
}
// end of setters