#include "rogue.h"
#include "monster.h"



Monster* selectMonster(int level){

    int monster;
    monster = (rand() % 5) + 1;
    

    switch (monster){

        case 1: /* Demon */
            return createMonster('D', 5, 1, 1, 1, 2);
        case 2: /* Fire */
            return createMonster('F', 10, 2, 1, 1, 2);
        case 3: /* Giant */
            return createMonster('G', 15, 3, 1, 1, 2);
        case 4: /* Snake */
            return createMonster('S', 20, 5, 1, 1, 2);
        case 5: /* Undead */
            return createMonster('U', 30, 8, 1, 1, 2);
    }



}

Monster* createMonster(char symbol, int health, int attack, int speed, int defence, int pathfinding){
    
    Monster* newMonster;
    newMonster = malloc(sizeof(Monster));


    newMonster->symbol = symbol;
    newMonster->health = health;
    newMonster->attack = attack;
    newMonster->speed = speed;
    newMonster->defence = defence;
    newMonster->pathfinding = pathfinding;
    newMonster->alive = 1;

    sprintf(newMonster->string, "%c", symbol);

    newMonster->position = malloc(sizeof(Position));

    return newMonster;
}

void killMonster(Monster* monster){
    monster->alive = 0;
}



void pathfindingRandom(Position* position){

    int random;

    random = rand() % 5;

    switch (random){

        /* step up */
        case 0:
            if (mvinch(position->y - 1, position->x) == '.')
                position->y = position->y - 1;
            break;

        /* step down */
        case 1:
            if (mvinch(position->y + 1, position->x) == '.')
                position->y = position->y + 1;
            break;

        /* step left */
        case 2:
            if (mvinch(position->y, position->x - 1) == '.')
                position->x = position->x - 1;
            break;

        /* step right */
        case 3:
            if (mvinch(position->y, position->x + 1) == '.')
                position->x = position->x + 1;
            break;

        /* do nothing */
        case 4:
            break;

    }
}

void pathfindingSeek(Position* start, Position* destination){
    /* step left */
    if ((abs((start->x - 1) - destination->x) < abs(start->x - destination->x)) && (mvinch(start->y, start->x - 1) == '.'))
        start->x = start->x - 1;

    /* step right */
    else if ((abs((start->x + 1) - destination->x) < abs(start->x - destination->x)) && (mvinch(start->y, start->x + 1) == '.'))
        start->x = start->x + 1;
    
    /* step down */
    else if ((abs((start->y + 1) - destination->y) < abs(start->y - destination->y)) && (mvinch(start->y + 1, start->x) == '.'))
        start->y = start->y + 1;

    /* step up */
    else if ((abs((start->y - 1) - destination->y) < abs(start->y - destination->y)) && (mvinch(start->y - 1, start->x) == '.'))
        start->y = start->y - 1;
}

Monster* getMonsterAt(Position* position, Monster** monsters){

    for (int x = 0; x < 6; x++){

        if ((position->y == monsters[x]->position->y) && (position->x == monsters[x]->position->x))
            return monsters[x];
    }

    return NULL;
}

void drawMonster(Monster* monster){

    if (monster->alive)
        mvprintw(monster->position->y, monster->position->x, monster->string);
}