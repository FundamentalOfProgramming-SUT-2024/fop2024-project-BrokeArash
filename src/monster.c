#include "rogue.h"


int addMonsters(Level* level){

    level->monsters = malloc(sizeof(Monster *) * 6);
    level->numberOfMonsters = 0;

    for(int x = 0; x < level->numberOfRooms; x++){

        if((rand()%2) == 0){

            level->monsters[level->numberOfMonsters] = selectMonster(level->level);
            setStartingPosition(level->monsters[level->numberOfMonsters], level->rooms[x]);
            level->numberOfMonsters++;
        }

    }
}

Monster* selectMonster(int level){
    int monster;

    switch(level){
        case 1:
        case 2:
        case 3:
            monster = (rand()% 2) + 1;
            break;

        case 4:
        case 5:
            monster = (rand()% 2) + 2; 
            break;

        case 6:
            monster = 3;
            break;
    }

    switch(monster){
        case 1:
            return createMonster('X', 2, 1, 1, 1, 1);
        case 2:
            return createMonster('G', 5, 3, 1, 1, 2);
        case 3:
            return createMonster('T', 15, 5, 1, 1, 1);
    }
}

Monster* createMonster(char symbol, int health, int attack, int speed, int defence, int pathFinding){
    Monster* newMonster;
    newMonster = malloc(sizeof(Monster));

    newMonster->symbol = symbol;
    newMonster->health = health;
    newMonster->attack = attack;
    newMonster->speed = speed;
    newMonster->defence = defence;
    newMonster->pathFinding = pathFinding;

    return newMonster;
}

int setStartingPosition(Monster* monster, Room* room){

    char buffer[8];

    monster->position.x = (rand()% (room->width-2) + room->position.x + 1);
    monster->position.y = (rand()% (room->height-2) + room->position.y + 1);

    sprintf(buffer, "%c", monster->symbol);

    mvprintw(monster->position.y, monster->position.x, buffer);

    return 1;
}