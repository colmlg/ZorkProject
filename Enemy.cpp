#include "Enemy.h"

Enemy::Enemy(int attack, int health, string name, Item* itemDrop) {
	this->attack = attack;
	this->health = health;
	this->maxHealth = health;
	this->name = name;
	this->itemDrop = itemDrop;
}

string Enemy::getName() {
	return name;
}

double Enemy::getCurrentHealthPercentage() {
	return ((double) health / (double) maxHealth) * 100.0;
}

Item* Enemy::getItem() {
	return itemDrop;
}
