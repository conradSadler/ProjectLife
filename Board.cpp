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

void Board::initializeTiles(int player_index)
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
        _tiles[player_index][i] = temp;
    }
}


Board::Board()
{
     _player_count = 1;

     // Initialize player position
     player_position[0][0] = 0;
     player_position[0][1] = 0;
     player_position[1][0] = -1;
     player_position[1][1] = -1;

     // Initialize tiles
     initializeBoard();
}

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
    player_position[0][0] = -1;
    player_position[0][1] = -1;
    player_position[1][0] = -1;
    player_position[1][1] = -1;
    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        player_position[i][1] = 0;
        player_position[i][0] = 0;
    }

    // Initialize tiles

    initializeBoard();
}
bool Board::isBothPlayersOnTile(int track, int pos, int player_index)
{
    if (player_index != -1 && player_position[player_index][1] == pos && (player_position[1][1] == player_position[0][1]) && player_position[player_index][0] == track && (player_position[1][0] == player_position[0][0]))
    {
        return true;
    }
    return false;
}

bool Board::isPlayerOnTile(int track, int pos, int player_index)
{
    if (player_index != -1 && player_position[player_index][1] == pos && player_position[player_index][0] == track)
    {
        return true;
    }
    return false;
}

void Board::displayTile(int track, int pos, int player_index)
{
    // string space = "                                       ";
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
        displayTile(track, i, player_index);
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

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0) {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}
int Board::spin()
{
    return (rand() % 6) +1;
}
bool Board::movePlayer(int player_index)
{
     // Increment player position
     int rolledNum = spin();
     cout << "Spinning ";
     __libcpp_thread_sleep_for(chrono::seconds(2));
     cout << ". ";
     __libcpp_thread_sleep_for(chrono::seconds(2));
     cout << ". ";
     __libcpp_thread_sleep_for(chrono::seconds(2));
     cout << ". ";
     cout << "You rolled a " << rolledNum << endl;
     player_position[player_index][1]+= rolledNum;
     if (player_position[player_index][1] == _BOARD_SIZE - 1)
     {
         // Player reached last tile
        return true;
     }
     return false;
 }

int Board::getPlayerPosition(int player_index) const
{
     if (player_index >= 0 && player_index <= _player_count)
     {
        return player_position[player_index][1];
    }
    return -1;
}

bool Board::adventure(int player_index)
{
    system("clear");
    cout << "Enter 'S' or 's' to stop moving. Otherwise press enter or anyother key" << endl;
    displayBoard();
    string input;
    bool reachedEnd = false;
    while(tolower(input[0]) != 's' && reachedEnd == false)
    {
        getline(cin,input);
        if(tolower(input[0]) != 's'){reachedEnd = movePlayer(player_index);}
        system("clear");
        cout << "Enter 'S' or 's' to stop moving. Otherwise press enter or anyother key" << endl;
        displayBoard();
    }
    return true;
}

bool Board::chooseCharacter()
{
    Life player;
    if(!player.displayCharacters())
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
            if(!isspace(characterName[i]))
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
        chooseValidCharacter = player.setCharacter(formatedCharacterName);
        if(characterName == "Stop")
        {
            return false;
        }
    }
    if(players[0].getName() == "")
    {
        players[0] = player;
    }
    else
    {
        players[1] = player;
    }
    return true;
}
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
void Board::setTrack(int track, int player_index)
{
    if(track == 0 || track == 1)
    {
        cout << "track: " << track << endl;
        player_position[player_index][0] = track;
    }
    else
    {
        printf("Invalid path.\n");
    }
}
int Board::playerMenu()
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
        getline(cin,userInput);
        if(tolower(userInput[0]) == 'e')
        {
            return -1;
        }
        userInput.erase(remove_if(userInput.begin(),userInput.end(),::isspace),userInput.end());
        if(isdigit(userInput[0]))
        {
            return userInput[0];
        }
        else
        {
            cout << "Invalid user input. Please try again. Press 'E' to exit game" << endl;

            __libcpp_thread_sleep_for(chrono::seconds(2));
        }
    }
}
