#include "player.h"

Player::Player() {
	health = 100;
	attack = 5;
}

Player::~Player() {
	delete weapon;
}

void Player::setWeapon(Weapon* weapon) {
	this->weapon = weapon;
}

Weapon* Player::getWeapon() {
	return weapon;
}

Weapon* Player::takeWeapon() {
    Weapon *returnWeapon = weapon;
    weapon = NULL;
    return returnWeapon;
}

int Player::getAttack(){
    return weapon == NULL ? attack : attack * weapon->getDamageMuliplier();
}

Inventory& Player::getInventory() {
	return inventory;
}

