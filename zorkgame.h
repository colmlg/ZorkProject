#ifndef ZORKUL_H_
#define ZORKUL_H_
#include <iostream>
#include <string>
#include "room.h"
#include "inventory.h"
#include "player.h"
#include "map.h"

using namespace std;

class ZorkGame {
private:
	Player* player;
	GameMap* map;
	void moveSelectedItem(Inventory& fromInventory, Inventory& toInventory);
	int getRandom(int min, int max);
	Room*** createRooms();

public:
	ZorkGame();
	~ZorkGame();
	//MARK: Getters & setters
	string getCurrentRoomInfo();
    Room* getCurrentRoom();
	Player* getPlayer();
	bool hasPlayerWon();
	bool hasPlayerLost();
	int getScore();
	//MARK: Game commands
	void go(Direction direction);
	void takeSelectedItem();
	void placeSelectedItem();
	//MARK: Battle Commands
	string attackEnemy();
	string runFromEnemy();
	string hideFromEnemy();
	string playDead();
};

#endif /*ZORKUL_H_*/
