#include "room.h"

Room::Room(string shortDescription, string longDescription) {
	this->shortDescription = shortDescription;
	this->longDescription = longDescription;

	inventory = new Inventory();
	enemy = NULL;
}

Room::~Room() {
	delete inventory;
	delete enemy;
}

string Room::getShortDescription() {
	return shortDescription;
}

string Room::getLongDescription() {
	return longDescription;
}

void Room::setEnemy(Enemy* enemy) {
    this->enemy = enemy;
}

bool Room::hasEnemy() {
	return enemy != NULL;
}

Enemy* Room::getEnemy() {
	return enemy;
}
