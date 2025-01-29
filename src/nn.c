#include "rogue.h"


int main() {
    Player* user;
    char ch;
    Position* newPosition;

    Level* level;


    screenSetUp();
    
    level = createLevel(1);
    

    user = playerSetup();

    while ((ch = getch()) != 'q') {
        newPosition = handleInput(ch, user);
        checkPosition(newPosition, user, level->tiles);
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






