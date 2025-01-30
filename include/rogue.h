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
    struct Player* user;
}Level;

typedef struct Position{
    int x,y;
    //TILE_TYPE tile;
}Position;


typedef struct Door{

    Position position;
    int connected;


}Door;


typedef struct Player {

    Position* position;
    int health;
    int attack;
    int gold;
    int maxHealth;
    int exp;
} Player;

typedef struct Monster{

    char string[2];
    char symbol;
    int health;
    int attack;
    int speed;
    int defence;
    int pathFinding;
    Position* position;
    int alive;

}Monster;

typedef struct Room{
    int height, width;
    Position position;
    Door** doors;
    int numberOfDoors;
    //Monster** monsters;
    //Item ** items
}Room;

extern int MAX_HEIGHT;
extern int MAX_WIDTH;

int screenSetUp();
Room** roomSetUp();
Player* playerSetUp();
Position* handleInput(int input, Player* user);
int checkPosition(Position* newPosition, Level* level);
int playerMove(Position* newPosition, Player* user, char** level);
int placePlayer(Room** rooms, Player* user);

Level* createLevel(int level);
Room* createRoom(int grid, int numberOfDoors);
int drawRoom(Room *room);
void connectDoors(Level* level);
char** saveLevelPositions();


int addMonsters(Level* level);
Monster* selectMonster(int level);
Monster* createMonster(char symbol, int health, int attack, int speed, int defence, int pathFinding);
int setStartingPosition(Monster* monster, Room* room);
int moveMonsters(Level* level);
int pathFindingSeek(Position* start, Position* destination);
int pathFindingRandom(Position* position);
int killMonster(Monster* monster);
Monster* getMonsterAt(Position* position, Monster** monsters);


int combat(Player* player, Monster* monster, int order);


#endif
