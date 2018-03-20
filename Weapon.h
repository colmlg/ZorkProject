#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

enum WeaponType {
	metal, magic, fire
};

class Weapon: public Item {
private:
	int damageMultiplier;
	WeaponType weaponType;
public:
	Weapon(int damageMultiplier, WeaponType weaponType);
    Weapon(ItemType itemType);
	int getDamageMuliplier();
	WeaponType getWeaponType();
    virtual bool isWeapon();
};

#endif // WEAPON_H
