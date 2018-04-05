#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "Inventory.h"
#include "Enemy.h"

using namespace std;
using std::vector;

class Room {
private:
    string description;
    map<string, Room*> exits;
    string exitString();
    Enemy* enemy = NULL;


public:
    int numberOfItems();
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    Inventory* inventory = new Inventory();
    void setEnemy(Enemy* enemy);
    bool hasEnemy() {
        return enemy != NULL;
    }

    static const int itemSlots = 4;
};

#endif
