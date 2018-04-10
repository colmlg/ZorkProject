#ifndef ENEMY_H
#define ENEMY_H
#include "entity.h"
#include <string>
#include <item.h>
using std::string;

class Enemy: public Entity {
private:
	string name;
	int maxHealth;
	Item* itemDrop;
	string imagePath;

public:
	Enemy(int attack, int health, string name, Item* itemDrop, string imagePath);
	string getName();
	double getCurrentHealthPercentage();
	Item* getItem();
	string getImagePath();
};

#endif // ENEMY_H
