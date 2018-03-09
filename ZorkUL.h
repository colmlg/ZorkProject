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
    Room *rooms[10];
    void createRooms();
    void createItems();
	void moveSelectedItem(Inventory* fromInventory, Inventory* toInventory);
public:
    ZorkUL();
    string getCurrentRoomInfo();
    //MARK: Game commands
    void teleport();
    string go(string direction);
    Inventory* getCharacterInventory();
    Inventory* getCurrentRoomInventory();
    Room* getCurrentRoom();
	void takeSelectedItem();
	void placeSelectedItem();
	Player* getCharacter();
};

#endif /*ZORKUL_H_*/
