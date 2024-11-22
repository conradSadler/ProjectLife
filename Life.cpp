#include "Life.h"

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
void Life:: printStats()
{
    printf("%s, age %d\nStrength: %d\nStamina: %d\nWisdom: %d\nPride Points: %d\n",pName.c_str(),pAge,pStrength,pStamina,pWisdom,pPridePoints);
}

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
        else if (!isspace(original[i]))
        {
            edditedOriginal += original[i];
        }
    }
    if(edditedOriginal.length() > 0 && count < splitPartsSize)
    {
        splitParts[count] = edditedOriginal;
    }

    if(count == 0)
    {
        return 0;
    }
    return 1;

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
        string attributes[5];
        const int attributesSize = 5;
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
                split(hold.substr(EndOfNameIndex),'|',attributes,attributesSize);
                pAge = stoi(attributes[0]);
                pStrength = stoi(attributes[1]);
                pStamina = stoi(attributes[2]);
                pWisdom = stoi(attributes[3]);
                pPridePoints = stoi(attributes[4]);
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
string Life::getAdvisor()
{
    return advisor;
}
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
        while(getline(cin,fileInput))
        {
            cout << fileInput << endl;
        }
        inputFile.close();
        bool validInput = false;
        string userInput;
        while(!validInput)
        {
            cout<< "Please enter an option from the list (1->5) or 0 to exit: ";
            getline(cin,userInput);
            userInput.erase(remove_if(userInput.begin(),userInput.end(),::isspace),userInput.end());
            switch(userInput[0])
            {
                case '0':
                    validInput = true;
                    break;
                case '1':
                    advisor = "Rafiki";
                    validInput = true;
                    break;
                case '2':
                    advisor = "Nala";
                    validInput = true;
                    break;
                case '3':
                    advisor = "Sarabi";
                    validInput = true;
                    break;
                case '4':
                    advisor = "Zazu";
                    validInput = true;
                    break;
                case '5':
                    advisor = "Sarafina";
                    validInput = true;
                    break;
                default:
                    cout<< "Invalid user input please try again." << endl;
            }
        }
    }
}