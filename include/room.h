#ifndef ROOM_H
#define ROOM_H

#include "monster.h"
#include "player.h"
#include "position.h"
#include "door.h"
#include "food.h"

typedef struct Food Food;

typedef struct Room{

    Position position;
    int height;
    int width;
    struct Stair* stair;
    struct Door** doors;
    int numberOfDoors;
    // Monster ** monsters;
    // Item ** items;
} Room;

typedef struct Stair{
    
    Position position;
} Stair;



/* room functions */
Room* createRoom(int grid, int numberOfDoors);
int drawRoom(Room* room);


void placePlayer(Room** rooms, Player* user);
void setStartingPosition(Monster* monster, Room* room);
void setStartingPosition2(Food* food, Room* room);



#endif
