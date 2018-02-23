#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "Inventory.h"
#include <vector>

class Character {
private:
	int health = 95;
	int damage = 5;
public:
    Inventory* inventory = new Inventory();
	int getHealth();
	void dealDamage(int amount);
	void heal(int amount);
};

#endif /*CHARACTER_H_*/
