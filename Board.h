#include "Tile.h"
#include "Life.h"

#ifndef BOARD_H
#define BOARD_H

/**
 * Name: ConRad Sadler
 * Project: Project Life Computer Science 1300
 * Date: 11/22/2024
 */

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int player_position[_MAX_PLAYERS][_MAX_PLAYERS];
    void displayTile(int track, int pos);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos, int track);
    Life players[2];
    Tile _tiles[2][_BOARD_SIZE];

public:
    Board();
    Board(int player_count);
    void setPlayer(Life player, int playerIndex);
    void setTrack(int track, int player_index);
    void displayTrack(int player_index);
    void initializeBoard();
    void displayBoard();
    bool isBothPlayersOnTile(int track, int pos, int player_index);
    bool movePlayer(int player_index);
    bool adventure(int player_index);
    bool chooseCharacter();
    int getPlayerPosition(int player_index) const;
    int spin();
    Life getPlayer(int);
};

#endif