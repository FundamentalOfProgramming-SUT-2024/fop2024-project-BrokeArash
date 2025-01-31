#ifndef PLAYER_H
#define PLAYER_H

#include "position.h"
#include "item.h"

extern int MAX_ITEMS;

typedef struct Player
{
    Position * position;
    int health;
    int attack;
    int gold;
    int maxHealth;
    int exp;
    int numberItems;
    // Room * room;
    Item** items;
} Player;

/* player functions */
Player * playerSetUp();
Position * handleInput(int input, Player * user);
void playerMove(Position * newPosition, Player * user, char ** level);
void drawPlayer(Player * player);


#endif