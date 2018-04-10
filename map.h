#ifndef MAP_H
#define MAP_H
#include "room.h"
#include "direction.h"

class Map {
private:
	int row = 2;
	int col = 0;
	int previousRow;
	int previousCol;
	Room*** rooms;
	void createRooms();
	int moveCounter = 0;
public:
	const static int numCols = 10;
	const static int numRows = 6;
	Map(Room*** rooms);
	~Map();
	void go(Direction direction);
	void goToPreviousRoom();
	Room* getCurrentRoom();
	bool useTeleportItem();
	int getRow();
	int getCol();
	int getMoveCount();
	string getExitString();
};
#endif // MAP_H
