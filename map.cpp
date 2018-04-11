#include "map.h"

GameMap::GameMap(Room*** rooms) {
	this->rooms = rooms;
}

GameMap::~GameMap() {
	for(int i = 0; i < GameMap::numRows; i++) {
		for(int j = 0; j < GameMap::numCols; j++) {
				delete rooms[i][j];
		}
		delete rooms[i];
	}
	delete rooms;
}

void GameMap::go(Direction direction) {
	int newCol = currentPosition.col;
	int newRow = currentPosition.row;

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

	previousPosition = currentPosition;
	currentPosition = MapPosition(newRow, newCol);

	moveCounter++;
}

void GameMap::goToPreviousRoom() {
	MapPosition temp = currentPosition;
	currentPosition = previousPosition;
	previousPosition = temp;
	moveCounter++;
}

Room* GameMap::getCurrentRoom() {
	return rooms[currentPosition.row][currentPosition.col];
}

bool GameMap::useTeleportItem() {
	if(currentPosition == roomWithAGap) {
		previousPosition = currentPosition;
		currentPosition.col += 2; //Jump across the gap
		return true;
	}
	return false; //Not in the correct room
}

int GameMap::getMoveCount() {
	return moveCounter;
}

string GameMap::getExitString() {
	string exitString = "";
	int northExit = currentPosition.row - 1;
	int southExit = currentPosition.row + 1;
	int westExit = currentPosition.col - 1;
	int eastExit = currentPosition.col + 1;

	if(northExit > 0 && northExit < numRows && rooms[northExit][currentPosition.col] != NULL) {
		exitString += "To the north lies a " + rooms[northExit][currentPosition.col]->getShortDescription() + ".\n";
	}
	if(eastExit > 0 && eastExit < numCols && rooms[currentPosition.row][eastExit] != NULL) {
		exitString += "To the east lies a " + rooms[currentPosition.row][eastExit]->getShortDescription() + ".\n";
	}
	if(southExit > 0 && southExit < numRows && rooms[southExit][currentPosition.col] != NULL) {
		exitString += "To the south lies a " + rooms[southExit][currentPosition.col]->getShortDescription() + ".\n";
	}
	if(westExit > 0 && westExit < numCols && rooms[currentPosition.row][westExit] != NULL) {
		exitString += "To the west lies a " + rooms[currentPosition.row][westExit]->getShortDescription() + ".\n";
	}
	return exitString;
}

bool GameMap::inWinRoom() {
	return currentPosition == winRoom;
}
