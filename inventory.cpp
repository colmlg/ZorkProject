#include "inventory.h"
using std::string;

Inventory::~Inventory() {
	for(Item* item : items) {
		delete item;
	}
}

void Inventory::addItem(Item* item) {
	items.push_back(item);
}

void Inventory::selectItem(int index) {
    deselectItems();
	items[index]->setSelected(true);
}

void Inventory::deselectItems() {
    for (Item* item : items) {
		item->setSelected(false);
    }
}

int Inventory::getNumberOfItems() {
    return items.size();
}

std::vector<Item*> Inventory::getItems() {
    return items;
}

void Inventory::removeItem(int index) {
    items.erase(items.begin() + index);
}
