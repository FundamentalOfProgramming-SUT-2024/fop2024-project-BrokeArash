#include "rogue.h"


int main() {
    
    char ch;
    Position* newPosition;

    Level* level;


    screenSetUp();
    
    level = createLevel(1);
    

    

    while ((ch = getch()) != 'q') {


        newPosition = handleInput(ch, level->user);
        checkPosition(newPosition, level);
        moveMonsters(level);
        move(level->user->position->y, level->user->position->x);
    
    
    }
    endwin();

    return 0;
}

int screenSetUp() {
    initscr();
    noecho();
    curs_set(0);
    refresh();
    srand(time(NULL));

    return 1;
}






