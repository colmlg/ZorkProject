#include "map.h"

Map::Map(Room*** rooms) {
	this->rooms = rooms;
}

Map::~Map() {
	for(int i = 0; i < Map::numRows; i++) {
		for(int j = 0; j < Map::numCols; j++) {
				delete rooms[i][j];
		}
		delete rooms[i];
	}
	delete rooms;
}

void Map::go(Direction direction) {
	int newCol = col;
	int newRow = row;

	switch(direction) {
		case north:
		newRow--;
		break;
		case south:
		newRow++;
		break;
		case east:
		newCol++;
		break;
		case west:
		newCol--;
		break;
	}

	//Bounds checking for the array
	if(newCol < 0 || newRow < 0 || newCol > numCols - 1 || newRow > numRows - 1) {
		return;
	}

	if(rooms[newRow][newCol] == NULL) {
		return;
	}

	previousRow = row;
	previousCol = col;
	row = newRow;
	col = newCol;

	moveCounter++;
}

void Map::goToPreviousRoom() {
	int temp = previousRow;
	previousRow = row;
	row = temp;

	temp = previousCol;
	previousCol = col;
	col = temp;

}

Room* Map::getCurrentRoom() {
	return rooms[row][col];
}

bool Map::useTeleportItem() {
	if(row == 2 && col == 5) {
		previousRow = row;
		previousCol = col;
		col+= 2; //Jump across the gap
		return true;
	}
	return false; //Not in the correct room
}

int Map::getRow() {
	return row;
}

int Map::getCol() {
	return col;
}

int Map::getMoveCount() {
	return moveCounter;
}

string Map::getExitString() {
	string exitString = "";
	int northExit = row - 1;
	int southExit = row + 1;
	int westExit = col - 1;
	int eastExit = col + 1;

	if(northExit > 0 && northExit < numRows && rooms[northExit][col] != NULL) {
		exitString += "To the north lies a " + rooms[northExit][col]->getShortDescription() + ".\n";
	}
	if(eastExit > 0 && eastExit < numCols && rooms[row][eastExit] != NULL) {
		exitString += "To the east lies a " + rooms[row][eastExit]->getShortDescription() + ".\n";
	}
	if(southExit > 0 && southExit < numRows && rooms[southExit][col] != NULL) {
		exitString += "To the south lies a " + rooms[southExit][col]->getShortDescription() + ".\n";
	}
	if(westExit > 0 && westExit < numCols && rooms[row][westExit] != NULL) {
		exitString += "To the west lies a " + rooms[row][westExit]->getShortDescription() + ".\n";
	}
	return exitString;
}
