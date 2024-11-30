# include "Game.h"

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

Game::Game()
{
    winner = "";
}

void Game::setWinner(string player)
{
    winner = player;
}
        
string Game::getWinner()
{
    return winner;
}
void Game::outputRandomPositiveEvents()
{
    Board playingBoard = Board(2);
    playingBoard.testForRandomEvent(0);
}
int parseUserInputInteger()
{
    string userInput;
    getline(cin,userInput); //getting input from the user
    if(tolower(userInput[0]) == 'e') //if the user entered 'E' or 'e' then exit and return
    {
        return -1;
    }
    userInput.erase(remove_if(userInput.begin(),userInput.end(),::isspace),userInput.end());  //erasing all ' ','\f','\n','\r','\t','\v' from input
    for(int i = 0; i < userInput.length(); i++)
    {
        if(!isdigit(userInput[i]))
        {
            return -1;
        }
    }
    if(userInput.length() == 0)
    {
        return -1;
    }
    else
    {
        return stoi(userInput);
    }
}

char parseUserInput()
{
    string userInput;
    getline(cin,userInput); //getting input from the user
    if(tolower(userInput[0]) == 'e') //if the user entered 'E' or 'e' then exit and return
    {
        return 'e';
    }
    userInput.erase(remove_if(userInput.begin(),userInput.end(),::isspace),userInput.end());  //erasing all ' ','\f','\n','\r','\t','\v' from input
    if(isdigit(userInput[0]))
    {
        return userInput[0];
    }
    else
    {
        return '-';
    }
}
/**
 * Description: This function displays the user menu and gets the users input, which is between 1 and 5.
 * @return the integer that the user entered, unless the user entered 'E' or 'e' which will return -1(unsuccessful)
 */
int playerMenu()
{
    bool validInput = false;
    int userInput = 0;
    while(!validInput)
    {
        //system("clear");
        cout << "  --- Player Menu ---  |Options|" << endl;
        cout << "Check Player Progress: |   1   |" << endl;
        cout << "Review Character:      |   2   |" << endl;
        cout << "Check Position:        |   3   |" << endl;
        cout << "Review your Advisor:   |   4   |" << endl;
        cout << "Move Forward:          |   5   |" << endl;
        cout << "\nEnter Valid Option: " << endl;
        
        userInput = parseUserInputInteger();
        if(userInput == -1) //if the user entered 'E' or 'e' then exit and return
        {
            return -1;
        }

        if(userInput > 0 && userInput < 6)
        {
            return userInput;
        }
        else
        {
            cout << "Invalid user input. Please try again. Press 'E' to exit game" << endl;

            __libcpp_thread_sleep_for(chrono::seconds(2));  //pausing thread for 2 seconds before giving the user another opertunity to enter a choice
        }
    }
    return -1;
}
Life pointConversion(Life player,int caseOfConversion)
{
    int numberOfPoints = -1;
    switch(caseOfConversion)
    {
        case 1:
            while(numberOfPoints == -1)
            {
                cout << "how many strength points do you want to convert" << endl;
                cout << "\nEnter Valid Option or enter 'e' to exit: " << endl;
                numberOfPoints = parseUserInputInteger();
                if(numberOfPoints == -1)
                {
                    numberOfPoints = 0;
                }
            }
            if(numberOfPoints == 0)
            {
                cout << "No points Converted" << endl;
                break;
            }
            numberOfPoints = player.getStrength() - numberOfPoints;
            if(numberOfPoints < 100)
            {
                numberOfPoints = player.getStrength() - 100;
                cout << "Can not convert that many points, 100 point minimum point balance required for strength" << endl;
                cout << "Converting "<< numberOfPoints << " stength points to Pride Points" << endl;
                player.setStrength(100);
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));  // multiplying by a factor of 1000
            }
            else
            {
                player.setStrength(player.getStrength() - numberOfPoints);
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));
            }
            break;
        case 2:
            while(numberOfPoints == -1)
            {
                cout << "how many stamina points do you want to convert" << endl;
                cout << "\nEnter Valid Option or enter 'e' to exit: " << endl;
                numberOfPoints = parseUserInputInteger();
                if(numberOfPoints == -1)
                {
                    numberOfPoints = 0;
                }
            }
            if(numberOfPoints == 0)
            {
                cout << "No points Converted" << endl;
                break;
            }
            numberOfPoints = player.getStamina() - numberOfPoints;

            if(numberOfPoints < 100)
            {
                numberOfPoints = player.getStamina() - 100;
                cout << "Can not convert that many points, 100 point minimum point balance required for stamina" << endl;
                cout << "Converting "<< numberOfPoints << " stength points to Pride Points" << endl;
                player.setStamina(100);
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));  // multiplying by a factor of 1000
            }
            else
            {
                player.setStamina(player.getStamina() - numberOfPoints);
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));
            }
            break;
        case 3:
            while(numberOfPoints == -1)
            {
                cout << "how many wisdom points do you want to convert" << endl;
                cout << "\nEnter Valid Option or enter 'e' to exit: " << endl;
                if(numberOfPoints == -1)
                {
                    numberOfPoints = 0;
                }
            }
            if(numberOfPoints == 0)
            {
                cout << "No points Converted" << endl;
                break;
            }
            numberOfPoints = player.getWisdom() - numberOfPoints;
            if(numberOfPoints < 100)
            {
                numberOfPoints = player.getWisdom() - 100;
                cout << "Can not convert that many points, 100 point minimum point balance required for wisdom" << endl;
                cout << "Converting "<< numberOfPoints << " stength points to Pride Points" << endl;
                player.setWisdom(100);
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));  // multiplying by a factor of 1000
            }
            else
            {
                player.setWisdom(player.getWisdom() - numberOfPoints);
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));
            }
            break;
        default:
            cout << "Unsucessful termination in Menu Decision" << endl;
    }
    return player;
}

Life menuDecision(int decision, Life player, const Board playingBoard, const int playerIndex)
{
    char userInput;
    switch(decision)
    {
        case 1:
            cout << "  --- Sub-Menu ---                         |Options|" << endl;
            cout << "Convert Leadership traits to pride points: |   1   |" << endl;
            cout << "percentage of path covered:                |   2   |" << endl;
            cout << "\nEnter Valid Option: " << endl;
            userInput = parseUserInput();
            switch(userInput)
            {
                case '1':
                    player.printStats();
                    cout << "What Leadership trait do you want to convert to Pride Points?" << endl;
                    cout << "  --- Sub-Menu for point conversion---     |Options|" << endl;
                    cout << "Strength:                                  |   1   |" << endl;
                    cout << "Stamina:                                   |   2   |" << endl;
                    cout << "Wisdom:                                    |   3   |" << endl;
                    cout << "\nEnter Valid Option: " << endl;
                    userInput = parseUserInput();
                    switch(userInput)
                    {
                        case '1':
                            player = pointConversion(player,1);
                            break;
                        case '2':
                             player = pointConversion(player,2);
                             break;
                        case '3':
                            player = pointConversion(player,3);
                            break;
                        default:
                            cout << "Unsucessful termination in Menu Decision" << endl;
                    }
                    break;
                case '2':
                    cout << "You have covered " << float(playingBoard.getPlayerPosition(playerIndex))/51 << " of the playing board" << endl;
                    break;
                default:
                    cout << "Unsucessful termination in Menu Decision" << endl;

            }
            break;

        case 2:
            player.printStats();
            break;
        case 3:
            cout << "You are " << 51-playingBoard.getPlayerPosition(playerIndex) << " tile/s from the pride lands" << endl;
            break;
        case 4:
            cout << "Here is your advisor:" << endl;
            cout << player.getAdvisor() << endl;
            break;
        case 5:
            break;
        default:
            cout << "Error in menu decision" << endl;
    }
    return player;
}
/**
 * This function plays the game. This function is not complete and needs to be borken up becasue it is too long.
 */
bool Game::play()
{
    string userInput;
    int numPlayers;
    cout << "Enter The Number of Players:" << endl;
    getline(cin,userInput);
    userInput.erase(remove_if(userInput.begin(), userInput.end(), ::isspace),userInput.end());
    try //if stoi fails becasue the user inou was invalid the program will not crash
    {
        numPlayers = stoi(userInput);
    }
    catch(exception e)
    {
        printf("Invalid user input. Default set to two players\n");
        numPlayers = 2;
    }
    Board playingBoard = Board(numPlayers);  // initializing Board
    
    for(int i = 0; i < numPlayers; i++)
    {
        if(playingBoard.chooseCharacter() == false)
        {
            return false;
        }

        printf("Does Player %d Wish To Go To:\nA: Cub Training\nB: Straight to the Pride Lands\nEnter 'A' for choice A or 'B' for choice B\n", i);
        bool validInput = false;
            //This loop will continue unit the user makes a decision on what path to take
        while(validInput == false && getline(cin,userInput))
        {
            if(tolower(userInput[0]) == 'a')
            {
                validInput = true;
                playingBoard.setTrack(0,i);
                Life CubTrainingPlayer = playingBoard.getPlayer(i);
                CubTrainingPlayer.setPridePoints(CubTrainingPlayer.getPridePoints() - 5000);
                CubTrainingPlayer.setStamina(CubTrainingPlayer.getStamina() + 500);
                CubTrainingPlayer.setStrength(CubTrainingPlayer.getStrength() + 500);
                CubTrainingPlayer.setWisdom(CubTrainingPlayer.getWisdom() + 1000);
                CubTrainingPlayer.setAdvisor();
                playingBoard.setPlayer(CubTrainingPlayer,i);
                /**
                 * The training requires an investment of -5,000 Pride Points from the starting
                    number of Pride Points; this symbolizes the time and resources dedicated to developing these skills instead
                    of gaining Pride Points. This path also adds 500 Stamina Points, 500 Strength Points, and 1,000 Wisdom
                    Points to the starting amount of your character’s Leadership Traits before you start the journey
                 */
            }
            else if(tolower(userInput[0]) == 'b')
            {
                validInput = true;
                playingBoard.setTrack(1,i);
                Life PrideLandsPlayer = playingBoard.getPlayer(i);
                PrideLandsPlayer.setPridePoints(PrideLandsPlayer.getPridePoints() + 5000);
                PrideLandsPlayer.setStamina(PrideLandsPlayer.getStamina() + 200);
                PrideLandsPlayer.setStrength(PrideLandsPlayer.getStrength() + 200);
                PrideLandsPlayer.setWisdom(PrideLandsPlayer.getWisdom() + 200);
                playingBoard.setPlayer(PrideLandsPlayer,i);
                /**
                 * +5,000 Pride Points from the starting number of Pride Points, allowing early progression and quick success
                    in achieving intermediate goals. This path adds 200 Stamina Points, 200 Strength Points, and 200 Wisdom
                    Points to the starting amount of your character’s Leadership Traits before you start the journey
                 */
            }
            else
            {
                printf("Invalid User Input. Please try again.\n");
                printf("Does Player %d Wish To Go To:\nA: Cub Training\nB: Straight to the Pride Lands\nEnter 'A' for choice A or 'B' for choice B\n", i);
            }

        }

    }
    int decidingFirstPlayer = playingBoard.spin()%4;
    int playerTurn = 0;
        //using random numbers to see what player will start the game
    if(decidingFirstPlayer == 0)
    {
        decidingFirstPlayer = 4;
    }
    if(decidingFirstPlayer%2 == 0)
    {
        cout << "\n*** Player 1 Starts The Game ***\n" << endl;
    }
    else
    {
        cout << "\n*** Player 2 Starts The Game ***\n" << endl;
        playerTurn = 1;
    }
        // end of using random numbers to see what player will start the game
     
    int playerDesicion = 0;
        //game playing loop
    playingBoard.displayBoard();
    __libcpp_thread_sleep_for(chrono::seconds(2)); //This pauses the current thread for 2 seconds

    while(playingBoard.getPlayerPosition(0) != 51 || playingBoard.getPlayerPosition(0) != 51)
    {
        if(playingBoard.getPlayerPosition(0) == 51)  // if player one has reached the "finish line", then only let player two move
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                cout << "  --- Player 2's turn ---  " << endl;
                playerDesicion = playerMenu();
                if(playerDesicion != -1)
                {
                    playingBoard.setPlayer(menuDecision(playerDesicion, playingBoard.getPlayer(1), playingBoard, 1),1);
                }
                else
                {
                    playerDesicion = 5;
                }
                //create menu function to handle menu (1->4)
            }
            playingBoard.movePlayer(playerTurn);
            playerTurn = 1;
        }
        else if(playingBoard.getPlayerPosition(1) == 51)  // if player two has reached the "finish line", then only let player one move
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                cout << "  --- Player 1's turn ---  " << endl;
                playerDesicion = playerMenu();
                if(playerDesicion != -1)
                {
                    playingBoard.setPlayer(menuDecision(playerDesicion, playingBoard.getPlayer(0), playingBoard, 0),0);
                }
                else
                {
                    playerDesicion = 5;
                }
                //create menu function to handle menu (1->4)
            }
            playingBoard.movePlayer(playerTurn);
            playerTurn = 0;
        }
        else //if both players have not reached the finish line, then alternate turns
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                cout << "Player "<< playerTurn+1 <<"'s turn" << endl;
                playerDesicion = playerMenu();
                if(playerDesicion != -1)
                {
                    playingBoard.setPlayer(menuDecision(playerDesicion, playingBoard.getPlayer(playerTurn), playingBoard, playerTurn),playerTurn);
                }
                else
                {
                    playerDesicion = 5;
                }
                //create menu function to handle menu (1->4)
            }
            if(playingBoard.movePlayer(playerTurn) != 1)
            {
                playerTurn = ((playerTurn +1) % 2);
            }
        }
    }
    return true;
}