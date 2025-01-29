#include "rogue.h"

Room * createRoom(int x, int y, int height, int width){


    Room* newRoom = malloc(sizeof(Room));
    newRoom->position.x = x;
    newRoom->position.y = y;
    newRoom->height = height;
    newRoom->width = width;

    newRoom->doors = malloc(sizeof(Position)*4);
    
    newRoom->doors[0] = malloc(sizeof(Position));
    newRoom->doors[0]->x = rand()% (width-2) + newRoom->position.x + 1;
    newRoom->doors[0]->y = newRoom->position.y;

    newRoom->doors[1] = malloc(sizeof(Position));
    newRoom->doors[1]->x = newRoom->position.x;
    newRoom->doors[1]->y = rand()% (height-2) + newRoom->position.y+1;

    newRoom->doors[2] = malloc(sizeof(Position));
    newRoom->doors[2]->x = rand()% (width-2) + newRoom->position.x + 1;
    newRoom->doors[2]->y = newRoom->position.y + newRoom->height-1;

    newRoom->doors[3] = malloc(sizeof(Position));
    newRoom->doors[3]->x = newRoom->position.x + width-1;
    newRoom->doors[3]->y = rand()% (height-2) + newRoom->position.y + 1;

    
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