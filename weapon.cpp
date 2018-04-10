#include "weapon.h"

Weapon::Weapon(ItemType itemType)
: Item(itemType) {
    switch(itemType) {
    case sword:
		damageMultiplier = 2;
        break;
    default:
        damageMultiplier = 1;
    }
}

bool Weapon::isWeapon() {
    return true;
}

int Weapon::getDamageMuliplier() {
    return damageMultiplier;
}
