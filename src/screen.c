#include "rogue.h"
#include "utils.h"

MAX_HEIGHT = 30;
MAX_WIDTH = 120;

void screenSetUp(){

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    refresh();

    srand(time(NULL));
}


void printGameHub(Level * level){
    mvprintw(31, 0, "    Level: %d", level->level);
    printw("    Gold: %d", level->user->gold);
    printw("    Hp: %d(%d)", level->user->health, level->user->maxHealth);
    printw("    Attack: %d", level->user->attack);
    printw("    Exp: %d", level->user->exp);
    printw("      ");
}

void printInventory(Player* player){
    mvprintw(32, 0, "    Inventory: ");
    for(int i = 0; i < player->numberItems; i++){
        printw(player->items[i]->string);
    }
}

