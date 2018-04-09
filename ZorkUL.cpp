#include <iostream>
#include "ZorkUL.h"
#include "Constants.h"
#include <cstdlib>
using namespace std;

ZorkUL::ZorkUL() {
    createRooms();
	player = new Player();
}

ZorkUL::~ZorkUL() {
	delete player;
	for (auto const& key : rooms) {
		delete key.second;
	}
}

void ZorkUL::createRooms() {
	Item* bookItem = new Item(book);
	bookItem->action = [this]{ teleport(); };

	Item* berryItem = new Item(berry);
	berryItem->action = [this]{ player->heal(Constants::berryHealAmount); };

	Item* poisonBerryItem = new Item(poisonBerry);
	poisonBerryItem->action = [this]{ player->takeDamage(Constants::poisonBerryDamage); };

    Weapon* swordItem = new Weapon(sword);

    rooms["a"] = new Room("a");
    rooms["a"]->inventory->addItem(bookItem);
    rooms["a"]->inventory->addItem(swordItem);
    rooms["a"]->inventory->addItem(poisonBerryItem);

	Enemy* badWolf = new Enemy(30, 30, "big bad wolf", berryItem, ":/images/enemies/wolf_forest.png");
    rooms["b"] = new Room("b");
	rooms["b"]->setEnemy(badWolf);

    rooms["c"] = new Room("c");
    rooms["d"] = new Room("d");
    rooms["e"] = new Room("e");
    rooms["f"] = new Room("f");
    rooms["g"] = new Room("g");
    rooms["h"] = new Room("h");
    rooms["i"] = new Room("i");
    rooms["j"] = new Room("j");

    //             (N, E, S, W)
    rooms["a"]->setExits(rooms["f"], rooms["b"], rooms["d"], rooms["c"]);
    rooms["b"]->setExits(NULL, NULL, NULL, rooms["a"]);
	rooms["c"]->setExits(NULL, rooms["a"], NULL, NULL);
    rooms["d"]->setExits(rooms["a"], rooms["e"], NULL, rooms["i"]);
    rooms["e"]->setExits(NULL, NULL, NULL, rooms["d"]);
    rooms["f"]->setExits(NULL, rooms["g"], rooms["a"], rooms["h"]);
    rooms["g"]->setExits(NULL, NULL, NULL, rooms["f"]);
    rooms["h"]->setExits(NULL, rooms["f"], NULL, NULL);
    rooms["i"]->setExits(NULL, rooms["d"], rooms["j"], NULL);
    rooms["j"]->setExits(rooms["i"], NULL, NULL, NULL);

    currentRoom = rooms["a"];
}

Inventory* ZorkUL::getPlayerInventory() {
	return player->inventory;
}

Inventory* ZorkUL::getCurrentRoomInventory() {
    return currentRoom->inventory;
}

void ZorkUL::moveSelectedItem(Inventory* fromInventory, Inventory* toInventory) {
	Item* item = fromInventory->takeSelectedItem();
    
    if (item == NULL) {
        return;
    }
	item->setSelected(false);
    toInventory->addItem(item);
}

void ZorkUL::takeSelectedItem() {
	moveSelectedItem(currentRoom->inventory, player->inventory);
}

void ZorkUL::placeSelectedItem() {
	moveSelectedItem(player->inventory, currentRoom->inventory);
}

void ZorkUL::teleport() {
    auto iterator = rooms.begin();
    std::advance(iterator, rand() % rooms.size());
    currentRoom = iterator->second;
}

string ZorkUL::getCurrentRoomInfo() {
    return currentRoom->longDescription();
}

void ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL) {
		return;
	}
	previousRoom = currentRoom;
    currentRoom = nextRoom;
}

Player* ZorkUL::getPlayer() {
	return player;
}

Room* ZorkUL::getCurrentRoom() {
	return currentRoom;
}

string ZorkUL::attackEnemy() {
	string logString = "";
	int playerHitChance = getRandom(0, 100);
	int enemyHitChance = getRandom(0, 100);
	Enemy* enemy = currentRoom->getEnemy();

	if (playerHitChance <= 80) { //80% chance
		enemy->takeDamage(player->getAttack());
		string weaponName = player->getWeapon() == NULL ? "fist" : player->getWeapon()->getShortDescription();
		logString += "You deal a swift blow to the enemy with your " + weaponName + ", dealing " + to_string(player->getAttack()) + " damage.";
	} else {
		logString += "Your attack misses the enemy, dealing no damage.";
	}

	if (enemyHitChance <= 50) { //50% chance
		player->takeDamage(enemy->getAttack());
		logString += "\nThe " + enemy->getName() + " lands a hit on you, dealing " + to_string(enemy->getAttack()) + " damage.";
	} else {
		logString += "\nThe " + enemy->getName() + " tries to attack but narrowly misses.";
	}

	if (enemy->getHealth() == 0) {
		logString += "\nYour final blow defeats the " + enemy->getName() + ", it drops something on the ground as it dies...";
		currentRoom->inventory->addItem(enemy->getItem());
		currentRoom->setEnemy(NULL);
		delete enemy;
	}
	return logString;
}

string ZorkUL::runFromEnemy() {
	int escapeChance = getRandom(0, 100);

	if(escapeChance <= 80) {
		currentRoom = previousRoom;
		return "You managed to escape, and ran to the previous room.";
	} else {
		Enemy* enemy = currentRoom->getEnemy();
		player->takeDamage(enemy->getAttack());
		return "You tried to escape but the " + enemy->getName() + " lands a blow and knocks you to the floor. You have been dealt " + to_string(enemy->getAttack()) + " damage.";
	}
}

string ZorkUL::hideFromEnemy() {
	int healChance = getRandom(0, 100);

	if(healChance <= 75) {
		player->heal(10);
		return "You hide and catch your breath for a minute. You have been healed for 10 points.";
	} else {
		Enemy* enemy = currentRoom->getEnemy();
		player->takeDamage(enemy->getAttack());
		return "You tried to hide but the " + enemy->getName() + " finds you. You have been dealt " + to_string(enemy->getAttack()) + " damage.";
	}
}

string ZorkUL::playDead() {
	int fleeChance = getRandom(0, 100);
	Enemy* enemy = currentRoom->getEnemy();

	if(fleeChance <= 15) {
		currentRoom->setEnemy(NULL);
		delete enemy;
		return "Surprisingly the enemy falls for your trick and presumes you dead. It moves on in search other opponents.";
	} else {
		int attackDamage = (int)(enemy->getAttack() * 1.5);
		player->takeDamage(attackDamage);
		return "Well that didn't work! The " + enemy->getName() + " lands a cheap shot. You have been dealt  " + to_string(attackDamage) + " damage.";
	}
}



int ZorkUL::getRandom(int min, int max) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max);
	return distr(eng);
}

bool ZorkUL::hasPlayerLost() {
	return player->getHealth() == 0;
}

bool ZorkUL::hasPlayerWon() {
	return playerWon;
}
