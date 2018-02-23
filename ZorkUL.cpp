#include <iostream>
#include "ZorkUL.h"
#include <cstdlib>
using namespace std;

ZorkUL::ZorkUL() {
    createRooms();
    character = new Character();
}

void ZorkUL::createRooms() {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
	Item* bookItem = new Item(book);
	bookItem->action = [this]{ teleport(); };

	Item* berryItem = new Item(berry);
	berryItem->action = [this]{ character->heal(10); };

	Item* poisonBerry = new Item(berry);
	poisonBerry->actionDescription = "Ouch! The delicious looking berry turned out to be poisonous! You have been dealt 50 damage.";
	poisonBerry->action = [this]{ character->dealDamage(50); };

	Item* swordItem = new Item(sword);

	a = new Room("a");
	a->inventory->addItem(bookItem);
	a->inventory->addItem(berryItem);
	a->inventory->addItem(swordItem);
	a->inventory->addItem(poisonBerry);

    b = new Room("b");
	b->inventory->addItem(swordItem);
	b->inventory->addItem(bookItem);

    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");

    //             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, j, NULL);
    j->setExits(i, NULL, NULL, NULL);

    currentRoom = a;

    rooms[0] = a;
    rooms[1] = b;
    rooms[2] = c;
    rooms[3] = d;
    rooms[4] = e;
    rooms[5] = f;
    rooms[6] = g;
    rooms[7] = h;
    rooms[8] = i;
    rooms[9] = j;
}

Inventory* ZorkUL::getCharacterInventory() {
    return character->inventory;
}

Inventory* ZorkUL::getCurrentRoomInventory() {
    return currentRoom->inventory;
}

void ZorkUL::moveItem(string itemName, Inventory* fromInventory, Inventory* toInventory) {
    Item* item = fromInventory->takeItem(itemName);
    
    if (item == NULL) {
        return;
    }
    item->isSelected = false;
    toInventory->addItem(item);
}

void ZorkUL::takeItem(string itemName) {
    moveItem(itemName, currentRoom->inventory, character->inventory);
}

void ZorkUL::placeItem(string itemName) {
    moveItem(itemName, character->inventory, currentRoom->inventory);
}

void ZorkUL::teleport() {
    int roomNumber = rand() % 10;
    currentRoom = rooms[roomNumber];
}

string ZorkUL::getCurrentRoomInfo() {
    return currentRoom->longDescription();
}

string ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return ("direction null");
    else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

Character* ZorkUL::getCharacter() {
	return character;
}
