#include "entity.h"

Entity::~Entity() {}

int Entity::getHealth() {
	return health;
}

void Entity::heal(int amount) {
	health += amount;
	if (health > 100) {
		health = 100;
	}
}

void Entity::takeDamage(int amount) {
	health -= amount;
	if (health < 0) {
		health = 0;
	}
}
