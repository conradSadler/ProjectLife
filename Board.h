#include "Tile.h"
#include "Life.h"

#ifndef BOARD_H
#define BOARD_H


class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int player_position[_MAX_PLAYERS][_MAX_PLAYERS];
    void displayTile(int track, int pos, int player_index);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos, int track);
    Life players[2];

public:
    Board();
    Board(int player_count);
    void displayTrack(int player_index);
    void initializeBoard();
    void displayBoard();
    bool movePlayer(int player_index);
    int getPlayerPosition(int player_index) const;
    bool adventure(int player_index);
    bool chooseCharacter();
    Life getPlayer(int);
    void setPlayer(Life player, int playerIndex);
    void setTrack(int track, int player_index);
    bool isBothPlayersOnTile(int track, int pos, int player_index);
    int spin();
    int playerMenu();
};

#endif