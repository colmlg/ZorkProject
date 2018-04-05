#include "Enemy.h"

Enemy::Enemy(int attack, int health, string name) {
	this->attack = attack;
	this->health = health;
	this->maxHealth = health;
	this->name = name;
}

string Enemy::getName() {
	return name;
}

int Enemy::getCurrentHealthPercentage() {
	return health / maxHealth;
}
