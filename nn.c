#include <ncurses.h>
#include <stdlib.h>



typedef struct Player {
    int Xposition;
    int Yposition;
    int Health;
} Player;

typedef struct Room{
    int xPosition, yPosition, height, width;
    //Monster** monsters;
    //Item ** items
}Room;

int screenSetUp();
Room** mapSetUp();
int handleInput(int input, Player* user);
int playerMove(int y, int x, Player* user);
int checkPosition(int newY,int newX, Player* user);
Player* playerSetup();
Room* createRoom(int x, int y, int height, int width);
int drawRoom(Room *room);

int main() {
    Player* user;
    char ch;

    screenSetUp();
    mapSetUp();
    user = playerSetup();

    while ((ch = getch()) != 'q') {
        handleInput(ch, user);
    }
    endwin();

    return 0;
}

int screenSetUp() {
    initscr();
    noecho();
    curs_set(0);
    refresh();

    return 1;
}

Room** mapSetUp() {
    
    Room** rooms;
    rooms = malloc(sizeof(Room)*6);


    
    rooms[0] = createRoom(13, 13, 8, 12);
    drawRoom(rooms[0]);
    rooms[1] = createRoom(22, 31,8, 12 );
    drawRoom(rooms[1]);

    return rooms;
}

Room * createRoom(int x, int y, int height, int width){

    Room* newRoom = malloc(sizeof(Room));
    newRoom->xPosition = x;
    newRoom->yPosition = y;
    newRoom->height = height;
    newRoom->width = width;

}

int drawRoom(Room *room){
    int y, x;

    for(x = room->xPosition; x < room->xPosition+room->width; x++){
        mvprintw(room->yPosition, x, "-");
        mvprintw(room->yPosition+room->height-1, x, "-");
    }

    for(y = room->yPosition + 1; y < room->yPosition+room->height-1;y++){
        mvprintw(y, room->xPosition, "|");
        mvprintw(y, room->xPosition+room->width-1, "|");
        for(x = room->xPosition+1;x < room->xPosition + room->width-1; x++){
            mvprintw(y, x, ".");
        }
    }
    return 1;
}

Player* playerSetup() {
    Player* newPlayer = malloc(sizeof(Player));
    
    newPlayer->Xposition = 14;
    newPlayer->Yposition = 14;
    newPlayer->Health = 20;

    playerMove(newPlayer->Yposition, newPlayer->Xposition, newPlayer);
    refresh();

    return newPlayer;
}

int handleInput(int input, Player* user) {
    int newY, newX;
    switch (input) {
        case 'w':
            newY = user->Yposition -1; newX = user->Xposition;
            break;
        case 'a':
            newY = user->Yposition; newX = user->Xposition-1;
            break;
        case 's':
            newY = user->Yposition +1; newX = user->Xposition;
            break;
        case 'd':
            newY = user->Yposition ; newX = user->Xposition+1;
            break;
        default:
            break;
    }

    checkPosition(newY, newX, user);        
    return 0;
}

int checkPosition(int newY,int newX, Player* user){
    int space;
    switch(mvinch(newY, newX)){
        case '.':
            playerMove(newY, newX, user);
        default:
            move(user->Yposition, user->Xposition);
            break;
    }

}

int playerMove(int y, int x, Player* user) {
        mvprintw(user->Yposition, user->Xposition, ".");
        user->Yposition = y;
        user->Xposition = x;
        mvprintw(user->Yposition, user->Xposition, "H");
        move(user->Yposition, user->Xposition);
        refresh();
    return 0;
}

