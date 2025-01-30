#include "rogue.h"

Room * createRoom(int grid){


    Room* newRoom = malloc(sizeof(Room));
    
    switch(grid){

        case 0:
            newRoom->position.x = 0;
            newRoom->position.y = 0;
            break;
        case 1:
            newRoom->position.x = 33;
            newRoom->position.y = 0;
            break;
        case 2:
            newRoom->position.x = 66;
            newRoom->position.y = 0;
            break;
        case 3:
            newRoom->position.x = 0;
            newRoom->position.y = 14;
            break;
        case 4:
            newRoom->position.x = 33;
            newRoom->position.y = 14;
            break;
        case 5:
            newRoom->position.x = 66;
            newRoom->position.y = 14;
            break;
    }

    newRoom->height = rand() % 6 + 6; //MAX 11
    newRoom->width =  rand() % 14 + 6; //MAX 19

    newRoom->position.x += rand()% (20- newRoom->width  + 1);
    newRoom->position.y += rand()% (4 - newRoom->height + 1);

    newRoom->doors = malloc(sizeof(Position)*4);
    
    newRoom->doors[0] = malloc(sizeof(Position));
    newRoom->doors[0]->x = rand()% (newRoom->width-2) + newRoom->position.x + 1;
    newRoom->doors[0]->y = newRoom->position.y;

    newRoom->doors[1] = malloc(sizeof(Position));
    newRoom->doors[1]->x = newRoom->position.x;
    newRoom->doors[1]->y = rand()% (newRoom->height-2) + newRoom->position.y+1;

    newRoom->doors[2] = malloc(sizeof(Position));
    newRoom->doors[2]->x = rand()% (newRoom->width-2) + newRoom->position.x + 1;
    newRoom->doors[2]->y = newRoom->position.y + newRoom->height-1;

    newRoom->doors[3] = malloc(sizeof(Position));
    newRoom->doors[3]->x = newRoom->position.x + newRoom->width-1;
    newRoom->doors[3]->y = rand()% (newRoom->height-2) + newRoom->position.y + 1;

    
    return newRoom;
}


int drawRoom(Room *room){
    int y, x;

    for(x = room->position.x; x < room->position.x+room->width; x++){
        mvprintw(room->position.y, x, "-");
        mvprintw(room->position.y+room->height-1, x, "-");
    }

    for(y = room->position.y + 1; y < room->position.y+room->height-1;y++){
        mvprintw(y, room->position.x, "|");
        mvprintw(y, room->position.x+room->width-1, "|");
        for(x = room->position.x+1;x < room->position.x + room->width-1; x++){
            mvprintw(y, x, ".");
        }
    }


    mvprintw(room->doors[0]->y, room->doors[0]->x, "+");
    mvprintw(room->doors[1]->y, room->doors[1]->x, "+");
    mvprintw(room->doors[2]->y, room->doors[2]->x, "+");
    mvprintw(room->doors[3]->y, room->doors[3]->x, "+");


    return 1;
}

int connectDoors(Position* doorOne, Position* doorTwo){

    Position temp;
    Position previous;

    temp.x = doorOne->x;
    temp.y = doorOne->y;

    previous = temp;
    int count = 0;

    while(1){

        if(abs((temp.x - 1) - doorTwo->x) < abs(temp.x - doorTwo->x) && mvinch(temp.y, temp.x - 1) == ' '){
            previous.x = temp.x;
            temp.x = temp.x - 1;
        }

        else if(abs((temp.x + 1) - doorTwo->x) < abs(temp.x - doorTwo->x) && mvinch(temp.y, temp.x + 1) == ' '){
            previous.x = temp.x;
            temp.x = temp.x + 1;
        }

        else if(abs((temp.y + 1) - doorTwo->y) < abs(temp.y - doorTwo->y) && mvinch(temp.y+1, temp.x) == ' '){
            previous.y = temp.y;
            temp.y = temp.y + 1;
        }

        else if(abs((temp.y - 1) - doorTwo->y) < abs(temp.y - doorTwo->y) && mvinch(temp.y-1, temp.x) == ' '){
            previous.y = temp.y;
            temp.y = temp.y -1;
        }
        else{

            if(count == 0){
                temp = previous;
                count ++;
                continue;
            }
            else
                return 0;
        }

        mvprintw(temp.y, temp.x, "#");
        getch();
    }


    

    return 1;    
}