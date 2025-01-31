#include <menu.h>
#include <stdlib.h>
#include "mainMenu.h"


void closeMenu(int numberItems, MENU* menu, ITEM** items){
    
    unpost_menu(menu);
    free_menu(menu);
    for(int i = 0; i < numberItems; i++){
        free_item(items[i]);
    }
}



int mainMenu(int numberItems, char* choices[]){

    int i, c, value;
    MENU* menu;
    ITEM** items = malloc(sizeof(ITEM*) * numberItems+1);
    ITEM* current;

    for(i = 0; i < numberItems; i++){

        items[i] = new_item(choices[i], "");
    }
    items[i] = (ITEM*)NULL;

    menu = new_menu((ITEM**)items);
    post_menu(menu);
    refresh;

    //menu Loop

    while(1){
        c = getch();

        switch(c){

            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;          
            case 10:
                current = current_item(menu);
                value = item_index(current);
                closeMenu(numberItems, menu, items);
                return value;
        }
    }
}