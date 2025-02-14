#ifndef UTILS_H
#define UTILS_H

#include "level.h"
#include "position.h"
#include "player.h"
#include "monster.h"
#include "food.h"



void pathFind(Position * start, Position * end);

/* screen functions */
void screenSetUp();
void printGameHub(Level * level);
void printInventory(Player* player);
void combat(Player * player, Monster * monster, int order);

#endif