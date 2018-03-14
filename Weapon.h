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
	int getDamageMuliplier();
	WeaponType getWeaponType();

};

#endif // WEAPON_H
