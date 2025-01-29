#ifndef ROGUE_H
#define ROGUE_H


#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

typedef struct Level{
    char** tiles;
    int level;
    int numberOfRooms;
    struct Room** rooms; 
    struct Monster** monsters;
    int numberOfMonsters;
}Level;

typedef struct Position{
    int x,y;
    //TILE_TYPE tile;
}Position;

typedef struct Player {

    Position position;
    int Health;
} Player;

typedef struct Monster{
    char symbol;
    int health;
    int attack;
    int speed;
    int defence;
    int pathFinding;
    Position position;

}Monster;

typedef struct Room{
    int height, width;
    Position position;
    Position** doors;
    //Monster** monsters;
    //Item ** items
}Room;

int screenSetUp();
Room** roomSetUp();
Player* playerSetup();
Position* handleInput(int input, Player* user);
int checkPosition(Position* newPosition, Player* user,char ** level);
int playerMove(Position* newPosition, Player* user, char** level);

Level* createLevel();
Room* createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);
int connectDoors(Position* doorOne, Position* doorTwo);
char** saveLevelPositions();


int addMonsters(Level* level);
Monster* selectMonster(int level);
Monster* createMonster(char symbol, int health, int attack, int speed, int defence, int pathFinding);
int setStartingPosition(Monster* monster, Room* room);


#endif
