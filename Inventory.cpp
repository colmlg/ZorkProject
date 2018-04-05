#include "Inventory.h"
using std::string;

void Inventory::addItem(Item* item) {
    items.push_back(item);
}

Item* Inventory::takeSelectedItem() {
    for (unsigned int i = 0; i < items.size(); i++) {
        Item* item = items[i];
		if (item->isSelected()) {
            items.erase(items.begin() + i);
            return item;
        }
    }
    
    return NULL;
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
