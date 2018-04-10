#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "inventory.h"
#include "enemy.h"

using namespace std;
using std::vector;

class Room {
private:
    string description;
	Enemy* enemy = NULL;

public:
	~Room();
    int numberOfItems();
    Room(string description);
    string shortDescription();
    string longDescription();
    Inventory* inventory = new Inventory();
    void setEnemy(Enemy* enemy);
    bool hasEnemy() {
        return enemy != NULL;
    }

	Enemy* getEnemy() {
		return enemy;
	}
};

#endif
