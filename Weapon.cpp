#include "Weapon.h"

Weapon::Weapon(int damageMultiplier, WeaponType weaponType) {
	this->damageMultiplier = damageMultiplier;
	this->weaponType = weaponType;
}

Weapon::Weapon(ItemType itemType)
: Item(itemType) {
    switch(itemType) {
    case sword:
        weaponType = metal;
        damageMultiplier = 2;
    default:
        damageMultiplier = 1;
    }
}

bool Weapon::isWeapon() {
    return true;
}
