#include "rogue.h"
#include "game.h"
#include "level.h"
#include "utils.h"



void render(Game* game){

    clear();
    printGameHub(game->levels[game->currentLevel - 1]);
    drawLevel(game->levels[game->currentLevel - 1]);
}

void gameLoop(Game* game){

    usleep(100000);
    int ch = '\0';
    Position* newPosition;
    Level* level;

    if (game->currentLevel == 0){

        game->levels[game->currentLevel] = createLevel(1);
        game->currentLevel++;
    }

    // if (game->currentLevel == 1){

    //     game->levels[game->currentLevel] = createLevel(2);
    //     game->currentLevel++;
    // }

    // if (game->currentLevel == 2){

    //     game->levels[game->currentLevel] = createLevel(3);
    //     game->currentLevel++;
    // }

    // if (game->currentLevel == 3){

    //     game->levels[game->currentLevel] = createLevel(4);
    //     game->currentLevel++;
    // }


    level = game->levels[game->currentLevel - 1];

    /* main game loop */
    while (1){

        if(ch == 'q')
            break;

        if(ch == 'i')
            printInventory(level->user);

        else{

            newPosition = handleInput(ch, level->user);
            checkPostion(newPosition, level);
            moveMonsters(level);

            render(game);

            if (level->user->health <= 0){

                game->currentLevel = 0;
                clear();
                mvprintw(12, 30, "YOU DIED");
                getch();
                return;
            }
        }
        
        ch = getch();
    }
}