#include "Board.h"

bool play()
{
    string userInput;
    int numPlayers;
    cout << "Enter The Number of Players:" << endl;
    getline(cin,userInput);
    userInput.erase(remove_if(userInput.begin(), userInput.end(), ::isspace),userInput.end());
    try
    {
        numPlayers = stoi(userInput);
    }
    catch(exception e)
    {
        printf("Invalid user input. Default set to two players\n");
        numPlayers = 2;
    }
    Board playingBoard = Board(numPlayers);
    for(int i = 0; i < numPlayers; i++)
    {
        if(playingBoard.chooseCharacter() == false)
        {
            return false;
        }

        printf("Does Player %d Wish To Go To:\nA: Cub Training\nB: Straight to the Pride Lands\nEnter 'A' for choice A or 'B' for choice B\n", i);
        bool validInput = false;

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
    int playerDesicion = 0;
    while(playingBoard.getPlayerPosition(0) != 51 || playingBoard.getPlayerPosition(0) != 51)
    {
        if(playingBoard.getPlayerPosition(0) == 51)
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
        else if(playingBoard.getPlayerPosition(1) == 51)
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
        else
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

int main()
{
    play();
}