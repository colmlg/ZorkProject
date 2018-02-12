#include "Room.h"
#include "Command.h"

Room::Room(string description) {
    this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}

string Room::shortDescription() {
    return description;
}

string Room::longDescription() {
    return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first; // access the "first" element of the pair (direction as a string)
    return returnString;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
    // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item* inItem) {
    itemsInRoom.push_back(inItem);
}

string Room::displayItem() {
    string listOfItems = "Items in room = ";
    int numberOfItems = itemsInRoom.size();
    if (numberOfItems < 1) {
        listOfItems = "No items in room";
    } else {
        for (int i = 0; i < numberOfItems; i++) {
            listOfItems = listOfItems + itemsInRoom[i]->getShortDescription() + "  ";
        }
    }
    return listOfItems;
}

Item* Room::takeItem(string itemName) {
    for (int i = 0; i < itemsInRoom.size(); i++) {
        bool itemIsInRoom = itemName == itemsInRoom[i]->getShortDescription();
        if (itemIsInRoom) {
            Item* item = itemsInRoom[i];
            itemsInRoom.erase(itemsInRoom.begin() + i);
            return item;
        }
    }

    return NULL; //Item is not in room
}
