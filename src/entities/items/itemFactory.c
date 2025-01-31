#include "rogue.h"
#include "item.h"
#include "weapon.h"

Item* createMace(int attack, int health){

    Item* item = malloc(sizeof(Item));
    item->type = WEAPON_TYPE;
    strcpy(item->string, "Mace");

    Weapon* weapon = malloc(sizeof(Weapon));
    weapon->attack = attack;
    weapon->health = health;

    item->item.weapon = weapon;

    return item;
}