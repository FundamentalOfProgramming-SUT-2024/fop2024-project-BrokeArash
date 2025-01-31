#include "rogue.h"
#include "player.h"


Player* playerSetUp(){

    int MAX_ITEMS = 25;

    Player* newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->position = malloc(sizeof(Position));
    newPlayer->items = malloc(sizeof(Item*));

    newPlayer->health = 10;
    newPlayer->attack = 1;
    newPlayer->gold = 0;
    newPlayer->exp = 0;
    newPlayer->maxHealth = 100;
    newPlayer->numberItems = 0;

    newPlayer->items[newPlayer->numberItems++] = createSword(1, 20);  

    return newPlayer;
}


Position* handleInput(int input, Player * user){

    Position* newPosition;
    newPosition = malloc(sizeof(Position));
    switch (input){

        /* move up */
        case 'j':
        case 'J':
            newPosition->y = user->position->y - 1;
            newPosition->x = user->position->x;
            break;

        /* move down */
        case 'k':
        case 'K':
            newPosition->y = user->position->y + 1;
            newPosition->x = user->position->x;
            break;

        /* move left */
        case 'h':
        case 'H':
            newPosition->y = user->position->y;
            newPosition->x = user->position->x - 1;
            break;

        /* move right */
        case 'l':
        case 'L':
            newPosition->y = user->position->y;
            newPosition->x = user->position->x + 1;
            break;
        /* move NW*/
        case 'y':
        case 'Y':
            newPosition->y = user->position->y - 1;
            newPosition->x = user->position->x - 1;
            break;
        /* move NE*/
        case 'u':
        case 'U':
            newPosition->y = user->position->y - 1;
            newPosition->x = user->position->x + 1;
            break;
        /*move SW*/
        case 'b':
        case 'B':
            newPosition->y = user->position->y + 1;
            newPosition->x = user->position->x - 1;
            break;
        /*move SE*/
        case 'n':
        case 'N':
            newPosition->y = user->position->y + 1;
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