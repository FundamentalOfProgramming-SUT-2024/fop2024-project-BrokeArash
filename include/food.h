#ifndef FOOD_H
#define FOOD_H

#include "position.h"
#include "level.h"
#include "player.h"

typedef struct Level Level;


typedef struct Food {
    char string[2];
    char symbol;
    int health;
    int alive;
    Position* position;
} Food;

Food* selectFood(Level* level);
Food* createFood(char symbol, int health, int attack, Player* player);
void killFood(Food* food);
void drawFood(Food* food);

#endif
