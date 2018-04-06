#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Room.h"
#include "Inventory.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
	Player* player;
	Room* currentRoom;
	Room* previousRoom;
    map<string, Room*> rooms;
    void createRooms();
    void createItems();
	void moveSelectedItem(Inventory* fromInventory, Inventory* toInventory);
	bool playerWon = false;
	int getRandom(int min, int max);
public:
	ZorkUL();
	~ZorkUL();
    string getCurrentRoomInfo();
    void teleport();
	void go(string direction);
    Inventory* getPlayerInventory();
    Inventory* getCurrentRoomInventory();
    Room* getCurrentRoom();
	void takeSelectedItem();
	void placeSelectedItem();
	Player* getPlayer();
	string attackEnemy();
	string runFromEnemy();
	string hideFromEnemy();
	string playDead();
	bool hasPlayerWon();
	bool hasPlayerLost();
};

#endif /*ZORKUL_H_*/
