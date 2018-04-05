#include <iostream>
#include "ZorkUL.h"
#include "Constants.h"
#include <cstdlib>
using namespace std;

ZorkUL::ZorkUL() {
    createRooms();
	player = new Player();
}

void ZorkUL::createRooms() {
	Item* bookItem = new Item(book);
	bookItem->action = [this]{ teleport(); };

	Item* berryItem = new Item(berry);
	berryItem->action = [this]{ player->heal(Constants::berryHealAmount); };

	Item* poisonBerryItem = new Item(poisonBerry);
	poisonBerryItem->action = [this]{ player->takeDamage(Constants::poisonBerryDamage); };

    Weapon* swordItem = new Weapon(sword);

    rooms["a"] = new Room("a");
    rooms["a"]->inventory->addItem(bookItem);
    rooms["a"]->inventory->addItem(berryItem);
    rooms["a"]->inventory->addItem(swordItem);
    rooms["a"]->inventory->addItem(poisonBerryItem);

    rooms["b"] = new Room("b");
    rooms["b"]->inventory->addItem(swordItem);
    rooms["b"]->inventory->addItem(bookItem);

    Enemy* someMonster = new Enemy(10, 50);
    rooms["b"]->setEnemy(someMonster);

    rooms["c"] = new Room("c");
    rooms["d"] = new Room("d");
    rooms["e"] = new Room("e");
    rooms["f"] = new Room("f");
    rooms["g"] = new Room("g");
    rooms["h"] = new Room("h");
    rooms["i"] = new Room("i");
    rooms["j"] = new Room("j");

    //             (N, E, S, W)
    rooms["a"]->setExits(rooms["f"], rooms["b"], rooms["d"], rooms["c"]);
    rooms["b"]->setExits(NULL, NULL, NULL, rooms["a"]);
    rooms["c"]->setExits(NULL, rooms["a"], NULL, NULL);
    rooms["d"]->setExits(rooms["a"], rooms["e"], NULL, rooms["i"]);
    rooms["e"]->setExits(NULL, NULL, NULL, rooms["d"]);
    rooms["f"]->setExits(NULL, rooms["g"], rooms["a"], rooms["h"]);
    rooms["g"]->setExits(NULL, NULL, NULL, rooms["f"]);
    rooms["h"]->setExits(NULL, rooms["f"], NULL, NULL);
    rooms["i"]->setExits(NULL, rooms["d"], rooms["j"], NULL);
    rooms["j"]->setExits(rooms["i"], NULL, NULL, NULL);

    currentRoom = rooms["a"];
}

Inventory* ZorkUL::getPlayerInventory() {
	return player->inventory;
}

Inventory* ZorkUL::getCurrentRoomInventory() {
    return currentRoom->inventory;
}

void ZorkUL::moveSelectedItem(Inventory* fromInventory, Inventory* toInventory) {
	Item* item = fromInventory->takeSelectedItem();
    
    if (item == NULL) {
        return;
    }
	item->setSelected(false);
    toInventory->addItem(item);
}

void ZorkUL::takeSelectedItem() {
	moveSelectedItem(currentRoom->inventory, player->inventory);
}

void ZorkUL::placeSelectedItem() {
	moveSelectedItem(player->inventory, currentRoom->inventory);
}

void ZorkUL::teleport() {
    auto iterator = rooms.begin();
    std::advance(iterator, rand() % rooms.size());
    currentRoom = iterator->second;
}

string ZorkUL::getCurrentRoomInfo() {
    return currentRoom->longDescription();
}

Room* ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);
    currentRoom = nextRoom;
    return currentRoom;
}

Player* ZorkUL::getPlayer() {
	return player;
}
