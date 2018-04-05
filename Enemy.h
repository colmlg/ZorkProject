#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <string>
using std::string;

class Enemy: public Entity {
private:
	string name;
	int maxHealth;
public:
	Enemy(int attack, int health, string name);
	string getName();
	int getCurrentHealthPercentage();
};

#endif // ENEMY_H
