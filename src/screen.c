#include "rogue.h"

int screenSetUp() {
    initscr();
    noecho();
    curs_set(0);
    refresh();
    srand(time(NULL));

    return 1;
}

int printGameHub(Level* level){

    mvprintw(30, 0, "      Level: %d", level->level);
    printw("      Gold: %d", level->user->gold);
    printw("     HP: %d(%d)", level->user->health, level->user->maxHealth);
    printw("     attack: %d", level->user->attack);
    printw("     exp: %d", level->user->exp);
    printw("      ");

    return 1;
}