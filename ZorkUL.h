#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Room.h"
#include "Inventory.h"
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Character *character;
    Room *currentRoom;
    Room *rooms[10];
    void createRooms();
    void createItems();
    void moveItem(string itemName, Inventory* fromInventory, Inventory* toInventory);
public:
    ZorkUL();
    string getCurrentRoomInfo();
    //MARK: Game commands
    void teleport();
    string go(string direction);
    Inventory* getCharacterInventory();
    Inventory* getCurrentRoomInventory();
    Room* getCurrentRoom();
    void takeItem(string itemName);
    void placeItem(string itemName);
	Character* getCharacter();
};

#endif /*ZORKUL_H_*/
