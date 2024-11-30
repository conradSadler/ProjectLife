# include "Game.h"

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 * 
 * This file implements all game play actions
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

/**
 * This is a private helper function that gets user input and parses it.
 * @return integer from user input
 */
int Game::parseUserInputInteger() const
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
/**
 * This is a private helper function that gets user input and parses it.
 * @return char from user input
 */
char Game::parseUserInput() const
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
int Game::playerMenu()
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
/**
 * This is a private helper function for pointConversion(Life,int). This function processes user input by calling parseUserInputInteger()
 * @param question a question to print to output stream
 */
int Game::pointConversionHelper(string question) const
{
    int numberOfPoints = -1;
    while(numberOfPoints == -1)
    {
        cout << question << endl;
        cout << "\nEnter Valid Option or enter 'e' to exit: " << endl;
        numberOfPoints = parseUserInputInteger();
        if(numberOfPoints == -1) //if user enters 'e' to stop loop, then exit loop by setting loop conditional to false
        {
            numberOfPoints = 0;
        }
    }
    return numberOfPoints;
}
/**
 * This function allows user to convert their player's strength, stamina, widsom into pridePoints
 * @param player a Life object(one of the player objects playing the game)
 * @param caseOfConversion the type of points the user wants to convert
 * @return the modified Life object(one of the players objects playing the game)
 */
Life Game::pointConversion(Life player,int caseOfConversion)
{
    int numberOfPoints = -1;
    switch(caseOfConversion)
    {
        case 1:
            numberOfPoints = pointConversionHelper("How many strength points do you want to convert?");
            if(numberOfPoints == 0)
            {
                cout << "No points Converted" << endl;
                break;
            }
            numberOfPoints = player.getStrength() - numberOfPoints;
            if(numberOfPoints < 100)  //protecting against over conversion
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
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));  // multiplying by a factor of 1000
            }
            break;
        case 2:
            numberOfPoints = pointConversionHelper("How many stamina points do you want to convert?");
            if(numberOfPoints == 0)
            {
                cout << "No points Converted" << endl;
                break;
            }
            numberOfPoints = player.getStamina() - numberOfPoints;

            if(numberOfPoints < 100)  //protecting against over conversion
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
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));  // multiplying by a factor of 1000
            }
            break;
        case 3:
            numberOfPoints = pointConversionHelper("How many wisdom points do you want to convert?");

            if(numberOfPoints == 0)
            {
                cout << "No points Converted" << endl;
                break;
            }
            numberOfPoints = player.getWisdom() - numberOfPoints;
            if(numberOfPoints < 100)  //protecting against over conversion
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
                player.setPridePoints(player.getPridePoints()+(numberOfPoints * 1000));  // multiplying by a factor of 1000
            }
            break;
        default:
            cout << "Unsucessful termination in Menu Decision" << endl;
    }
    return player;
}
/**
 * This function processes the users choice that they made by slecting from the menu options priodived by playerMenu()
 * @param desision the users decision
 * @param player a Life object(one of the player objects playing the game)
 * @param playingBoard used only to get data pertaining to player
 * @param playerIndex used to 
 * @return the modified Life object(one of the players objects playing the game)
 */
Life Game::menuDecision(int decision, Life player, const Board playingBoard, const int playerIndex)
{
    char userInput;
    switch(decision)
    {
        case 1:  //user choose option one
            cout << "  --- Sub-Menu ---                         |Options|" << endl;
            cout << "Convert Leadership traits to pride points: |   1   |" << endl;
            cout << "percentage of path covered:                |   2   |" << endl;
            cout << "\nEnter Valid Option: " << endl;
            userInput = parseUserInput();
            
            switch(userInput)  //for determining if user wants to know path covered or want to conver points
            {
                case '1':  // converting points
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
                case '2':  // path covered
                    cout << "You have covered " << float(playingBoard.getPlayerPosition(playerIndex))/51 << " of the playing board" << endl;
                    break;
                default:
                    cout << "Unsucessful termination in Menu Decision" << endl;

            }
            break;

        case 2:  //displays player statistics
            player.printStats();
            break;
        case 3:  //tells the user how many tiles their player is from pride lands
            cout << "You are " << 51-playingBoard.getPlayerPosition(playerIndex) << " tile/s from the pride lands" << endl;
            break;
        case 4:  //displays player's advisor
            cout << "Here is your advisor:" << endl;
            cout << player.getAdvisor() << endl;
            break;
        case 5:  //nothing here becasue player wants to move forward
            break;
        default:
            cout << "Error in menu decision" << endl;
    }
    return player;
}
Life Game::CubTrainingPlayer(Life player)
{
    player.setPridePoints(player.getPridePoints() - 5000);
    player.setStamina(player.getStamina() + 500);
    player.setStrength(player.getStrength() + 500);
    player.setWisdom(player.getWisdom() + 1000);
    player.setAdvisor();
    /**
     * The training requires an investment of -5,000 Pride Points from the starting
        number of Pride Points; this symbolizes the time and resources dedicated to developing these skills instead
        of gaining Pride Points. This path also adds 500 Stamina Points, 500 Strength Points, and 1,000 Wisdom
        Points to the starting amount of your character’s Leadership Traits before you start the journey
    */
    return player;
}
Life Game::PrideLandsPlayer(Life player)
{
    player.setPridePoints(player.getPridePoints() + 5000);
    player.setStamina(player.getStamina() + 200);
    player.setStrength(player.getStrength() + 200);
    player.setWisdom(player.getWisdom() + 200);
    /**
     * +5,000 Pride Points from the starting number of Pride Points, allowing early progression and quick success
        in achieving intermediate goals. This path adds 200 Stamina Points, 200 Strength Points, and 200 Wisdom
        Points to the starting amount of your character’s Leadership Traits before you start the journey
    */
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
    try //if stoi fails becasue the user input was invalid the program will not crash
    {
        numPlayers = stoi(userInput);
        if(numPlayers > 2)
        {
            numPlayers = 2;
        }
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

        printf("Does Player %d Wish To Go To:\nA: Cub Training\nB: Straight to the Pride Lands\nEnter 'A' for choice A or 'B' for choice B\n", i+1);
        bool validInput = false;
            //This loop will continue unit the user makes a decision on what path to take
        while(validInput == false && getline(cin,userInput))
        {
            if(tolower(userInput[0]) == 'a')
            {
                validInput = true;
                playingBoard.setTrack(0,i);
                playingBoard.setPlayer(CubTrainingPlayer(playingBoard.getPlayer(i)),i);
            }
            else if(tolower(userInput[0]) == 'b')
            {
                validInput = true;
                playingBoard.setTrack(1,i);
                playingBoard.setPlayer(PrideLandsPlayer(playingBoard.getPlayer(i)),i);
            }
            else
            {
                printf("Invalid User Input. Please try again.\n");
                printf("Does Player %d Wish To Go To:\nA: Cub Training\nB: Straight to the Pride Lands\nEnter 'A' for choice A or 'B' for choice B\n", i+1);
            }

        }

    }
    system("clear"); //clearing screen
    int playerTurn = 0;

    if(numPlayers == 2)
    {
        int decidingFirstPlayer = playingBoard.spin()%4;
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
    }
    else
    {
        cout << "\n*** Player 1 Starts The Game ***\n" << endl;
            /**
             * players default to the end of the board when itinialized, so the game loop will work with one player
             */
    }
     
    int playerDesicion;
    playingBoard.displayBoard();  //displays the initial board
    __libcpp_thread_sleep_for(chrono::seconds(2)); //This pauses the current thread for 2 seconds

    while(playingBoard.getPlayerPosition(0) < 51 || playingBoard.getPlayerPosition(1) < 51)  //game loop continues until both players are at the end
    {
        if(playingBoard.getPlayerPosition(0) == 51)  // if player one has reached the "finish line", then only let player two move
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                cout << "  --- Player 2's turn ---  \n" << endl;
                playerDesicion = playerMenu();

                if(playerDesicion != -1)  //if player did not exit out of menu
                {
                    playingBoard.setPlayer(menuDecision(playerDesicion, playingBoard.getPlayer(1), playingBoard, 1),1);
                }
                else  //if player did exit out of menu, make loop conditional false
                {
                    playerDesicion = 5;
                }
            }
            playingBoard.movePlayer(1);
        }
        else if(playingBoard.getPlayerPosition(1) == 51)  // if player two has reached the "finish line", then only let player one move
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                cout << "  --- Player 1's turn ---  \n" << endl;
                playerDesicion = playerMenu();

                if(playerDesicion != -1)  //if player did not exit out of menu
                {
                    playingBoard.setPlayer(menuDecision(playerDesicion, playingBoard.getPlayer(0), playingBoard, 0),0);
                }
                else  //if player did exit out of menu, make loop conditional false
                {
                    playerDesicion = 5;
                }
            }
            playingBoard.movePlayer(0);
        }
        else //if both players have not reached the finish line, then alternate turns
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                cout << "--- Player "<< playerTurn+1 <<"'s turn --- \n" << endl;
                playerDesicion = playerMenu();
                if(playerDesicion != -1)  //if player did not exit out of menu
                {
                    playingBoard.setPlayer(menuDecision(playerDesicion, playingBoard.getPlayer(playerTurn), playingBoard, playerTurn),playerTurn);
                }
                else  //if player did exit out of menu, make loop conditional false
                {
                    playerDesicion = 5;
                }
            }
            if(playingBoard.movePlayer(playerTurn) != 1)  //if conditinal is false that means player gets extra turn becasue they landed on oasis tile
            {
                playerTurn = ((playerTurn +1) % 2);
            }
        }
    }
    playingBoard.calculateWinner();  //calculates the winner!
    return true;
}