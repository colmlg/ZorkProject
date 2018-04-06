#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <string>
#include <Item.h>
using std::string;

class Enemy: public Entity {
private:
	string name;
	int maxHealth;
	Item* itemDrop;
public:
	Enemy(int attack, int health, string name, Item* itemDrop);
	string getName();
	double getCurrentHealthPercentage();
	Item* getItem();
};

#endif // ENEMY_H
