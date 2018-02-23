#include "Character.h"

void Character::heal(int amount) {
	health += amount;
	if (health > 100) {
		health = 100;
	}
}

int Character::getHealth() {
	return health;
}

void Character::dealDamage(int amount) {
	health -= amount;
	if (health < 0) {
		health = 0;
	}
}
