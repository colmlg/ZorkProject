#ifndef PLAYER_H_
#define PLAYER_H_
#include "Inventory.h"
#include "Entity.h"
#include "Weapon.h"

class Player: public Entity {
private:
    Weapon* weapon = NULL;

public:
	Player();
	~Player();
	Inventory* inventory = new Inventory();
	void setWeapon(Weapon* weapon);
	Weapon* takeWeapon();
	Weapon* getWeapon();
    int getAttack();
};

#endif /*PLAYER_H_*/
