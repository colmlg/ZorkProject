#ifndef MAP_H
#define MAP_H
#include "room.h"
#include "direction.h"
#include "mapposition.h"

class GameMap {
private:
	//Important Rooms
	const MapPosition roomWithAGap = MapPosition(2,5);
	const MapPosition winRoom = MapPosition(2,9);

	MapPosition currentPosition = MapPosition(2,0);
	MapPosition previousPosition = currentPosition;
	Room*** rooms;
	void createRooms();
	int moveCounter = 0;
public:
	const static int numCols = 10;
	const static int numRows = 6;
	GameMap(Room*** rooms);
	~GameMap();
	void go(Direction direction);
	void goToPreviousRoom();
	Room* getCurrentRoom();
	bool useTeleportItem();
	int getMoveCount();
	string getExitString();
	bool inWinRoom();
};
#endif // MAP_H
