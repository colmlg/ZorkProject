#include <iostream>
#include "zorkgame.h"
#include "constants.h"
#include <cstdlib>
#include "direction.h"
using namespace std;

ZorkGame::ZorkGame() {
	map = new Map(createRooms());
	player = new Player();
}

Room*** ZorkGame::createRooms() {
	//Reserve space for the array
	Room*** rooms = new Room**[Map::numRows];
	for(int i = 0; i < Map::numRows; i++) {
		rooms[i] = new Room*[Map::numCols];
	}
	//NULL out the space for the rooms
	for(int i = 0; i < Map::numRows; i++) {
		for(int j = 0; j < Map::numCols; j++) {
			rooms[i][j] = NULL;
		}
	}

	Item* crystalBall = new Item(teleportBall);
	crystalBall->action = [this]{
		return map->useTeleportItem();
	};

	Item* berryItem = new Item(berry);
	berryItem->action = [this]{
		player->heal(Constants::berryHealAmount);
		return true;
	};

	Item* poisonBerryItem = new Item(poisonBerry);
	poisonBerryItem->action = [this]{
		player->takeDamage(Constants::poisonBerryDamage);
		return true;
	};

	Weapon* swordItem = new Weapon(sword);
	Enemy* littleBadWolf = new Enemy(5, 20, "little bad wolf", berryItem, ":/images/enemies/wolf_forest.png");
	Enemy* badWolf = new Enemy(10, 30, "bad wolf", berryItem, ":/images/enemies/wolf_forest.png");
	Enemy* bigBadWolf = new Enemy(15, 50, "big bad wolf", berryItem, ":/images/enemies/wolf_forest.png");

	rooms[2][0] = new Room("Start Room");
	rooms[2][1] = new Room("Second Room.");
	rooms[1][1] = new Room("Sword Room");
	rooms[1][1]->inventory->addItem(swordItem);
	rooms[1][3] = new Room("Berry Room");
	rooms[1][3]->inventory->addItem(poisonBerryItem);
	rooms[2][2] = new Room("Easy Wolf Room");
//	rooms[2][2]->setEnemy(littleBadWolf);
	rooms[2][3] = new Room("Battle finished room");
	rooms[1][3] = new Room("Passageway");
	rooms[0][3] = new Room("Book Room");
	rooms[0][3]->inventory->addItem(crystalBall);
	rooms[3][3] = new Room("Passageway");
	rooms[4][3] = new Room("Passageway");
	rooms[5][3] = new Room("Berry Room");
	rooms[5][3]->inventory->addItem(berryItem);
	rooms[2][4] = new Room("Normal Wolf Room");
//	rooms[2][4]->setEnemy(badWolf);
	rooms[2][5] = new Room("Room with a gap");
	rooms[2][7] = new Room("After gap");
	rooms[1][7] = new Room("Dead end");
	rooms[3][7] = new Room("Passageway");
	rooms[4][7] = new Room("Poison berry");
	rooms[4][7]->inventory->addItem(poisonBerryItem);
	rooms[2][8] = new Room("Final Boss");
//	rooms[2][8]->setEnemy(bigBadWolf);
	rooms[2][9] = new Room("Win room!");
	return rooms;
}

ZorkGame::~ZorkGame() {
	delete player;
}

Inventory* ZorkGame::getPlayerInventory() {
	return player->inventory;
}

Inventory* ZorkGame::getCurrentRoomInventory() {
	return map->getCurrentRoom()->inventory;
}

void ZorkGame::moveSelectedItem(Inventory* fromInventory, Inventory* toInventory) {
	Item* item = fromInventory->takeSelectedItem();
    
    if (item == NULL) {
        return;
    }
	item->setSelected(false);
    toInventory->addItem(item);
}

void ZorkGame::takeSelectedItem() {
	moveSelectedItem(map->getCurrentRoom()->inventory, player->inventory);
}

void ZorkGame::placeSelectedItem() {
	moveSelectedItem(player->inventory, map->getCurrentRoom()->inventory);
}

string ZorkGame::getCurrentRoomInfo() {
	return map->getCurrentRoom()->longDescription() + "\n" + map->getExitString();
}

void ZorkGame::go(Direction direction) {
	map->go(direction);
}

Player* ZorkGame::getPlayer() {
	return player;
}

Room* ZorkGame::getCurrentRoom() {
	return map->getCurrentRoom();
}

string ZorkGame::attackEnemy() {
	string logString = "";
	int playerHitChance = getRandom(0, 100);
	int enemyHitChance = getRandom(0, 100);
	Enemy* enemy = map->getCurrentRoom()->getEnemy();

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
		map->getCurrentRoom()->inventory->addItem(enemy->getItem());
		map->getCurrentRoom()->setEnemy(NULL);
		delete enemy;
	}
	return logString;
}

string ZorkGame::runFromEnemy() {
	int escapeChance = getRandom(0, 100);

	if(escapeChance <= 80) {
		map->goToPreviousRoom();
		return "You managed to escape, and ran to the previous room.";
	} else {
		Enemy* enemy = map->getCurrentRoom()->getEnemy();
		player->takeDamage(enemy->getAttack());
		return "You tried to escape but the " + enemy->getName() + " lands a blow and knocks you to the floor. You have been dealt " + to_string(enemy->getAttack()) + " damage.";
	}
}

string ZorkGame::hideFromEnemy() {
	int healChance = getRandom(0, 100);

	if(healChance <= 75) {
		player->heal(10);
		return "You hide and catch your breath for a minute. You have been healed for 10 points.";
	} else {
		Enemy* enemy = map->getCurrentRoom()->getEnemy();
		player->takeDamage(enemy->getAttack());
		return "You tried to hide but the " + enemy->getName() + " finds you. You have been dealt " + to_string(enemy->getAttack()) + " damage.";
	}
}

string ZorkGame::playDead() {
	int fleeChance = getRandom(0, 100);
	Enemy* enemy = map->getCurrentRoom()->getEnemy();

	if(fleeChance <= 15) {
		map->getCurrentRoom()->setEnemy(NULL);
		delete enemy;
		return "Surprisingly the enemy falls for your trick and presumes you dead. It moves on in search other opponents.";
	} else {
		int attackDamage = (int)(enemy->getAttack() * 1.5);
		player->takeDamage(attackDamage);
		return "Well that didn't work! The " + enemy->getName() + " lands a cheap shot. You have been dealt  " + to_string(attackDamage) + " damage.";
	}
}

int ZorkGame::getRandom(int min, int max) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max);
	return distr(eng);
}

bool ZorkGame::hasPlayerLost() {
	return player->getHealth() == 0;
}

bool ZorkGame::hasPlayerWon() {
	return map->getCol() == 9 && map->getRow() == 2;
}

int ZorkGame::getScore() {
	return (player->getHealth() * 10) + (player->getAttack() * 10) - (map->getMoveCount() * 5);
}
