#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Inventory.h"
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Parser parser;
    Character *character;
    Room *currentRoom;
    Room *rooms[10];
    void createRooms();
    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void createItems();
    void displayItems();
    void moveItem(string itemName, Inventory* fromInventory, Inventory* toInventory);
public:
    ZorkUL();
    void play();
    string getCurrentRoomInfo();
    //MARK: Game commands
    void teleport();
    string go(string direction);
    Inventory* getCharacterInventory();
    Inventory* getCurrentRoomInventory();
    void takeItem(string itemName);
    void placeItem(string itemName);
};

#endif /*ZORKUL_H_*/
