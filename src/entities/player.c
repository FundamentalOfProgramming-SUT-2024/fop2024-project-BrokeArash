#include "rogue.h"
#include "player.h"


Player* playerSetUp(){

    int MAX_ITEMS = 25;

    Player* newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->position = malloc(sizeof(Position));
    newPlayer->items = malloc(sizeof(Item*));

    newPlayer->health = 20;
    newPlayer->attack = 1;
    newPlayer->gold = 0;
    newPlayer->exp = 0;
    newPlayer->maxHealth = 20;
    newPlayer->numberItems = 0;

    newPlayer->items[newPlayer->numberItems++] = createSword(1, 20);  

    return newPlayer;
}


Position* handleInput(int input, Player * user){

    Position* newPosition;
    newPosition = malloc(sizeof(Position));
    switch (input){

        /* move up */
        case 'w':
        case 'W':
            newPosition->y = user->position->y - 1;
            newPosition->x = user->position->x;
            break;

        /* move down */
        case 's':
        case 'S':
            newPosition->y = user->position->y + 1;
            newPosition->x = user->position->x;
            break;

        /* move left */
        case 'a':
        case 'A':
            newPosition->y = user->position->y;
            newPosition->x = user->position->x - 1;
            break;

        /* move right */
        case 'd':
        case 'D':
            newPosition->y = user->position->y;
            newPosition->x = user->position->x + 1;
            break;

        default:
            break;
    }

    return newPosition;
}


void playerMove(Position* newPosition, Player* user, char** level){

    user->position->y = newPosition->y;
    user->position->x = newPosition->x;
}

void drawPlayer(Player* player){

    mvprintw(player->position->y, player->position->x, "H");
    move(player->position->y, player->position->x);
}