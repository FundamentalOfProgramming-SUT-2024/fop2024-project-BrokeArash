#include "rogue.h"
#include "food.h"
#include "player.h"
#include "level.h"



Food* selectFood(Level* level){

    int food;
    food = (rand() % 5) + 1;
    

    switch (food){

        case 1: /* Demon */
            return createFood('f', 5, 0, level->user);
        case 2: /* Fire */
            return createFood('s', 10, 2, level->user);
        case 3: /* Giant */
            return createFood('m', 15, 2, level->user);
        case 4: /* Snake */
            return createFood('f', -10, 0, level->user);
    }



}

Food* createFood(char symbol, int health, int attack, Player* player){
    
    Food* newFood;
    newFood = malloc(sizeof(Food));


    newFood->symbol = symbol;
    newFood->health = health;
    newFood->alive = 1;
    player->attack += 2;

    sprintf(newFood->string, "%c", symbol);

    newFood->position = malloc(sizeof(Position));

    return newFood;
}


void killFood(Food* food){
    food->alive = 0;
}




void drawFood(Food* food){

    if (food->alive)
        mvprintw(food->position->y, food->position->x, food->string);
}





