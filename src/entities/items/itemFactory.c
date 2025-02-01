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

Item* createDagger(int attack, int health){

    Item* item = malloc(sizeof(Item));
    item->type = WEAPON_TYPE;
    strcpy(item->string, "Dagger");

    Weapon* weapon = malloc(sizeof(Weapon));
    weapon->attack = attack;
    weapon->health = health;
    weapon->symbol = 'D';

    item->item.weapon = weapon;

    return item;
}

Item* createMagicWand(int attack, int health){

    Item* item = malloc(sizeof(Item));
    item->type = WEAPON_TYPE;
    strcpy(item->string, "Magic Wand");

    Weapon* weapon = malloc(sizeof(Weapon));
    weapon->attack = attack;
    weapon->health = health;
    weapon->symbol = 'M';

    item->item.weapon = weapon;

    return item;
}

Item* createNoramalArrow(int attack, int health){

    Item* item = malloc(sizeof(Item));
    item->type = WEAPON_TYPE;
    strcpy(item->string, "Normal Arrow");

    Weapon* weapon = malloc(sizeof(Weapon));
    weapon->attack = attack;
    weapon->health = health;
    weapon->symbol = 'N';

    item->item.weapon = weapon;

    return item;
}

Item* createSword(int attack, int health){

    Item* item = malloc(sizeof(Item));
    item->type = WEAPON_TYPE;
    strcpy(item->string, "Sword");

    Weapon* weapon = malloc(sizeof(Weapon));
    weapon->attack = attack;
    weapon->health = health;
    weapon->symbol = 'S';

    item->item.weapon = weapon;

    return item;
}
