#include <iostream>
#include "zorkgame.h"
#include "constants.h"
#include <cstdlib>
#include "direction.h"
using namespace std;

ZorkGame::ZorkGame() {
	map = new GameMap(createRooms());
	player = new Player();
}

ZorkGame::~ZorkGame() {
	delete map;
	delete player;
}

Room*** ZorkGame::createRooms() {
	//Reserve space for the array
	Room*** rooms = new Room**[GameMap::numRows];
	for(int i = 0; i < GameMap::numRows; i++) {
		rooms[i] = new Room*[GameMap::numCols];
	}
	//NULL out the space for the rooms
	for(int i = 0; i < GameMap::numRows; i++) {
		for(int j = 0; j < GameMap::numCols; j++) {
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

	Item* treasureItem = new Item(treasure);
	Weapon* swordItem = new Weapon(sword);
	Weapon* fireballItem = new Weapon(fireball);

	Enemy* littleBadWolf = new Enemy(5, 20, "little bad wolf", berryItem, ":/images/enemies/wolf_forest.png");
	Enemy* badWolf = new Enemy(10, 30, "bad wolf", fireballItem, ":/images/enemies/wolf_forest.png");
	Enemy* caveMonster = new Enemy(15, 50, "cave monster", treasureItem, ":/images/enemies/monster_cave.png");

	rooms[2][0] = new Room("small room", "You see before you a small enclosed room. There is not much here.");
	rooms[2][1] = new Room("crossroads", "You enter a large open space. Passages lead in every direction.");
	rooms[1][1] = new Room("something shiny", "You enter an ornately decorated room. On top of a plinth lies a sword.");
	rooms[1][1]->getInventory().addItem(swordItem);
	rooms[1][3] = new Room("damp room", "As you enter a dark dank room a putrid smell fills your nostrils. Something is growing on the walls.");
	rooms[1][3]->getInventory().addItem(poisonBerryItem);
	rooms[2][2] = new Room("wolf's den", "You enter into a wolf's den. There are animal carcasses scattered across the room.");
	rooms[2][2]->setEnemy(littleBadWolf);
	rooms[2][3] = new Room("crossroads", "You enter a large open space. Passages lead in every direction.");
	rooms[1][3] = new Room("passageway", "You enter a narrow passageway, there is barely room to breathe.");
	rooms[0][3] = new Room("a mysterious glow", "As you enter this room you feel an ancient energy. Something special lies here.");
	rooms[0][3]->getInventory().addItem(crystalBall);
	rooms[3][3] = new Room("passageway", "You enter a narrow passageway, there is barely room to breathe.");
	rooms[4][3] = new Room("passageway", "You enter a narrow passageway, there is barely room to breathe.");
	rooms[5][3] = new Room("beautiful garden", "A sweet smell of berries fills the room. Many beautiful plants decorate the walls.");
	rooms[5][3]->getInventory().addItem(berryItem);
	rooms[2][4] = new Room("wolf's den", "You enter into a wolf's den. There are animal carcasses scattered across the room.");
	rooms[2][4]->setEnemy(badWolf);
	rooms[2][5] = new Room("gaping chasm", "A gaping chasm stretches before you. On the opposite side you can see a door, but it seems impossible to reach.");
	rooms[2][7] = new Room("gaping chasm", "You are on the other side of the chasm. To return seems impossible.");
	rooms[1][7] = new Room("dark cave", "There doesn't seem to be much here.");
	rooms[3][7] = new Room("passageway", "You enter a narrow passageway, there is barely room to breathe.");
	rooms[4][7] = new Room("purple garden", "A garden full of purple plants lies before you. They look delicous.");
	rooms[4][7]->getInventory().addItem(poisonBerryItem);
	rooms[2][8] = new Room("dark cave", "You enter a dark damp cave. A horrifying monster appears before you.");
	rooms[2][8]->setEnemy(caveMonster);
	rooms[2][9] = new Room("fresh air", "A beautiful vista stretches out before you, and you feel a fresh breeze on your face. You are free.");
	return rooms;
}

void ZorkGame::moveSelectedItem(Inventory& fromInventory, Inventory& toInventory) {
	for (unsigned int i = 0; i < fromInventory.items.size(); i++) {
		if (fromInventory.items[i]->isSelected()) {
			fromInventory.items.erase(fromInventory.items.begin() + i);
			toInventory.items.push_back(fromInventory.items[i]);
		}
	}
}

void ZorkGame::takeSelectedItem() {
	moveSelectedItem(map->getCurrentRoom()->getInventory(), player->getInventory());
}

void ZorkGame::placeSelectedItem() {
	moveSelectedItem(player->getInventory(), map->getCurrentRoom()->getInventory());
}

string ZorkGame::getCurrentRoomInfo() {
	return map->getCurrentRoom()->getLongDescription() + "\n\n" + map->getExitString();
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
		map->getCurrentRoom()->getInventory().addItem(enemy->getItem());
		delete enemy;
		map->getCurrentRoom()->setEnemy(NULL);
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
		delete enemy;
		map->getCurrentRoom()->setEnemy(NULL);
		return "Surprisingly the enemy falls for your trick and presumes you dead. It moves on in search other opponents.";
	} else {
		int attackDamage = (int)(enemy->getAttack() * 1.5);
		player->takeDamage(attackDamage);
		return "Well that didn't work! The " + enemy->getName() + " lands a cheap shot. You have been dealt  " + to_string(attackDamage) + " damage.";
	}
}

inline int ZorkGame::getRandom(int min, int max) {
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(min, max);
	return distr(eng);
}

bool ZorkGame::hasPlayerLost() {
	return player->getHealth() == 0;
}

bool ZorkGame::hasPlayerWon() {
	return map->inWinRoom();
}

int ZorkGame::getScore() {
	return (player->getHealth() * 10) + (player->getAttack() * 10) - (map->getMoveCount() * 5);
}
