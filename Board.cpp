#include "Board.h"
#include <thread>
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"
/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

/**
 * NOTE: player_position[][] 2D array stores the players track(path) in column index 0(player_position[][0]). A player can either be on the cub traning path(track 1(index 0)) or pride lands path(track 2(index 1)).
 *       In column index 1(player_position[][1]) the player's position on the path is recorded which is between 1 and 51.
 *       [player 1's track][position]
 *       [player 2's track][position]
 */


/**
 * Description - This function creates each lane(track) of tiles by calling initializeTiles()
 * @return - void
 */
void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i);  // This ensures each lane has a unique tile distribution
    }
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
/**
 * Description - This function creates a tile object and initializes it with a color and tile *type(information)*(WORK IN PROGRESS)*
 * @param track is the index of of the 2D array that stores all the created tiles for the two paths
 */
void Board::initializeTiles(int track)
{
    srand(time(NULL));
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        } 
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 5;
            switch (color_choice)
            {
                case 0:
                    temp.color = 'B'; // Blue
                    break;
                case 1:
                    temp.color = 'P'; // Pink
                    break;
                case 2:
                    temp.color = 'N'; // Brown
                    break;
                case 3:
                    temp.color = 'R'; // Red
                    break;
                case 4:
                    temp.color = 'U'; // Purple
                    break;
            }
        }

        // Assign the tile to the board for the specified lane
        temp.type = "placeholder information for tile " + to_string(i);
        _tiles[track][i] = temp;
    }
}

// constructors

/**
 * Default constructor initializes no players
 */
Board::Board()
{
     _player_count = 0;

     // Initialize player position
     player_position[0][0] = -1;
     player_position[0][1] = -1;
     player_position[1][0] = -1;
     player_position[1][1] = -1;

     // Initialize tiles
     initializeBoard();
}
/**
 * This overloaded constructor initializes up to two players at the start of the cub training path 
 * which is the first row of _tiles 2D array(_tiles[0][]). Other functaions may make the player switch 
 * to the "pride lands path" or the second row of _tiles 2D array(_tiles[1][])
 * Other function will create the player objects. This constructor calls initializeBoard()
 */
Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }
        //default setting
    player_position[0][0] = -1;
    player_position[0][1] = -1;
    player_position[1][0] = -1;
    player_position[1][1] = -1;
        // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
            //each players starting position
        player_position[i][1] = 0; 
        player_position[i][0] = 0; 
    }

        // Initialize tiles

    initializeBoard();
}

//end of constructors

/**
 * Description - This function determines if a player is on a tile by determining if the path matches the players path(either cub training(track 0) or pride lands(track 1), if the 
 * position(index) of the tile matches the position of the player, and if the player identifyer is valid.
 * @param track the path (row of _tiles)
 * @param pos the index or position of the tile along the path
 * @param player_index the player identifyer( 0 for player one and 1 for player 2 )
 * @return returns true if the tile matches the players path and index along path 
 */
bool Board::isPlayerOnTile(int track, int pos, int player_index)
{
    if ( (player_index != -1) && (player_position[player_index][1] == pos) && (player_position[player_index][0] == track) )
    {
        return true;
    }
    return false;
}

/**
 * Description - this function print a tile to the output stream. This function calls isPlayerOnTile(int,int,int) to see if either palyer is on the tile that it is outputing.
 * If a player or players are on the tile then the players' Identifyer/s(either 1 or 2) will be added the the tile.
 * @param track the path (row of _tiles)
 * @param pos the index or position of the tile along the path
 */
void Board::displayTile(int track, int pos)
{
    string color = "";
    bool playerTwo = isPlayerOnTile(track, pos, 1);
    bool playerOne = isPlayerOnTile(track, pos, 0);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[track][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[track][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[track][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[track][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[track][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[track][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[track][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[track][pos].color == 'Y')
    {
        color = GREY;
    }
    if(playerOne == true && playerTwo == true)
    {
        cout << color << "|" << 1<< "&"<< 2 << "|" << RESET;
    }
    else if (playerOne == true)
    {
        cout << color << "|" << 1 << "|" << RESET;
    }
    else if(playerTwo == true)
    {
        cout << color << "|" << 2 << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}
//where player is assumed to be on track one
/**
 * Description: This function displays a entire path of tiles to the output stream by repededly calling displayTile(int). This function also outputs the tile information that the player player is on.
 *              if both players are on the same tile, the tile information will only be printed out once.
 * @param track the path (row of _tiles)
 */
void Board::displayTrack(int track)
{
    int tileNumber = -1;
    int player_index = -1;
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        if(player_position[0][0] == track)
        {
            player_index = 0;
        }
        else if(player_position[1][0] == track)
        {
            player_index = 1;
        }
        displayTile(track, i);
        if(isPlayerOnTile(track, i, player_index))
        {
            tileNumber = i;
        }
    }
    if(tileNumber != -1)
    {
        cout << "\n"<<_tiles[track][tileNumber].type;
    }
    cout << endl;
}
/**
 * Description: This function will display the entire board by calling displayTrack(int) twice, to display two tracks.
 */
void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0) 
        {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}
/**
 * Description: This function will create a random number each time the player wants to move
 */
int Board::spin()
{
    return (rand() % 6) +1;
}
/**
 * Description: This function will move a player between 1 index to 6 indexes on the path based off of a random "digital spin"
 * @param player_index the player identifyer( 0 for player one and 1 for player 2 )
 * @return if the player reached the end of the path then the function returns true. Otherwise false
 */
bool Board::movePlayer(int player_index)
{
     // Increment player position
     int rolledNum = spin();
     cout << "Spinning ";
     __libcpp_thread_sleep_for(chrono::seconds(2)); //This pauses the current thread for 2 seconds
     cout << ". ";
     cout << ". ";
     cout << ". ";
     __libcpp_thread_sleep_for(chrono::seconds(2)); //This pauses the current thread for 2 seconds
     cout << "You rolled a " << rolledNum << endl;
     player_position[player_index][1]+= rolledNum;  //incrementing player index by the number rolled
     if (player_position[player_index][1] == _BOARD_SIZE - 1)
     {
         // Player reached last tile
        return true;
     }
     return false;
 }
/**
 * Description: This function gets the players index
 * @param player_index the player identifyer( 0 for player one and 1 for player 2 )
 * @return returns the players index(position) on the path
 */
int Board::getPlayerPosition(int player_index) const
{
     if (player_index >= 0 && player_index <= _player_count)  //checking if valid player
     {
        return player_position[player_index][1];
    }
    return -1;
}
/**
 * Description: This function lets the player travel along their selected path by pressing enter on the keyboard.
 * @return returns true by default
 */
bool Board::adventure(int player_index)
{
    system("clear");  //clears the screen on mac
    cout << "Enter 'S' or 's' to stop moving. Otherwise press enter or anyother key" << endl;
    displayBoard();
    string input;
    bool reachedEnd = false;
    while(tolower(input[0]) != 's' && reachedEnd == false)  // while the user does not enter 's' and they have not reached the end this loop will continue
    {
        getline(cin,input);
        if(tolower(input[0]) != 's'){reachedEnd = movePlayer(player_index);}
        system("clear");
        cout << "Enter 'S' or 's' to stop moving. Otherwise press enter or anyother key" << endl;
        displayBoard();
    }
    return true;
}
/**
 * Description: This function calls the member function Life class displayCharacters() to display the character options to the user. Then the function
 *              parses the users input and calls Life class setCharacter(string) with the user input as the argument.
 * @return returns true if a character is set, false otherwise
 */
bool Board::chooseCharacter()
{
    Life player;
    if(!player.displayCharacters())  //if characters.txt the function returns false
    {
        return false;
    }
    string characterName = "";
    string formatedCharacterName;
    bool chooseValidCharacter = false;

    while(chooseValidCharacter == false)
    {
        formatedCharacterName = "";
        printf("Please choose a character by entering their name or 'STOP' to exit program:\n");
        getline(cin,characterName);
        for(int i = 0; i < characterName.length(); i++)
        {
            if(!isspace(characterName[i]))  //if the character is not a ' ','\f','\n','\r','\t','\v' then format it and add it to the formated string
            {
                if(formatedCharacterName.length() == 0)
                {
                    formatedCharacterName = toupper(characterName[i]);
                }
                else
                {
                    formatedCharacterName+=tolower(characterName[i]);
                }
            }

        }
        chooseValidCharacter = player.setCharacter(formatedCharacterName);  //sets the character with the formated user input
        if(characterName == "STOP") //if user wants to exit program
        {
            return false;
        }
    }
    if(players[0].getName() == "") //if the first spot in players array is empty, add the player
    {
        players[0] = player;
    }
    else
    {
        players[1] = player;
    }
    return true;
}
/**
 * Description: This function gets a player from the players array.
 * @param player_index the player identifyer( 0 for player one and 1 for player 2 )
 * @return the player(Life object)
 */
Life Board::getPlayer(int playerIndex)
{
    if(playerIndex < 2 && playerIndex > -1)
    {
        return players[playerIndex];
    }
    else
    {
        printf("Invalid Player Index\n");
        return players[0];
    }
}
/**
 * Description: This function sets a player to the players array
 * @param player the player the be added
 * @param player_index the player identifyer( 0 for player one and 1 for player 2 )
 * @return void
 */
void Board::setPlayer(Life player, int playerIndex)
{
    if(playerIndex < 2 && playerIndex > -1)
    {
        players[playerIndex] = player;
    }
    else
    {
        printf("Invalid Player Index\n");
    }
}
/**
 * Description: This function will put the player either on row one or rwo two of the _tiles 2D array. 
 * Not literally, but when the function isPlayerOnTile checks, the player will either be on path one(row one A.K.A. cub training) or path two(row two A.K.A. pride lands)
 * @param track the row of the 2D aray where the player will be placed
 * @param player_index the player identifyer( 0 for player one and 1 for player 2 )
 */
void Board::setTrack(int track, int player_index)
{
    if(track == 0 || track == 1)
    {
        cout << "track: " << track << endl;
        player_position[player_index][0] = track;  //sets the track to the player in player_position where the players track and position on track are recorded
    }
    else
    {
        printf("Invalid path.\n");
    }
}
/**
 * Description: This function displays the user menu and gets the users input, which is between 1 and 5.
 * @return the integer that the user entered, unless the user entered 'E' or 'e' which will return -1(unsuccessful)
 */
int playerMenu()
{
    bool validInput = false;
    string userInput;
    while(!validInput)
    {
        system("clear");
        cout << "  --- Player Menu ---  |Options|" << endl;
        cout << "Check Player Progress: |   1   |" << endl;
        cout << "Review Character:      |   2   |" << endl;
        cout << "Check Position:        |   3   |" << endl;
        cout << "Review your Advisor:   |   4   |" << endl;
        cout << "Move Forward:          |   5   |" << endl;
        cout << "\nEnter Valid Option: ";
        
        getline(cin,userInput); //getting input from the user
        if(tolower(userInput[0]) == 'e') //if the user entered 'E' or 'e' then exit and return
        {
            return -1;
        }
        userInput.erase(remove_if(userInput.begin(),userInput.end(),::isspace),userInput.end());  //erasing all ' ','\f','\n','\r','\t','\v' from input
        if(isdigit(userInput[0]))
        {
            return userInput[0];
        }
        else
        {
            cout << "Invalid user input. Please try again. Press 'E' to exit game" << endl;

            __libcpp_thread_sleep_for(chrono::seconds(2));  //pausing thread for 2 seconds before giving the user another opertunity to enter a choice
        }
    }
}
