#include "Player.h"

Player::Player() {
	health = 100;
	attack = 5;
}

int Player::dealDamage() { return 1; }

void Player::setWeapon(Weapon* weapon) {
	this->weapon = weapon;
}

Weapon* Player::getWeapon() {
	return weapon;
}
