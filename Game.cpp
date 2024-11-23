# include "Game.h";

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
    while(playingBoard.getPlayerPosition(0) != 51 || playingBoard.getPlayerPosition(0) != 51)
    {
        if(playingBoard.getPlayerPosition(0) == 51)  // if player one has reached the "finish line", then only let player two move
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                playerDesicion = playingBoard.playerMenu();
                cout << "Player 2's turn" << endl;
                //create menu function to handle menu (1->4)
            }
            playingBoard.movePlayer(playerTurn);
            playerTurn = 1;
            playingBoard.displayBoard();
        }
        else if(playingBoard.getPlayerPosition(1) == 51)  // if player two has reached the "finish line", then only let player one move
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                playerDesicion = playingBoard.playerMenu();
                cout << "Player 1's turn" << endl;
                //create menu function to handle menu (1->4)
            }
            playingBoard.movePlayer(playerTurn);
            playerTurn = 0;
            playingBoard.displayBoard();
        }
        else //if both players have not reached the finish line, then alternate turns
        {
            playerDesicion = 0;
            while(playerDesicion != 5)
            {
                playerDesicion = playingBoard.playerMenu();
                cout << "Player "<< playerTurn+1 <<"'s turn" << endl;
                //create menu function to handle menu (1->4)
            }
            playingBoard.movePlayer(playerTurn);
            playerTurn = ((playerTurn +1) % 2);
            playingBoard.displayBoard();
        }
    }
    return true;  
}