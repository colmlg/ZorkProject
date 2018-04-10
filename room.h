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
	string shortDescription;
	string longDescription;
	Enemy* enemy;

public:
	Room(string shortDescription, string longDescription);
	~Room();
    int numberOfItems();
	string getShortDescription();
	string getLongDescription();
	Inventory* inventory;
    void setEnemy(Enemy* enemy);
	bool hasEnemy();
	Enemy* getEnemy();
};

#endif
