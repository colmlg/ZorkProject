#ifndef PLAYER_H_
#define PLAYER_H_
#include "inventory.h"
#include "entity.h"
#include "weapon.h"

class Player: public Entity {
private:
	Inventory inventory;
    Weapon* weapon = NULL;

public:
	Player();
	~Player();
	void setWeapon(Weapon* weapon);
	Weapon* takeWeapon();
	Weapon* getWeapon();
    int getAttack();
	Inventory& getInventory();
};

#endif /*PLAYER_H_*/
