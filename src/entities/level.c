#include "rogue.h"
#include "level.h"
#include "utils.h"
#include "food.h"

Level* createLevel(int level){

    Level* newLevel;
    newLevel = malloc(sizeof(Level));

    newLevel->level = level;
    newLevel->numberOfRooms = 6;
    newLevel->rooms = roomsSetUp();
    connectDoors(newLevel);
    newLevel->tiles = saveLevelPositions();

    newLevel->user = playerSetUp();
    placePlayer(newLevel->rooms, newLevel->user);

    addMonsters(newLevel);
    addFood(newLevel);
    

    return newLevel;
}

void drawLevel(Level* level){


    // printing tiles
    for (int y = 0; y < MAX_HEIGHT; y++){

        for (int x = 0; x < MAX_WIDTH; x++){

            mvaddch(y, x, level->tiles[y][x]);
        }
    }

    // print monsters
    for (int i = 0; i < level->numberOfMonsters; i++){

        drawMonster(level->monsters[i]);
        
    }

    for (int i = 0; i < level->numberOfFood; i++){

        drawFood(level->food[i]);
        
    }

    drawPlayer(level->user);
}

Room** roomsSetUp(){

    Room** rooms;
    rooms = malloc(sizeof(Room)*6);

    for (int x = 0; x < 6; x++){

        rooms[x] = createRoom(x, 3);
        drawRoom(rooms[x]);
    }
    //connectDoors(rooms[0]->doors[3], rooms[1]->doors[1]);
    //pathFind(rooms[0]->doors[3], rooms[1]->doors[1]);
    //connectDoors(rooms[1]->doors[2], rooms[0]->doors[0]);

    return rooms;
}

void connectDoors(Level* level){

    int randomRoom, randomDoor;
    int count;

    for (int i = 0; i < level->numberOfRooms; i++){

        for (int j = 0; j < level->rooms[i]->numberOfDoors; j++){

            if (level->rooms[i]->doors[j]->connected == 1)
                continue;

            count = 0;

            while (count < 10){

                randomRoom = rand() % level->numberOfRooms;
                randomDoor = rand() % level->rooms[randomRoom]->numberOfDoors;

                if (level->rooms[randomRoom]->doors[randomDoor]->connected == 1 || randomRoom == i){
                    count++;
                    continue;
                }

                pathFind(&level->rooms[randomRoom]->doors[randomDoor]->position, &level->rooms[i]->doors[j]->position);

                level->rooms[randomRoom]->doors[randomDoor]->connected = 1;
                level->rooms[i]->doors[j]->connected = 1;
                break;
            }
        }
    }

}


char** saveLevelPositions(){

    char** positions;
    positions = malloc(sizeof(char*) * MAX_HEIGHT);

    for (int y = 0; y < MAX_HEIGHT; y++){

        positions[y] = malloc(sizeof(char) * MAX_WIDTH);

        for (int x = 0; x < MAX_WIDTH; x++){

            positions[y][x] = mvinch(y, x);
        }
    }

    return positions;
}


/* check what is at next position */
void checkPostion(Position* newPosition, Level* level){
    Player* user;
    user = level->user;
    switch (mvinch(newPosition->y, newPosition->x)){

        case '.':
        case '#':
            playerMove(newPosition, user, level->tiles);
            break;

        case '+':
                playerMove(newPosition, user, level->tiles);
            break;
        case 'D':
        case 'F':
        case 'G':
        case 'S':
        case 'U':
            combat(user, getMonsterAt(newPosition, level->monsters), 1);
        default:
            break;
    }
}



void moveMonsters(Level* level){

    for (int x = 0; x < level->numberOfMonsters; x++){

        if (level->monsters[x]->alive == 0)
            continue;

        if (level->monsters[x]->pathfinding == 1)
            pathfindingRandom(level->monsters[x]->position);

        else
            pathfindingSeek(level->monsters[x]->position, level->user->position);
    }
}


void addMonsters(Level* level){

    level->monsters = malloc(sizeof(Monster*)* 15);
    level->numberOfMonsters = 0;

    for (int x = 0; x < (level->numberOfRooms); x++){

        if ((rand() % 2) == 0){

            level->monsters[level->numberOfMonsters] = selectMonster(level->level);
            setStartingPosition(level->monsters[level->numberOfMonsters], level->rooms[x]);
            level->numberOfMonsters++;

        }
    }

    for (int x = 0; x < (level->numberOfRooms); x++){

        if ((rand() % 2) == 0){

            level->monsters[level->numberOfMonsters] = selectMonster(level->level);
            setStartingPosition(level->monsters[level->numberOfMonsters], level->rooms[x]);
            level->numberOfMonsters++;

        }
    }
}

void addFood(Level* level){

    level->food = malloc(sizeof(Food*)* 15);
    level->numberOfFood = 0;

    for (int x = 0; x < (level->numberOfRooms); x++){

        if ((rand() % 2) == 0){

            level->food[level->numberOfFood] = selectFood(level);
            setStartingPosition2(level->food[level->numberOfFood], level->rooms[x]);
            level->numberOfFood++;

        }
    }
}