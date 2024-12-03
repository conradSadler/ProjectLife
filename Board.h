#include "Tile.h"
#include "Life.h"
#include "RandomNum.h"
#include "RandomEvents.h"

#ifndef BOARD_H
#define BOARD_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 * 
 * This class pertains to using the game board
 */

class Board
{
private:
    struct r
    {
        string eventName;
        string path;
        string advisor;
        string pridePoints;
    };
    static const int _BOARD_SIZE = 52;
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int player_position[_MAX_PLAYERS][_MAX_PLAYERS];
    void displayTile(int track, int pos);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos, int track);
    Life players[2];
    Tile _tiles[2][_BOARD_SIZE];
    RandomNum randomNumObject;
    RandomEvents randomEventsObject;

public:
    Board();
    Board(int player_count);
    void testForRandomEvent(int dec);
    void setPlayer(Life player, int playerIndex);
    void setTrack(int track, int player_index);
    void displayTrack(int player_index);
    void initializeBoard();
    void displayBoard();
    void calculateWinner();
    void checkForRandomEvent(int player_index);
    bool checkForImpact(int player_index);
    bool isBothPlayersOnTile(int track, int pos, int player_index);
    bool adventure(int player_index);
    bool chooseCharacter();
    int getPlayerPosition(int player_index) const;
    int movePlayer(int player_index);
    int spin();
    Life getPlayer(int);
};

#endif