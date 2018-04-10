#include "room.h"

Room::Room(string description) {
    this->description = description;
}

Room::~Room() {
	delete inventory;
	delete enemy;
}

string Room::shortDescription() {
    return description;
}

string Room::longDescription() {
	return "room = " + description + ".\n";
}

void Room::setEnemy(Enemy* enemy) {
    this->enemy = enemy;
}
