#ifndef WEAPON_H
#define WEAPON_H
#include "item.h"
class Weapon: public Item {
private:
	int damageMultiplier;
public:
    Weapon(ItemType itemType);
	int getDamageMuliplier();
    virtual bool isWeapon();
};

#endif // WEAPON_H
