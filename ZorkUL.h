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
    Player *player;
    Room *currentRoom;
    map<string, Room*> rooms;
    void createRooms();
    void createItems();
	void moveSelectedItem(Inventory* fromInventory, Inventory* toInventory);
public:
    ZorkUL();
    string getCurrentRoomInfo();
    //MARK: Game commands
    void teleport();
    Room* go(string direction);
    Inventory* getPlayerInventory();
    Inventory* getCurrentRoomInventory();
    Room* getCurrentRoom();
	void takeSelectedItem();
	void placeSelectedItem();
	Player* getPlayer();
};

#endif /*ZORKUL_H_*/
