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
    void goRoom(Command command);
    void createItems();
    void displayItems();
    void printCurrentRoomInfo();
    void printMap();
    void teleport();
    void printInventory();
    void moveItem(string itemName, Inventory* fromInventory, Inventory* toInventory);
public:
    ZorkUL();
    void play();
    string go(string direction);
};

#endif /*ZORKUL_H_*/
