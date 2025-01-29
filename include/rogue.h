#ifndef ROGUE_H
#define ROGUE_H


#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

typedef struct Position{
    int x,y;
    //TILE_TYPE tile;
}Position;

typedef struct Player {

    Position position;
    int Health;
} Player;

typedef struct Room{
    int height, width;
    Position position;
    Position** doors;
    //Monster** monsters;
    //Item ** items
}Room;

int screenSetUp();
Room** mapSetUp();
Player* playerSetup();
Position* handleInput(int input, Player* user);
int checkPosition(Position* newPosition, Player* user,char ** level);
int playerMove(Position* newPosition, Player* user, char** level);


Room* createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);
int connectDoors(Position* doorOne, Position* doorTwo);
char** saveLevelPositions();




#endif
