#include "rogue.h"

int MAX_HEIGHT = 25;
int MAX_WIDTH = 100;

int main() {
    
    char ch;
    

    Position* newPosition;

    Level* level;


    screenSetUp();
    
    level = createLevel(1);
    printGameHub(level);

    

    while ((ch = getch()) != 'q') {

        printGameHub(level);
        newPosition = handleInput(ch, level->user);
        checkPosition(newPosition, level);
        moveMonsters(level);
        move(level->user->position->y, level->user->position->x);
    
    
    }
    endwin();

    return 0;
}





