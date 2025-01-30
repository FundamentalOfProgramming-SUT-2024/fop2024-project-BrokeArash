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
    newMonster->alive = 1;

    sprintf(newMonster->string, "%c", symbol);
    newMonster->position = malloc(sizeof(Position));

    return newMonster;
}

int killMonster(Monster* monster){

    mvprintw(monster->position->y, monster->position->x, ".");
    monster->alive = 0;

    return 1;
}

int setStartingPosition(Monster* monster, Room* room){

    

    monster->position = malloc(sizeof(Position));

    monster->position->x = (rand()% (room->width-2) + room->position.x + 1);
    monster->position->y = (rand()% (room->height-2) + room->position.y + 1);

    

    mvprintw(monster->position->y, monster->position->x, monster->string);

    return 1;
}

int moveMonsters(Level* level){

    int x;
    for(x = 0; x < level->numberOfMonsters; x++){
        if(level->monsters[x]->alive == 0)
            continue;

        mvprintw(level->monsters[x]->position->y, level->monsters[x]->position->x, ".");
        
        if(level->monsters[x]->pathFinding == 1)
            pathFindingRandom(level->monsters[x]->position);
        else
            pathFindingSeek(level->monsters[x]->position, level->user->position);
            

        mvprintw(level->monsters[x]->position->y, level->monsters[x]->position->x, level->monsters[x]->string);
    }
}

int pathFindingRandom(Position* position){

    int random;
    random = rand()% 5;

    switch(random){
        case 0:
            if(mvinch(position->y-1, position->x) == '.')
                position->y--;
            break;
        case 1:
            if(mvinch(position->y+1, position->x) == '.')
                position->y++;
            break;
        case 2:
            if(mvinch(position->y, position->x-1) == '.')
                position->x--;
            break;
        case 3:
            if(mvinch(position->y, position->x+1) == '.')
                position->x++;
            break;
        case 4:
            break;
    }

}


int pathFindingSeek(Position* start, Position* destination){

    
    if(abs((start->x - 1) - destination->x) < abs(start->x - destination->x) && mvinch(start->y, start->x - 1) == '.'){
        start->x = start->x - 1;
    }

    else if(abs((start->x + 1) - destination->x) < abs(start->x - destination->x) && mvinch(start->y, start->x + 1) == '.'){
        start->x = start->x + 1;
    }

    else if(abs((start->y + 1) - destination->y) < abs(start->y - destination->y) && mvinch(start->y+1, start->x) == '.'){
        start->y = start->y + 1;
    }

    else if(abs((start->y - 1) - destination->y) < abs(start->y - destination->y) && mvinch(start->y-1, start->x) == '.'){
        start->y = start->y -1;
    }
    
    return 1;

}

Monster* getMonsterAt(Position* position, Monster** monsters){

    for(int x = 0; x <6; x++){
        if((position->y == monsters[x]->position->y) && (position->x == monsters[x]->position->x)){
            return monsters[x];
        }
    }
    return NULL;
}