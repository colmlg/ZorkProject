#include "enemy.h"

Enemy::Enemy(int attack, int health, string name, Item* itemDrop, string imagePath) {
	this->attack = attack;
	this->health = health;
	this->maxHealth = health;
	this->name = name;
	this->itemDrop = itemDrop;
	this->imagePath = imagePath;
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

string Enemy::getImagePath() {
	return imagePath;
}
