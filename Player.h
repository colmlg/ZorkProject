#ifndef PLAYER_H_
#define PLAYER_H_
#include "Inventory.h"
#include "Entity.h"
#include "Weapon.h"

class Player: public Entity {
private:
	Weapon* weapon;

public:
	Player();
    Inventory* inventory = new Inventory();
	int dealDamage();
	void setWeapon(Weapon* weapon);
	Weapon* takeWeapon();
	Weapon* getWeapon();

};

#endif /*PLAYER_H_*/
