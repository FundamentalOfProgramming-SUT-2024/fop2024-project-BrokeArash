#include "rogue.h"
#include "utils.h"


void combat(Player* player, Monster* monster, int order){

    /* player attacking */
    if (order == 1){

        monster->health -= player->attack;
        if (monster->health > 0)
            player->health -= monster->attack;
 
        else{

            killMonster(monster);
            switch(monster->symbol){
                
                case 'D':
                    player->exp++;
                    break;

                case 'F':
                    player->exp+=2;
                    break;
                case 'G':
                    player->exp+=5;
                    break;
                case 'S':
                    player->exp+=10;
                    break;
                case 'U':
                    player->exp+=20;
                    break;
            }
            
        }
    }
    /* monster attacking */
    else{

        player->health -= monster->attack;

        if (player->health > 0)
            monster->health -= player->attack;
    }
}